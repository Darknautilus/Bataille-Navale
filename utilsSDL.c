#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>

#include "utilsSDL.h"

SDL_Surface * DemarrerSDL(int width, int height, char * titreFenetre)
{
    SDL_Surface * ecran;
    
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    
    ecran = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption(titreFenetre, NULL);
    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    
    return ecran;
}

void ArreterSDL()
{
    SDL_Quit();
    TTF_Quit();
}