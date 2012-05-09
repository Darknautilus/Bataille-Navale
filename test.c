// Permet la portabilité du programme
#ifdef __APPLE__
	#include <SDL/SDL.h>
#else
	#include <SDL/SDL.h>
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

	while (continuer)
	{
		EffacerEcran();

		SDL_Flip(SDL_GetVideoSurface());
		AttendreEvent(NULL, touche);

		if(ToucheSpec(touche) == SDLK_ESCAPE)
			continuer = 0;
	}
	LibererGrille(grille);

}
