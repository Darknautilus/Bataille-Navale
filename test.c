// Permet la portabilité du programme
#ifdef __APPLE__
	#include <SDL/SDL.h>
#else
	#include <SDL.h>
#endif

#include "vueUtilsSDL.h"
#include "vueChampSaisie.h"
#include "test.h"
#include "grille.h"
#include "vueGrille.h"
#include "bateau.h"
#include "vueBateau.h"

void MenuTest(void)
{
	int continuer = 1;
	SDL_keysym * touche = (SDL_keysym*) malloc(sizeof(SDL_keysym));

	Grille * grille = CreerGrille(10, 10);

	TPosition pos1 = {HORIZONTAL, 1, 1};
	TPosition pos1 = {HORIZONTAL, 1, 1};
	TPosition pos1 = {HORIZONTAL, 1, 1};
	TPosition pos1 = {HORIZONTAL, 1, 1};
	TPosition pos1 = {HORIZONTAL, 1, 1};

	TBateau * bat1;
	TBateau * bat2;
	TBateau * bat3;
	TBateau * bat4;
	TBateau * bat5;

	while (continuer)
	{
		EffacerEcran();

		bat1 = creerBateau(pos1, VOILIER);
		grille = InsertBateau(grille, bat1);

		afficherGrille(grille, SDL_GetVideoSurface(), 50, 50);

		SDL_Flip(SDL_GetVideoSurface());
		AttendreEvent(NULL, touche);

		if(ToucheSpec(touche) == SDLK_ESCAPE)
			continuer = 0;
	}
	LibererGrille(grille);

}
