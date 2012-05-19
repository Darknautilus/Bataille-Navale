// Permet la portabilité du programme
#include "includeSDL.h"

#include "vueUtilsSDL.h"
#include "vueChampSaisie.h"
#include "testVue.h"
#include "grille.h"
#include "vueGrille.h"
//#include "bateau.h"
//#include "vueBateau.h"

void MenuTestVue(void)
{
	int continuer = 1;
	SDL_keysym * touche = (SDL_keysym*) malloc(sizeof(SDL_keysym));
	
	SDL_EnableUNICODE(SDL_ENABLE);
    
	while (continuer)
	{
		EffacerEcran();

		SDL_Flip(SDL_GetVideoSurface());
		AttendreEvent(NULL, touche);

		if(ToucheSpec(touche) == SDLK_ESCAPE)
			continuer = 0;
		
		switch (ToucheChar(touche))
		{
				
			default:
				break;
		}
	}
	
	SDL_EnableUNICODE(SDL_DISABLE);
}
