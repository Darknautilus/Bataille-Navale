#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>

#include "utilsSDL.h"
#include "menu.h"

void EffacerEcran(SDL_Surface * ecran)
{
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
}

SDL_Surface * DemarrerSDL(int width, int height, char * titreFenetre)
{
    SDL_Surface * ecran;
    
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    
    ecran = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption(titreFenetre, NULL);
    
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
    
    EffacerEcran(ecran);
    
    return ecran;
}

void ArreterSDL()
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
    SDL_Flip(SDL_GetVideoSurface());
    SDL_FreeSurface(zoneTexte);
}