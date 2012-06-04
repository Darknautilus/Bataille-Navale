#include "../model/champSaisie.h"
#include "../model/parametre.h"
#include "../model/grille.h"

#include "../view/vueUtilsSDL.h"
#include "../view/menu.h"
#include "../view/vueGrille.h"
#include "../view/vueChampSaisie.h"
#include "../view/vueRegles.h"
#include "../view/includeSDL.h"

#include "utilsSDL.h"
#include "fichierDebug.h"

#include <stdio.h>
#include <stdlib.h>

void pause()
{
	int continuer = 1;
	SDL_Event event;

	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				exit(EXIT_FAILURE);
			break;

			case SDL_KEYDOWN:
				continuer = 0;
			break;
        }
    }

}

int main(int argc, char ** argv)
{
	SDL_Surface * ecran;

	int choixMenu;
	int continuer = 1;

	ecran = DemarrerSDL(1024, 768, "Bataille Navale");

    init_debug();

	AfficherMenuAccueil();

	while (continuer)
	{
		choixMenu = AfficherMenuRacine();

        switch (choixMenu)
        {
            case 1: // Nouvelle Partie
                MenuNouvellePartie();
                break;

            case 2: // Charger partie

                break;

            case 3: // Meilleurs scores

                break;

            case 4: // Afficher règles
                afficherRegles();
                break;

            case 5: // Quitter
                continuer = 0;
                break;

            default:
                break;
        }
    }

	ArreterSDL();
	detruire_debug();

	return 0;
}
