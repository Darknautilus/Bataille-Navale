// Permet la portabilité du programme
#include "includeSDL.h"


#include "vueUtilsSDL.h"
#include "utilsSDL.h"

void EcrireCar(char car,int taille, SDL_Rect positionChar)
{
	SDL_Surface * zoneTexte;
	TTF_Font * police = TTF_OpenFont("Fonts/default.ttf", taille);
	SDL_Color couleur = {255,255,255};

	zoneTexte = TTF_RenderUTF8_Blended(police, &car, couleur);
	SDL_BlitSurface(zoneTexte, NULL, SDL_GetVideoSurface(), &positionChar);
	SDL_FreeSurface(zoneTexte);

	TTF_CloseFont(police);
}

void EcrireTexte(char * texte,int taille, SDL_Rect positionTexte)
{
	SDL_Surface * zoneTexte;
	TTF_Font * police = TTF_OpenFont("Fonts/default.ttf", taille);
	SDL_Color couleur = {255,255,255};

	zoneTexte = TTF_RenderUTF8_Blended(police, texte, couleur);
	SDL_BlitSurface(zoneTexte, NULL, SDL_GetVideoSurface(), &positionTexte);
	SDL_FreeSurface(zoneTexte);

	TTF_CloseFont(police);
}

int AttendreEvent(SDL_Rect * coordClic, SDL_keysym * touche)
{
	SDL_Event event;
	int continuer = 1;
	int controle;// Permet de retourner si l'événement est un clic ou une touche

	while(continuer)
	{
		// On attend que quelque chose se passe
		SDL_WaitEvent(&event);
		// Si c'est un clic gauche et qu'on a activé l'option
		if (event.type == SDL_MOUSEBUTTONDOWN && coordClic != NULL && event.button.button == SDL_BUTTON_LEFT)
		{
			coordClic->x = event.button.x;
			coordClic->y = event.button.y;
			controle = 1;
			continuer = 0;
		}

		// Si c'est une touche et qu'on a activé l'option
		else if(event.type == SDL_KEYDOWN && touche != NULL)
		{
			* touche = event.key.keysym;
			controle = 2;
			continuer = 0;
		}

		// Si l'utilisateur a fait n'importe quoi
		else if(coordClic == NULL && touche == NULL)
			continuer = 0;

		// Si l'utilisateur veut quitter brutalement
		else if(event.type == SDL_QUIT)
			exit(EXIT_FAILURE);
	}

    return controle;
}

char ToucheChar(SDL_keysym * touche)
{
    char charTouche;
    
    charTouche = (char)(touche->unicode);
    
	return charTouche; 
}

SDLKey ToucheSpec(SDL_keysym * touche)
{
	return touche->sym;
}

Uint32 convertSDL_Color(SDL_Color pCouleur)
{
	
	return SDL_MapRGB(SDL_GetVideoSurface()->format, pCouleur.r, pCouleur.g, pCouleur.b);
}

void EffacerEcran(void)
{
	SDL_FillRect(SDL_GetVideoSurface(), NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, 0, 0, 0));
}



