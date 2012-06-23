/**
 * \file SDLImage.h
 * \author Aur�lien Bertron
 * \date 29 mai 2012
 * \brief Module d'image SDL
 *
 * Contient les d�clarations du module Image SDL
 */

#ifndef SDLIMAGE_H
#define SDLIMAGE_H

#include "includeSDL.h"

/**
 * \struct Image
 * \brief Outil de dessin d'image
*/
typedef struct
{
	int abscisse; /**< Abscisse de l'image */
	int ordonnee; /**< Ordonn�e de l'image */
	int longueur; /**< Longueur de l'image */
	int hauteur; /**< Hauteur de l'image */
	SDL_Surface * zoneImage; /**< Surface de stockage de l'image */
}Image;

/**
 * Cr�e une structure Image.
 * \param pChemin Le chemin de l'image � l'int�rieur du dossier image
 * \param pAbscisse Un entier contenant l'abscisse o� placer l'image
 * \param pOrdonnee Un entier contenant l'ordonn�e o� placer l'image
 * \return Une strucutre Image correctement cr�er.
*/
Image * CreerImage(char * pChemin, int pAbscisse, int pOrdonnee);

/**
 * Affiche une image
 * \param[in] pImage Une image
 */
void afficherImage(Image * pImage);

/**
 * D�termine si un clic est sur l'image ou non
 * \param[in] pImage Une image
 * \param[in] pPosClic La position du clic
 * \return 1 si le clic est sur l'image et 0 sinon
 */
int clicSurImage(Image * pImage, SDL_Rect * pPosClic);

/**
 * Lib�re l'image en m�moire
 * \param[in] pImage Une image
 */
void LibererImage(Image * pImage);

/**
 * Cette fonction charge une image du dossier Image dans une structure SDL_Surface
 * \param pChemin Le chemin de l'image � l'int�rieur du dossier image
 * \return Une strucutre SDL_Surface correctement cr�e.
*/
SDL_Surface SDLCALL* creerSDLImage(char chemin[]);

#endif
