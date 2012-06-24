#include "../model/ChampSaisie.h"

#include "includeSDL.h"
#include "VueChampSaisie.h"
#include "VueUtilsSDL.h"

#include "../ctrl/UtilsPoliceEcriture.h"
#include "../ctrl/FichierDebug.h"

#include <string.h>

void afficherChamp(ChampSaisie * champ)
{
	SDL_Surface * champBG, * texte;
	TTF_Font * police;
	SDL_Color couleurTexte = {KCOULTXT_R, KCOULTXT_G, KCOULTXT_B};
	SDL_Rect positionChamp, positionTexte;
	Uint32 couleurFondChamp;

	police = chargerPoliceEcriture("default.ttf", champ->tailleTexte);

	positionChamp.x = champ->abscisse;
	positionChamp.y = champ->ordonnee;
	positionTexte.x = champ->abscisse+KESP_HORI;
	positionTexte.y = champ->ordonnee+KESP_VERT;

	champBG = SDL_CreateRGBSurface(SDL_HWSURFACE, champ->longMax*champ->largCarac+2*KESP_HORI, champ->tailleTexte+2*KESP_VERT, 32, 0, 0, 0, 0);

	if(champ->onFocus == CHAMP_ACTIF)
		couleurFondChamp = SDL_MapRGB(champBG->format, KCOULEDIT_R, KCOULEDIT_G, KCOULEDIT_B);
	else
		couleurFondChamp = SDL_MapRGB(champBG->format, KCOULNORM_R, KCOULNORM_G, KCOULNORM_B);

	SDL_FillRect(champBG, NULL, couleurFondChamp);

	texte = TTF_RenderText_Blended(police, champ->chaine, couleurTexte);

	SDL_BlitSurface(champBG, NULL, SDL_GetVideoSurface(), &positionChamp);
	SDL_BlitSurface(texte, NULL, SDL_GetVideoSurface(), &positionTexte);

	SDL_FreeSurface(champBG);
	SDL_FreeSurface(texte);
	TTF_CloseFont(police);
}

void editerChamp(ChampSaisie * champ)
{
	int continuer = 1;
	int etatEvent;

	SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));

	SDL_EnableUNICODE(SDL_ENABLE);
    
    changeFocus(champ, CHAMP_ACTIF);

	while (continuer)
	{
		afficherChamp(champ);
		SDL_Flip(SDL_GetVideoSurface());

		etatEvent = attendreEvent(positionClic, touche);

		if(etatEvent == 1)
		{
			if(!clicSurChamp(champ, positionClic))
			{
				changeFocus(champ, CHAMP_INACTIF);
				continuer = 0;
			}

		}

		else if(etatEvent == 2)
		{
			if(toucheSpec(touche) == SDLK_BACKSPACE)
				champ->chaine = supprimerDernierChar(champ->chaine);
			else
			{
				if(!chainePleine(champ))
					champ->chaine = ajouterCharFin(champ->chaine, toucheChar(touche));
			}
		}

	}

	SDL_EnableUNICODE(SDL_DISABLE);

	free(positionClic);
	free(touche);
}

int clicSurChamp(ChampSaisie * champ, SDL_Rect * positionClic)
{
	int codeRetour = 0;

	if(positionClic->x >= champ->abscisse && positionClic->x <= champ->abscisse+champ->longMax*champ->largCarac+2*KESP_HORI &&
	positionClic->y >= champ->ordonnee && positionClic->y <= champ->ordonnee+champ->tailleTexte+2*KESP_VERT)
	{
		codeRetour = 1;
	}

	return codeRetour;

}
