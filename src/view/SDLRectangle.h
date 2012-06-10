#ifndef SDL_RECTANGLE_H
#define SDL_RECTANGLE_H

#include "includeSDL.h"

typedef struct
{
    int abscisse;
    int ordonnee;
    int largeur;
    int hauteur;
    int couleur;
    SDL_Surface * zoneRectangle;
}Rectangle;

Rectangle * creerRectangle(int pAbs, int pOrd, int pLarg, int pHaut);

void afficherRectangle(Rectangle * pRect);

int clicSurRectangle(Rectangle * pRect, SDL_Rect * pPosClic);

void incrCouleurRectangle(Rectangle * pRect);

void libererRectangle(Rectangle * pRect);

#endif //SDL_RECTANGLE_H