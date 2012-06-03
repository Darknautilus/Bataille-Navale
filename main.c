#include <stdio.h>
#include <stdlib.h>

// Permet la portabilité du programme
#include "includeSDL.h"

#include "utilsSDL.h"
#include "vueUtilsSDL.h"

#include "menu.h"

#include "parametre.h"

#include "grille.h"
#include "vueGrille.h"

#include "champSaisie.h"
#include "vueChampSaisie.h"
#include "regles.h"

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

	ecran = DemarrerSDL(800, 600, "Bataille Navale");

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

	return 0;
}
