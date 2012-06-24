/**
 * \file SDLImage.h
 * \author Aurélien Bertron
 * \date 29 mai 2012
 * \brief Module d'image SDL
 *
 * Contient les déclarations du module Image SDL
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
	int ordonnee; /**< Ordonnée de l'image */
	int longueur; /**< Longueur de l'image */
	int hauteur; /**< Hauteur de l'image */
	SDL_Surface * zoneImage; /**< Surface de stockage de l'image */
}Image;

/**
 * Crée une structure Image.
 * \param pChemin Le chemin de l'image ‡ l'intÈrieur du dossier image
 * \param pAbscisse Un entier contenant l'abscisse o˘ placer l'image
 * \param pOrdonnee Un entier contenant l'ordonnÈe o˘ placer l'image
 * \return Une strucutre Image correctement crÈer.
*/
Image * creerImage(char * pChemin, int pAbscisse, int pOrdonnee);

/**
 * Affiche une image
 * \param[in] pImage Une image
 */
void afficherImage(Image * pImage);

/**
 * Détermine si un clic est sur l'image ou non
 * \param[in] pImage Une image
 * \param[in] pPosClic La position du clic
 * \return 1 si le clic est sur l'image et 0 sinon
 */
int clicSurImage(Image * pImage, SDL_Rect * pPosClic);

/**
 * Libère l'image en mémoire
 * \param[in] pImage Une image
 */
void libererImage(Image * pImage);

/**
 * Cette fonction charge une image du dossier Image dans une structure SDL_Surface
 * \param pChemin Le chemin de l'image ‡ l'intÈrieur du dossier image
 * \return Une strucutre SDL_Surface correctement crÈe.
*/
SDL_Surface SDLCALL* creerSDLImage(char chemin[]);

#endif
