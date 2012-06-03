#include "utilsSDL.h"
#include "includeSDL.h"

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

void ArreterSDL(void)
{
	SDL_Quit();// On ne voit plus
	TTF_Quit();// On n'écrit plus
}
