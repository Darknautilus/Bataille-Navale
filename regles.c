// Permet la portabilité du programme
#include "includeSDL.h"


#include "vueUtilsSDL.h"
#include "vueChampSaisie.h"
#include "regles.h"

void afficherRegles()
{
	int continuer = 1;
	SDL_keysym * touche = (SDL_keysym*) malloc(sizeof(SDL_keysym));

	while (continuer)
	{
		EffacerEcran();


		SDL_Flip(SDL_GetVideoSurface());
		AttendreEvent(NULL, touche);

		if(ToucheSpec(touche) == SDLK_ESCAPE)
			continuer = 0;

	}
}
