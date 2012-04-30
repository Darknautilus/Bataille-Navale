#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>

#include "menu.h"
#include "champSaisie.h"
#include "utilsSDL.h"

void AfficherMenuAccueil(void)
{
    int continuer = 1;
    
    SDLKey * touche = (SDLKey*)malloc(sizeof(SDLKey));
    
    ImageFond("Images/menuAccueil.png");
    SDL_Flip(SDL_GetVideoSurface());
    
    while(continuer)
    {
        AttendreEvent(NULL, touche);
        switch(*touche)
        {
            case SDLK_SPACE:
                continuer = 0;
            break;
                    
            case SDLK_ESCAPE:
                exit(EXIT_FAILURE);
            break;
        }
    }
    
    free(touche);
}

int AfficherMenuRacine(void)
{
    SDL_Surface *puceMenu;
    SDL_Rect positionPuce;
    SDL_Event event;
    int continuer = 1;
    int choixMenu = 1;
    
    SDLKey * touche = (SDLKey*)malloc(sizeof(SDLKey));
    
    positionPuce.x = 80;
    positionPuce.y = 150;
    
    while(continuer)
    {
        ImageFond("Images/menuRacine.png");
        
        puceMenu = IMG_Load("Images/puceMenu.png");
        SDL_BlitSurface(puceMenu, NULL, SDL_GetVideoSurface(), &positionPuce);
        
        SDL_Flip(SDL_GetVideoSurface());
        
        AttendreEvent(NULL, touche);
        switch(*touche)
        {
            case SDLK_RETURN:
                continuer = 0;
            break;
                    
            case SDLK_UP:
                if(choixMenu != 1)
                {
                    choixMenu --;
                    positionPuce.y -= 60;
                }
            break;
                
            case SDLK_DOWN:
                if(choixMenu != 5)
                {
                    choixMenu ++;
                    positionPuce.y += 60;
                }
            break;
                
            case SDLK_ESCAPE:
                exit(EXIT_SUCCESS);
            break;
        }
    }
    
    free(touche);
    SDL_FreeSurface(puceMenu);
    
    return choixMenu;
}

void MenuNouvellePartie(void)
{
    ChampSaisie * champPseudoHumain, * champPseudoIA;
    int continuer = 1;
    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    SDLKey * touche = (SDLKey*)malloc(sizeof(SDLKey));
    int controleEvent;
    
    champPseudoHumain = CreerChamp(30, 30, 230, 150);
    champPseudoIA = CreerChamp(30, 30, 230, 200);
    
    ImageFond("Images/menuNouvellePartie.png");
    ImageRetour("Images/flecheRetour.png");
    
    while (continuer)
    {
        AfficherChamp(champPseudoHumain, SDL_GetVideoSurface());
        AfficherChamp(champPseudoIA, SDL_GetVideoSurface());
        SDL_Flip(SDL_GetVideoSurface());
        controleEvent = AttendreEvent(positionClic, touche);
        if(controleEvent == 1)
        {
            if(ClicSurChamp(champPseudoHumain, positionClic))
            {
                ChangeFocus(champPseudoHumain, CHAMP_ACTIF);
                EditerChamp(champPseudoHumain);
            }
            else if(ClicSurChamp(champPseudoIA, positionClic))
            {
                ChangeFocus(champPseudoIA, CHAMP_ACTIF);
                EditerChamp(champPseudoIA);
            }
            else if(ClicSurRetour(positionClic))
            {
                continuer = 0;
            }
        }
        else if(controleEvent == 2)
        {
            if(*touche == SDLK_ESCAPE)
                continuer = 0;
        }
    }
    
    free(positionClic);
    free(touche);
    LibererChamp(champPseudoHumain);
    LibererChamp(champPseudoIA);
}