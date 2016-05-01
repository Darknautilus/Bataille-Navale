#include "view/SDLImage.h"

#include "ctrl/UtilsSDL.h"
#include "ctrl/FichierDebug.h"
#include "view/IncludeSDL.h"

#include <stdlib.h>

Image * creerImage(char * pChemin, int pAbscisse, int pOrdonnee)
{
    char * mesErreur;
	Image * nouvImage = malloc(sizeof(Image));

    //On alloue une variable pouvant contenir le chemin vers le dossier image + celui de l'image
	char * chemin = malloc(sizeof(IMG_REP) + sizeof(char)*strlen(pChemin) + sizeof(char));

	strcpy(chemin, IMG_REP);
	strcat(chemin, pChemin);

	nouvImage->zoneImage = IMG_Load(chemin);

    if(nouvImage->zoneImage == NULL){
        mesErreur = malloc((strlen(chemin) + 30)*sizeof(char));
        strcpy(mesErreur, chemin);
        strcat(mesErreur, " : Impossible de charger une image");
        dgFatal(mesErreur);
        free(mesErreur);
        exit(EXIT_FAILURE);
    }

	nouvImage->longueur = nouvImage->zoneImage->w;
	nouvImage->hauteur = nouvImage->zoneImage->h;
	nouvImage->abscisse = pAbscisse;
	nouvImage->ordonnee = pOrdonnee;

	return nouvImage;
}

void afficherImage(Image * pImage)
{
	SDL_Rect positionImage;

	positionImage.x = pImage->abscisse;
	positionImage.y = pImage->ordonnee;

	SDL_BlitSurface(pImage->zoneImage, NULL, GetMainScreen(), &positionImage);
}

int clicSurImage(Image * pImage, SDL_Rect * pPosClic)
{
	if(pPosClic->x >= pImage->abscisse && pPosClic->x <= pImage->abscisse + pImage->longueur &&
	   pPosClic->y >= pImage->ordonnee && pPosClic->y <= pImage->ordonnee + pImage->hauteur)
		return 1;
	else
		return 0;
}

void libererImage(Image * pImage)
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
