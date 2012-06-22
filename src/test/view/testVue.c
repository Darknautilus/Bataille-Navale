#include "testVue.h"

#include "../../model/grille.h"

// Permet la portabilité du programme
#include "../../view/includeSDL.h"
#include "../../view/vueGrille.h"
#include "../../view/vueUtilsSDL.h"
#include "../../view/vueChampSaisie.h"


void MenuTestVue(void)
{
	int continuer = 1;
	SDL_keysym * touche = (SDL_keysym*) malloc(sizeof(SDL_keysym));

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
