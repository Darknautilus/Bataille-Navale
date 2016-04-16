#include "view/SDLRectangle.h"

#include "ctrl/UtilsSDL.h"
#include "model/Couleurs.h"
#include "view/VueUtilsSDL.h"

Rectangle * creerRectangle(int pAbs, int pOrd, int pLarg, int pHaut)
{
    Rectangle * nouvRect = (Rectangle*)malloc(sizeof(Rectangle));

    nouvRect->abscisse = pAbs;
    nouvRect->ordonnee = pOrd;
    nouvRect->largeur = pLarg;
    nouvRect->hauteur = pHaut;
    nouvRect->couleur = 0;

    nouvRect->zoneRectangle = GetNewRGBASurface(pLarg, pHaut);

    return nouvRect;
}

void afficherRectangle(Rectangle * pRect)
{
    SDL_Rect positionRectangle;

    positionRectangle.x = pRect->abscisse;
    positionRectangle.y = pRect->ordonnee;

    SDL_FillRect(pRect->zoneRectangle, NULL, convertSDL_Color(getColor(getCouleurFromNum(pRect->couleur))));

    SDL_BlitSurface(pRect->zoneRectangle, NULL, GetMainScreen(), &positionRectangle);
}

int clicSurRectangle(Rectangle * pRect, SDL_Rect * pPosClic)
{
    if(pPosClic->x >= pRect->abscisse && pPosClic->x <= pRect->abscisse + pRect->largeur &&
	   pPosClic->y >= pRect->ordonnee && pPosClic->y <= pRect->ordonnee + pRect->hauteur)
		return 1;
	else
		return 0;
}

void incrCouleurRectangle(Rectangle * pRect)
{
    if(pRect->couleur == KCOULEURS_NBCOULMAX-1)
        pRect->couleur = 0;
    else
        pRect->couleur++;
}

void libererRectangle(Rectangle * pRect)
{
    SDL_FreeSurface(pRect->zoneRectangle);
    free(pRect);
}
