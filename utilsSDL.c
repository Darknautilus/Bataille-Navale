// Permet la portabilité du programme
#ifdef __APPLE__

#include <SDL/SDL.h>
#include <SDL_ttf/SDL_ttf.h>

#else

#include <SDL.h>
#include <SDL_ttf.h>

#endif

#include "utilsSDL.h"

SDL_Surface * DemarrerSDL(int width, int height, char * titreFenetre)
{
    SDL_Surface * ecran;// Pour voir
    
    TTF_Init();// Pour écrire
    SDL_Init(SDL_INIT_VIDEO);// Pour voir des images
    
    ecran = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);// Pour voir mieux
    SDL_WM_SetCaption(titreFenetre, NULL);// Pour savoir de quoi on parle
    
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);// Pour les flemmards

    return ecran;
}

int ClicSurRetour(SDL_Rect * positionClic)
{
    if(positionClic->x >= KABSRETOUR - 5 && positionClic->x <= KABSRETOUR + 100 &&
       positionClic->y >= KORDRETOUR - 10)
        return 1;
    else
        return 0;
}

void ArreterSDL(void)
{
    SDL_Quit();// On ne voit plus
    TTF_Quit();// On n'écrit plus
}