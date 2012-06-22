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

/**
 * Cr�er une structure Image.
 * \param pChemin Le chemin de l'image � l'int�rieur du dossier image
 * \param pAbscisse Un entier contenant l'abscisse o� placer l'image
 * \param pOrdonnee Un entier contenant l'ordonn�e o� placer l'image
 * \return Une strucutre Image correctement cr�er.
*/
Image * CreerImage(char * pChemin, int pAbscisse, int pOrdonnee);

void afficherImage(Image * pImage);

int clicSurImage(Image * pImage, SDL_Rect * pPosClic);

void LibererImage(Image * pImage);

/**
 * Cette fonction charge une image du dossier Image dans une structure SDL_Surface
 * \param pChemin Le chemin de l'image � l'int�rieur du dossier image
 * \return Une strucutre SDL_Surface correctement cr�e.
*/
SDL_Surface SDLCALL* creerSDLImage(char chemin[]);

#endif
