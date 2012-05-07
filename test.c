// Permet la portabilité du programme
#ifdef __APPLE__
	#include <SDL/SDL.h>
#else
	#include <SDL.h>
#endif

#include "vueUtilsSDL.h"
#include "vueChampSaisie.h"
#include "test.h"

void MenuTest(void)
{
	int continuer = 1;
	SDL_keysym * touche = (SDL_keysym*) malloc(sizeof(SDL_keysym));

	while (continuer)
	{
		EffacerEcran();
		EcrireTexte("Partie Test", 40, 20, 20);
		SDL_Flip(SDL_GetVideoSurface());
		AttendreEvent(NULL, touche);

		if(ToucheSpec(touche) == SDLK_ESCAPE)
			continuer = 0;
    }
}
