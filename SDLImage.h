#ifndef SDLIMAGE_H
#define SDLIMAGE_H

#include "includeSDL.h"

typedef struct
{
	int abscisse;
	int ordonnee;
	int longueur;
	int hauteur;
	SDL_Surface * zoneImage;
}Image;

Image * CreerImage(char * pChemin, int pAbscisse, int pOrdonnee);

void AfficherImage(Image * pImage);

int ClicSurImage(Image * pImage, SDL_Rect * pPosClic);

void LibererImage(Image * pImage);

#endif