#include "VueRegles.h"

// Permet la portabilité du programme
#include "includeSDL.h"

#include "VueUtilsSDL.h"
#include "VueChampSaisie.h"


void afficherRegles()
{
	int continuer = 1;
	SDL_keysym * touche = (SDL_keysym*) malloc(sizeof(SDL_keysym));

	while (continuer)
	{
		effacerEcran();


		SDL_Flip(SDL_GetVideoSurface());
		attendreEvent(NULL, touche);

		if(toucheSpec(touche) == SDLK_ESCAPE)
			continuer = 0;

	}
}
