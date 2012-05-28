#include "includeSDL.h"
#include "SDLButton.h"
#include <string.h>

SDL_Bouton * CreerBouton(char * pTexte, SDL_Rect * pCoord, int pTailleTexte)
{
	if(strlen(pTexte)>SDL_BOUTON_KLONGMAX)
		return NULL;
	
	SDL_Bouton * nouvBouton = (SDL_Bouton*)malloc(sizeof(SDL_Bouton));
	
	strcpy(nouvBouton->texte, pTexte);
	nouvBouton->coordBouton = pCoord;
	nouvBouton->tailleTexte = pTailleTexte;
	
	return nouvBouton;
}

void AfficherBouton(SDL_Bouton * pBouton)
{
	SDL_Surface * fondBouton, * texteBouton;
	TTF_Font * police;
	SDL_Color couleurTexte = {SDL_BOUTON_KCOULTXT_R,SDL_BOUTON_KCOULTXT_G,SDL_BOUTON_KCOULTXT_B};
	SDL_Rect positionFondBouton;
	
	police = TTF_OpenFont("Fonts/default.ttf", pBouton->tailleTexte);
	
	positionFondBouton.x = pBouton->coordBouton->x - SDL_BOUTON_KESP_HORI;
	positionFondBouton.y = pBouton->coordBouton->y - SDL_BOUTON_KESP_VERT;
	
	fondBouton = SDL_CreateRGBSurface(SDL_HWSURFACE, strlen(pBouton->texte)*SDL_BOUTON_KLARGCHAR+2*SDL_BOUTON_KESP_HORI, pBouton->tailleTexte+2*SDL_BOUTON_KESP_VERT, 32, 0, 0, 0, 0);
	
	fondBouton = SDL_DisplayFormat(fondBouton);
	
	SDL_FillRect(fondBouton, NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, SDL_BOUTON_KCOUL_R, SDL_BOUTON_KCOUL_G, SDL_BOUTON_KCOUL_B));
	SDL_BlitSurface(fondBouton, NULL, SDL_GetVideoSurface(), &positionFondBouton);
	
	texteBouton = TTF_RenderText_Blended(police, pBouton->texte, couleurTexte);
	SDL_BlitSurface(texteBouton, NULL, SDL_GetVideoSurface(), pBouton->coordBouton);
	
	TTF_CloseFont(police);
	SDL_FreeSurface(fondBouton);
	SDL_FreeSurface(texteBouton);
}

void LibererBouton(SDL_Bouton * pBouton)
{
	free(pBouton);
}