// Permet la portabilité du programme
#ifdef __APPLE__
	#include <SDL/SDL.h>
	#include <SDL_ttf/SDL_ttf.h>
#else
	#include <SDL/SDL.h>
	#include <SDL/SDL_ttf.h>
#endif

#include "champSaisie.h"
#include "vueChampSaisie.h"
#include "vueUtilsSDL.h"

void AfficherChamp(ChampSaisie * champ, SDL_Surface * ecran)
{
	SDL_Surface * champBG, * texte;
	TTF_Font * police;
	SDL_Color couleurTexte = {KCOULTXT_R, KCOULTXT_G, KCOULTXT_B};
	SDL_Rect positionChamp, positionTexte;
	Uint32 couleurFondChamp;

	police = TTF_OpenFont("Fonts/apple.ttf", champ->tailleTexte);

	positionChamp.x = champ->abscisse;
	positionChamp.y = champ->ordonnee;
	positionTexte.x = champ->abscisse+KESP_HORI;
	positionTexte.y = champ->ordonnee+KESP_VERT;

	champBG = SDL_CreateRGBSurface(SDL_HWSURFACE, champ->longMax*KLARGCHAR+2*KESP_HORI, champ->tailleTexte+2*KESP_VERT, 32, 0, 0, 0, 0);

	if(champ->onFocus == CHAMP_ACTIF)
		couleurFondChamp = SDL_MapRGB(champBG->format, KCOULEDIT_R, KCOULEDIT_G, KCOULEDIT_B);
	else
		couleurFondChamp = SDL_MapRGB(champBG->format, KCOULNORM_R, KCOULNORM_G, KCOULNORM_B);

	SDL_FillRect(champBG, NULL, couleurFondChamp);

	texte = TTF_RenderText_Blended(police, champ->chaine, couleurTexte);

	SDL_BlitSurface(champBG, NULL, ecran, &positionChamp);
	SDL_BlitSurface(texte, NULL, ecran, &positionTexte);

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


	/*
	L'utilisation des caractères Unicode nous empêche d'utiliser AttendreEvent() qui ne les prend pas en charge
	La gestion d'Unicode s'active au début du sous-programme puis se désactive à la fin
	*/

	SDL_EnableUNICODE(SDL_ENABLE);

	while (continuer)
	{
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
				champ->chaine = AjouterCharFin(champ->chaine, ToucheChar(touche));
		}

		AfficherChamp(champ, SDL_GetVideoSurface());
		SDL_Flip(SDL_GetVideoSurface());
	}

	SDL_EnableUNICODE(SDL_DISABLE);

	free(positionClic);
	free(touche);
}

int ClicSurChamp(ChampSaisie * champ, SDL_Rect * positionClic)
{
	int codeRetour = 0;

	if(positionClic->x >= champ->abscisse && positionClic->x <= champ->abscisse+champ->longMax*13+20 &&
	positionClic->y >= champ->ordonnee && positionClic->y <= champ->ordonnee+champ->tailleTexte+10)
	{
		codeRetour = 1;
	}

	return codeRetour;

}
