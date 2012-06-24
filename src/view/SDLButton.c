#include "SDLButton.h"

#include "../view/IncludeSDL.h"

#include "../ctrl/UtilsPoliceEcriture.h"

#include <string.h>

SDL_Bouton * creerBouton(char * pTexte, SDL_Rect * pCoord, int pTailleTexte)
{
	if(strlen(pTexte)>SDL_BOUTON_KLONGMAX)
		return NULL;

	SDL_Bouton * nouvBouton = (SDL_Bouton*)malloc(sizeof(SDL_Bouton));

	strcpy(nouvBouton->texte, pTexte);
	nouvBouton->abscisse = pCoord->x;
	nouvBouton->ordonnee = pCoord->y;
	nouvBouton->tailleTexte = pTailleTexte;
	nouvBouton->largCarac = nouvBouton->tailleTexte/1.5;
	nouvBouton->longTexte = strlen(nouvBouton->texte);

	return nouvBouton;
}

void afficherBouton(SDL_Bouton * pBouton)
{
	SDL_Surface * fondBouton, * texteBouton;
	TTF_Font * police;
	SDL_Color couleurTexte = {SDL_BOUTON_KCOULTXT_R,SDL_BOUTON_KCOULTXT_G,SDL_BOUTON_KCOULTXT_B};
	SDL_Rect positionFondBouton, positionTexteBouton;

	police = chargerPoliceEcriture("default.ttf", pBouton->tailleTexte);

	positionFondBouton.x = pBouton->abscisse;
	positionFondBouton.y = pBouton->ordonnee;
	positionTexteBouton.x = pBouton->abscisse + SDL_BOUTON_KESP_HORI;
	positionTexteBouton.y = pBouton->ordonnee + SDL_BOUTON_KESP_VERT;

	fondBouton = SDL_CreateRGBSurface(SDL_HWSURFACE, pBouton->longTexte*pBouton->largCarac+2*SDL_BOUTON_KESP_HORI, pBouton->tailleTexte+2*SDL_BOUTON_KESP_VERT, 32, 0, 0, 0, 0);

	fondBouton = SDL_DisplayFormat(fondBouton);

	SDL_FillRect(fondBouton, NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, SDL_BOUTON_KCOUL_R, SDL_BOUTON_KCOUL_G, SDL_BOUTON_KCOUL_B));
	SDL_BlitSurface(fondBouton, NULL, SDL_GetVideoSurface(), &positionFondBouton);

	texteBouton = TTF_RenderText_Blended(police, pBouton->texte, couleurTexte);
	SDL_BlitSurface(texteBouton, NULL, SDL_GetVideoSurface(), &positionTexteBouton);

	TTF_CloseFont(police);
	SDL_FreeSurface(fondBouton);
	SDL_FreeSurface(texteBouton);
}

int clicSurBouton(SDL_Bouton * pBouton, SDL_Rect * positionClic)
{
	if(positionClic->x >= pBouton->abscisse && positionClic->x <= pBouton->abscisse+pBouton->longTexte*pBouton->largCarac+2*SDL_BOUTON_KESP_HORI && positionClic->y >= pBouton->ordonnee && positionClic->y <= pBouton->ordonnee+pBouton->tailleTexte+2*SDL_BOUTON_KESP_VERT)
		return 1;
	else
		return 0;
}

void libererBouton(SDL_Bouton * pBouton)
{
	free(pBouton);
}
