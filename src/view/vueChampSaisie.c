/**
 * \file vueChampSaisie.c
 * \author Aurélien Bertron
 * \date 29 avril 2012
 * \brief Vue champ saisie
 *
 * Contient les corps des fonctions d'entrée/sortie du module de champs de saisie.
 * Ce module implémente la gestion du champ de saisie. Il permet à l'utilisateur de saisir une chaine de caractères.
 */

#include "../model/champSaisie.h"

#include "includeSDL.h"
#include "vueChampSaisie.h"
#include "vueUtilsSDL.h"

#include "../ctrl/utilsPoliceEcriture.h"
#include "../ctrl/fichierDebug.h"

#include <string.h>

void AfficherChamp(ChampSaisie * champ)
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

void EditerChamp(ChampSaisie * champ)
{
	int continuer = 1;
	int etatEvent;

	SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));

	SDL_EnableUNICODE(SDL_ENABLE);

	while (continuer)
	{
		AfficherChamp(champ);
		SDL_Flip(SDL_GetVideoSurface());

		etatEvent = AttendreEvent(positionClic, touche);

		if(etatEvent == 1)
		{
			if(!ClicSurChamp(champ, positionClic))
			{
				ChangeFocus(champ, CHAMP_INACTIF);
				continuer = 0;
			}

		}

		else if(etatEvent == 2)
		{
			if(ToucheSpec(touche) == SDLK_BACKSPACE)
				champ->chaine = SupprimerDernierChar(champ->chaine);
			else
			{
				if(!ChainePleine(champ))
					champ->chaine = AjouterCharFin(champ->chaine, ToucheChar(touche));
			}
		}

	}

	SDL_EnableUNICODE(SDL_DISABLE);

	free(positionClic);
	free(touche);
}

int ClicSurChamp(ChampSaisie * champ, SDL_Rect * positionClic)
{
	int codeRetour = 0;

	if(positionClic->x >= champ->abscisse && positionClic->x <= champ->abscisse+champ->longMax*champ->largCarac+2*KESP_HORI &&
	positionClic->y >= champ->ordonnee && positionClic->y <= champ->ordonnee+champ->tailleTexte+2*KESP_VERT)
	{
		codeRetour = 1;
	}

	return codeRetour;

}
