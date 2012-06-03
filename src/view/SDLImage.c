#include "SDLImage.h"

#include "includeSDL.h"

#include "../ctrl/fichierDebug.h"

Image * CreerImage(char * pChemin, int pAbscisse, int pOrdonnee)
{
	Image * nouvImage = (Image*)malloc(sizeof(Image));

    //On alloue une variable pouvant contenir le chemin vers le dossier image + celui de l'image
	char * chemin = malloc(sizeof(IMG_REP) + sizeof(char)*strlen(pChemin) + sizeof(char));

	strcpy(chemin, IMG_REP);
	strcat(chemin, pChemin);

	nouvImage->zoneImage = IMG_Load(chemin);

    if(nouvImage->zoneImage == NULL){
        dgFatal("Impossible de charger une image");
    }

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

SDL_Surface SDLCALL* creerSDLImage(char chemin[]){

    char * cheminComplet = malloc (sizeof(IMG_REP) + sizeof(char)*strlen(chemin) + sizeof(char) );

    strcpy(cheminComplet, IMG_REP);
    strcat(cheminComplet, chemin);

    return IMG_Load(cheminComplet);
}