/**
 *   \file bateau.h
 *   \author Aurelien Bertron
 *   \date 13 mai 2012
 *   \brief Module Utilitaire SDL
 *
 *   Contient les inplémentations des fonctions d'activation et de destruction de la libraire SDL
*/

#include "utilsSDL.h"

#include "../view/includeSDL.h"

SDL_Surface * DemarrerSDL(int width, int height, char * titreFenetre)
{
	SDL_Surface * ecran;// Pour voir

	SDL_Init(SDL_INIT_VIDEO);// Pour voir des images
    TTF_Init();// Pour écrire

	ecran = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);// Pour voir mieux
	SDL_WM_SetCaption(titreFenetre, NULL);// Pour savoir de quoi on parle

	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);// Pour les flemmards

	return ecran;
}

void ArreterSDL(void)
{
    TTF_Quit();// On n'écrit plus
	SDL_Quit();// On ne voit plus
}
