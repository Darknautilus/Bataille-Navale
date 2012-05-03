// Permet la portabilité du programme
#ifdef _WIN32

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#else

#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>

#endif

#include "menu.h"

#include "champSaisie.h"
#include "vueChampSaisie.h"

#include "utilsSDL.h"
#include "vueUtilsSDL.h"

#include "test.h"

void AfficherMenuAccueil(void)
{
    int continuer = 1;
    
    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
    
    ImageFond("Images/menuAccueil.png");
    SDL_Flip(SDL_GetVideoSurface());
    
    while(continuer)
    {
        AttendreEvent(NULL, touche);
        switch(ToucheSpec(touche))
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
    SDL_Rect positionPuce;
    int continuer = 1;
    int choixMenu = 1;
    
    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
    
    SDL_EnableUNICODE(SDL_ENABLE);
    
    positionPuce.x = 80;
    positionPuce.y = 150;
    
    while(continuer)
    {
        ImageFond("Images/menuRacine.png");
        
        AfficherImage("Images/puceMenu.png", positionPuce);
        
        SDL_Flip(SDL_GetVideoSurface());
        
        AttendreEvent(NULL, touche);
        switch(ToucheSpec(touche))
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
        
        if(ToucheChar(touche) == 't')
            MenuTest();
    }
    
    SDL_EnableUNICODE(SDL_DISABLE);
    
    free(touche);
    
    return choixMenu;
}

void MenuNouvellePartie(void)
{
    ChampSaisie * champPseudoHumain, * champPseudoIA;
    int continuer = 1;
    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
    int controleEvent;
    
    champPseudoHumain = CreerChamp(30, 30, 230, 150);
    champPseudoIA = CreerChamp(30, 30, 230, 200);
    
    InitTexte(champPseudoHumain, "Anonyme");
    InitTexte(champPseudoIA, "GlaDos");
    
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
            if(ToucheSpec(touche) == SDLK_ESCAPE)
                continuer = 0;
        }
    }
    
    free(positionClic);
    free(touche);
    LibererChamp(champPseudoHumain);
    LibererChamp(champPseudoIA);
}