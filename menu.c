#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>

#include "menu.h"
#include "champSaisie.h"
#include "utilsSDL.h"

void AfficherMenuAccueil(SDL_Surface * ecran)
{
    SDL_Event event;
    int continuer = 1;
    
    while(continuer)
    {
        ImageFond("Images/menuAccueil.png");
        SDL_Flip(ecran);
        
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                exit(EXIT_FAILURE);
                break;
                
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
            {
                case SDLK_SPACE:
                    continuer = 0;
                    break;
                    
                case SDLK_ESCAPE:
                    exit(EXIT_FAILURE);
                    break;
            }
                break;
        }
    }
}

int AfficherMenuRacine(SDL_Surface * ecran)
{
    SDL_Surface *puceMenu;
    SDL_Rect positionPuce;
    SDL_Event event;
    int continuer = 1;
    int choixMenu = 1;
    
    positionPuce.x = 80;
    positionPuce.y = 150;
    
    while(continuer)
    {
        ImageFond("Images/menuRacine.png");
        
        puceMenu = IMG_Load("Images/puceMenu.png");
        SDL_BlitSurface(puceMenu, NULL, ecran, &positionPuce);
        
        SDL_Flip(ecran);
        
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                exit(EXIT_FAILURE);
            break;
                
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
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
                    exit(EXIT_FAILURE);
                break;
            }
            break;
        }
    }
    
    SDL_FreeSurface(puceMenu);
    
    return choixMenu;
}

void MenuNouvellePartie(void)
{
    ChampSaisie * champPseudoHumain, * champPseudoIA;
    SDL_Rect positionClic;
    SDL_Event * event;
    int continuer = 1;
    
    champPseudoHumain = CreerChamp(30, 30, 230, 150);
    champPseudoIA = CreerChamp(30, 30, 230, 200);
    
    ImageFond("Images/menuNouvellePartie.png");
    
    while (continuer)
    {
        AfficherChamp(champPseudoHumain, SDL_GetVideoSurface());
        AfficherChamp(champPseudoIA, SDL_GetVideoSurface());
        SDL_Flip(SDL_GetVideoSurface());
        AttendreClic(&positionClic);
        if(ClicSurChamp(champPseudoHumain, &positionClic))
        {
            champPseudoHumain = ChangeFocus(champPseudoHumain, 1);
            EditerChamp(champPseudoHumain);
        }
        else if(ClicSurChamp(champPseudoIA, &positionClic))
        {
            champPseudoIA = ChangeFocus(champPseudoIA, 1);
            EditerChamp(champPseudoIA);
        }
    }
    

    LibererChamp(champPseudoHumain);
    LibererChamp(champPseudoIA);
}