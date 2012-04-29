#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>

#include "menu.h"
#include "champSaisie.h"
#include "utilsSDL.h"

void AfficherMenuAccueil(SDL_Surface * ecran)
{
    SDL_Surface *fond;
    SDL_Rect positionFond;
    SDL_Event event;
    int continuer = 1;
    
    positionFond.x = 0;
    positionFond.y = 0;
    
    while(continuer)
    {
        fond = IMG_Load("Images/menuAccueil.png");
        SDL_BlitSurface(fond, NULL, ecran, &positionFond);
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
    SDL_Surface *fond, *puceMenu;
    SDL_Rect positionFond, positionPuce;
    SDL_Event event;
    int continuer = 1;
    int choixMenu = 1;
    
    positionFond.x = 0;
    positionFond.y = 0;
    positionPuce.x = 80;
    positionPuce.y = 150;
    
    while(continuer)
    {
        fond = IMG_Load("Images/menuRacine.png");
        SDL_BlitSurface(fond, NULL, ecran, &positionFond);
        
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
    
    SDL_FreeSurface(fond);
    SDL_FreeSurface(puceMenu);
    
    return choixMenu;
}

void MenuNouvellePartie(void)
{
    ChampSaisie * champ;
    SDL_Rect positionClic;
    SDL_Event * event;
    int continuer = 1;
    
    champ = CreerChamp(50, 30, 100, 100);
    champ = InitTexte(champ, "Salut");
    
    EffacerEcran();
    
    while (continuer)
    {
        AfficherChamp(champ, SDL_GetVideoSurface());
        SDL_Flip(SDL_GetVideoSurface());
        AttendreClic(&positionClic);
        if(ClicSurChamp(champ, &positionClic))
        {
            champ = ChangeFocus(champ, 1);
            EditerChamp(champ);
        }
        else
        {
            champ = ChangeFocus(champ, 0);
        }
    }
    

    LibererChamp(champ);
}