#include "test/view/TestVue.h"

#include "view/IncludeSDL.h"
#include "view/VueGrille.h"
#include "view/VueUtilsSDL.h"
#include "view/VueChampSaisie.h"

#include "model/Grille.h"

#include <stdlib.h>

void menuTestVue(void)
{
	int continuer = 1;
	SDL_keysym * touche = malloc(sizeof(SDL_keysym));

	SDL_EnableUNICODE(SDL_ENABLE);

	while (continuer)
	{
		effacerEcran();

		SDL_Flip(SDL_GetVideoSurface());
		attendreEvent(NULL, touche);

		if(toucheSpec(touche) == SDLK_ESCAPE)
			continuer = 0;

		switch (toucheChar(touche))
		{

			default:
				break;
		}
	}

	SDL_EnableUNICODE(SDL_DISABLE);
}
