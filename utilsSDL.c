#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>

#include "utilsSDL.h"
#include "menu.h"

SDL_Surface * DemarrerSDL(int width, int height, char * titreFenetre)
{
    SDL_Surface * ecran;
    
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    
    ecran = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption(titreFenetre, NULL);
    
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
        
    EffacerEcran();
    
    return ecran;
}

void ImageFond(char * cheminImage)
{
    SDL_Surface * imageFond;
    SDL_Rect positionFond;
    
    positionFond.x = 0;
    positionFond.y = 0;
    
    imageFond = IMG_Load(cheminImage);
    SDL_BlitSurface(imageFond, NULL, SDL_GetVideoSurface(), &positionFond);
}

void EffacerEcran(void)
{
    SDL_FillRect(SDL_GetVideoSurface(), NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, 0, 0, 0));
}

void ArreterSDL(void)
{
    SDL_Quit();
    TTF_Quit();
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

void AttendreClic(SDL_Rect * coordClic)
{
    SDL_Event event;
    int continuer = 1;
    
    while (continuer)
    {
        SDL_WaitEvent(&event);
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                coordClic->x = event.button.x;
                coordClic->y = event.button.y;
                continuer = 0;
            }
        }
        else if(event.type == SDL_QUIT)
            exit(EXIT_FAILURE);
    }
}