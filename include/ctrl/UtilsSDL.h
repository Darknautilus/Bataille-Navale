/**
 *   \file UtilsSDL.h
 *   \author Aurélien Bertron
 *   \date 13 mai 2012
 *   \brief Contrôleur des utilitaires SDL
 *
 *   Les fonctions d'activation et de destruction de la libraire SDL.
*/

#ifndef UTILSSDL_H
#define UTILSSDL_H

#include "view/IncludeSDL.h"

typedef struct {
    Uint32 rmask;
    Uint32 gmask;
    Uint32 bmask;
    Uint32 amask;
} SDL_Surface_RGBA_Masks;

SDL_Surface *GetNewRGBASurface(int width, int height);

SDL_Surface *GetMainScreen();

SDL_Texture *GetMainTexture();

void UpdateWindow(int reset);

void ClearWindow();

/**
 * Permet d'initialiser tous les modules SDL
 *
 * \param[in] width Largeur de la fenêtre
 * \param[in] height Hauteur de la fenêtre
 * \return Le renderer de la fenêtre principale
*/
void demarrerSDL(int width, int height, char * titreFenetre);

/**
 * Arrête tous les modules SDL
 * À ne pas oublier à la fin du programme
*/
void arreterSDL(void);



#endif
