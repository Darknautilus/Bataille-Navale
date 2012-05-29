#include "SDLImage.h"

#include "includeSDL.h"

Image * CreerImage(char * pChemin, int pAbscisse, int pOrdonnee)
{
	Image * nouvImage = (Image*)malloc(sizeof(Image));
	
	nouvImage->zoneImage = IMG_Load(pChemin);
	nouvImage->longueur = nouvImage->zoneImage->w;
	nouvImage->hauteur = nouvImage->zoneImage->h;
	nouvImage->abscisse = pAbscisse;
	nouvImage->ordonnee = pOrdonnee;
	
	return nouvImage;
}

void AfficherImage(Image * pImage)
{
	SDL_Rect positionImage;
	
	positionImage.x = pImage->abscisse;
	positionImage.y = pImage->ordonnee;
	
	SDL_BlitSurface(pImage->zoneImage, NULL, SDL_GetVideoSurface(), &positionImage);
}

int ClicSurImage(Image * pImage, SDL_Rect * pPosClic)
{
	if(pPosClic->x >= pImage->abscisse && pPosClic->x <= pImage->abscisse + pImage->longueur &&
	   pPosClic->y >= pImage->ordonnee && pPosClic->y <= pImage->ordonnee + pImage->hauteur)
		return 1;
	else
		return 0;
}

void LibererImage(Image * pImage)
{
	SDL_FreeSurface(pImage->zoneImage);
	free(pImage);
}