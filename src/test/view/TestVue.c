#include "test/view/TestVue.h"

#include "view/IncludeSDL.h"
#include "view/VueGrille.h"
#include "view/VueUtilsSDL.h"
#include "view/VueChampSaisie.h"

#include "model/Grille.h"
#include "ctrl/UtilsSDL.h"

void menuTestVue(void)
{
	int continuer = 1;
	SDL_Keysym touche;

	while (continuer)
	{
            effacerEcran();

            UpdateWindow(SDL_TRUE);
            attendreEvent(NULL, &touche);

            if(touche.scancode == SDL_SCANCODE_SPACE)
                    continuer = 0;

            switch (touche.scancode)
            {
                default:
                    break;
            }
	}
}
