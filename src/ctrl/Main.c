#include "ctrl/Menu.h"
#include "ctrl/Jeu.h"
#include "ctrl/UtilsSDL.h"
#include "ctrl/FichierDebug.h"
#include "ctrl/FichierSauvRes.h"
#include "ctrl/EcransDivers.h"

#include "model/ChampSaisie.h"
#include "model/Parametre.h"
#include "model/Grille.h"
#include "model/Random.h"
#include "model/Partie.h"

#include "view/VueUtilsSDL.h"
#include "view/VueGrille.h"
#include "view/VueChampSaisie.h"
#include "view/VueRegles.h"
#include "view/IncludeSDL.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	SDL_Surface * ecran;

	int choixMenu;
	int continuer = 1;
	int i;
    int partiePrete;
    int resultPartie = 0;

	ecran = demarrerSDL(1024, 768, "Bataille Navale");

    Tparam * parametrePartie = malloc (sizeof(Tparam));

    init_debug();
    initRandom();

    //EcranGrille(NULL);

	afficherMenuAccueil();

	while (continuer)
	{
	    //On créer un tableau d'entier
	    int * nbType = malloc (sizeof(int) * K_NBTYPEBATEAUX);
	    for(i = 0 ; i < K_NBTYPEBATEAUX ; i++){
            nbType[i]=1;
	    }

        parametrePartie = newTParam(nbType);
		choixMenu = afficherMenuRacine();

        switch (choixMenu)
        {
            case 1: // Nouvelle Partie
                partiePrete = menuNouvellePartie(parametrePartie);
                if(partiePrete)
                {
                    resultPartie = jeu(parametrePartie);
					if(resultPartie == 1)
						ecranVictoire();
					else if(resultPartie == -1)
						ecranPerte();
                }
                break;

            case 2: // Charger partie
                globalPartie = restaurerPartie("partieUser.dat");
                resultPartie = ecranJeu();
				if(resultPartie == 1)
					ecranVictoire();
				else if(resultPartie == -1)
					ecranPerte();
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

	arreterSDL();
	detruire_debug();

    libererParam(parametrePartie);


	return 0;
}
