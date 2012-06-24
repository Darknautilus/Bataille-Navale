/**
 * \file SDLRectangle.h
 * \author Aurélien Bertron
 * \date 7 juin 2012
 * \brief Module de rectangle SDL
 *
 * Contient les déclarations du module Rectangle SDL
 */

#ifndef SDL_RECTANGLE_H
#define SDL_RECTANGLE_H

#include "../view/IncludeSDL.h"

/**
 * \struct Rectangle
 * \brief Outil de dessin de rectangle
*/
typedef struct
{
    int abscisse; /**< Abscisse du rectangle */
    int ordonnee; /**< Ordonnée du rectangle */
    int largeur; /**< Largeur du rectangle */
    int hauteur; /**< Hauteur du rectangle */
    int couleur; /**< Indice de la couleur (voir table des couleurs) */
    SDL_Surface * zoneRectangle; /**< Surface de stockage du rectangle */
}Rectangle;

/**
 * Crée un rectangle de couleur blanche
 * \param[in] pAbs Abscisse du rectangle
 * \param[in] pOrd Ordonnée du rectangle
 * \param[in] pLarg Largeur du rectangle
 * \param[in] pHaut Hauteur du rectangle
 * \return Un rectangle initialisé
*/
Rectangle * creerRectangle(int pAbs, int pOrd, int pLarg, int pHaut);

/**
 * Afficher le rectangle
 * \param[in] pRect Un rectangle
*/
void afficherRectangle(Rectangle * pRect);

/**
 * Détermine si un clic est sur le rectangle ou non
 * \param[in] pRect Un rectangle
 * \param[in] pPosClic La position du clic
 * \return 1 si le clic est sur le rectangle et 0 sinon
 */
int clicSurRectangle(Rectangle * pRect, SDL_Rect * pPosClic);

/**
 * Incrémente la couleur du rectangle (voir table des couleurs)
 * \param[in] pRect Un rectangle
*/
void incrCouleurRectangle(Rectangle * pRect);

/**
 * Libère le rectangle en mémoire
 * \param[in] pRect Un rectangle
*/
void libererRectangle(Rectangle * pRect);

#endif //SDL_RECTANGLE_H
