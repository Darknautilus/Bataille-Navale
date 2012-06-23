/**
 *   \file utilsSDL.
 *   \author Aurelien Bertron
 *   \date 13 mai 2012
 *   \brief Module Utilitaire SDL
 *
 *   Les fonctions d'activation et de destruction de la libraire SDL.
*/

#ifndef UTILSSDL_H
#define UTILSSDL_H

#include "../view/includeSDL.h"

/**
 * Permet d'initialiser tous les modules SDL
 * Dans tout le code, la surface renvoyée par cette fonction peut-être retrouvée avec SDL_GetVideoSurface()
 *
 * \param[in] width Largeur de la fenêtre
 * \param[in] height Hauteur de la fenêtre
 * \return La surface de l'écran
*/
SDL_Surface * demarrerSDL(int width, int height, char * titreFenetre);

/**
 * Arrête tous les modules SDL
 * À ne pas oublier à la fin du programme
*/
void arreterSDL(void);



#endif
