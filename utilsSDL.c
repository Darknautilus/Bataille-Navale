#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>

#include "utilsSDL.h"
#include "menu.h"

SDL_Surface * DemarrerSDL(int width, int height, char * titreFenetre)
{
    SDL_Surface * ecran;// Pour voir
    
    TTF_Init();// Pour écrire
    SDL_Init(SDL_INIT_VIDEO);// Pour voir des images
    
    ecran = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);// Pour voir mieux
    SDL_WM_SetCaption(titreFenetre, NULL);// Pour savoir de quoi on parle
    
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);// Pour les flemmards
        
    EffacerEcran();// Pour partir sur de bonnes bases
    
    return ecran;
}

void ImageFond(char * cheminImage)
{
    SDL_Surface * imageFond;
    SDL_Rect positionFond;
    
    // Pour que l'image couvre tout l'écran
    positionFond.x = 0;
    positionFond.y = 0;
    
    // On charge l'image et on la colle à l'écran
    imageFond = IMG_Load(cheminImage);
    SDL_BlitSurface(imageFond, NULL, SDL_GetVideoSurface(), &positionFond);
    
    SDL_FreeSurface(imageFond);
}

void ImageRetour(char * cheminImage)
{
    SDL_Surface * imageRetour;
    SDL_Rect positionImageRetour;
    
    positionImageRetour.x = KABSRETOUR;
    positionImageRetour.y = KORDRETOUR;
    
    imageRetour = IMG_Load(cheminImage);
    SDL_BlitSurface(imageRetour, NULL, SDL_GetVideoSurface(), &positionImageRetour);
    
    EcrireTexte("RETOUR", 35, KABSRETOUR + 30, KORDRETOUR);
    
    SDL_FreeSurface(imageRetour);
}

int ClicSurRetour(SDL_Rect * positionClic)
{
    if(positionClic->x >= KABSRETOUR - 5 && positionClic->x <= KABSRETOUR + 100 &&
       positionClic->y >= KORDRETOUR - 10)
        return 1;
    else
        return 0;
}

void EcrireTexte(char * texte,int taille, int abscisse, int ordonnee)
{
    SDL_Surface * zoneTexte;
    TTF_Font * police = TTF_OpenFont("Fonts/apple.ttf", taille);
    SDL_Color couleur = {255,255,255};
    SDL_Rect position;
    
    position.x = abscisse;
    position.y = ordonnee;
    
    zoneTexte = TTF_RenderText_Blended(police, texte, couleur);
    SDL_BlitSurface(zoneTexte, NULL, SDL_GetVideoSurface(), &position);
    SDL_FreeSurface(zoneTexte);
    
    TTF_CloseFont(police);
}

int AttendreEvent(SDL_Rect * coordClic, SDLKey * touche)
{
    SDL_Event event;
    int continuer = 1;
    int controle;// Permet de retourner si l'événement est un clic ou une touche
    
    while(continuer)
    {
        // On attend que quelque chose se passe
        SDL_WaitEvent(&event);
        // Si c'est un clic gauche et qu'on a activé l'option
        if (event.type == SDL_MOUSEBUTTONDOWN && coordClic != NULL && event.button.button == SDL_BUTTON_LEFT)
        {
            coordClic->x = event.button.x;
            coordClic->y = event.button.y;
            controle = 1;
            continuer = 0;
        }
        // Si c'est une touche et qu'on a activé l'option
        else if(event.type == SDL_KEYDOWN && touche != NULL)
        {
            *touche = event.key.keysym.sym;
            controle = 2;
            continuer = 0;
        }
        // Si l'utilisateur a fait n'importe quoi
        else if(coordClic == NULL && touche == NULL)
            continuer = 0;
        
        // Si l'utilisateur veut quitter brutalement
        else if(event.type == SDL_QUIT)
            exit(EXIT_FAILURE);
    }
    
    return controle;
}

void EffacerEcran(void)
{
    SDL_FillRect(SDL_GetVideoSurface(), NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, 0, 0, 0));
}

void ArreterSDL(void)
{
    SDL_Quit();// On ne voit plus
    TTF_Quit();// On n'écrit plus
}