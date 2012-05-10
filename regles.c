// Permet la portabilité du programme
#include "includeSDL.h"


#include "vueUtilsSDL.h"
#include "vueChampSaisie.h"
#include "regles.h"

void afficherRegles()
{
	int continuer = 1;
	int posX = 10;
	int posY = 10;
	SDL_keysym * touche = (SDL_keysym*) malloc(sizeof(SDL_keysym));

	while (continuer)
	{
		EffacerEcran();

		EcrireTexte("ABC123?./éàè", 20, posX, posY);

		SDL_Flip(SDL_GetVideoSurface());
		AttendreEvent(NULL, touche);

		if(ToucheSpec(touche) == SDLK_ESCAPE)
			continuer = 0;

	}
}
