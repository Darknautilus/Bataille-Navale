#include "VueRegles.h"

#include "../view/IncludeSDL.h"
#include "../view/VueUtilsSDL.h"
#include "../view/VueChampSaisie.h"


void afficherRegles()
{
	int continuer = 1;
	SDL_Rect positionTexte;
	SDL_keysym * touche = (SDL_keysym*) malloc(sizeof(SDL_keysym));

	while (continuer)
	{
		effacerEcran();

		positionTexte.x = 450;
		positionTexte.y = 15;
		ecrireTexte("Regles", 30, positionTexte, "default.ttf");

		positionTexte.x = 15;
		positionTexte.y = 50;
		ecrireTexte("Le but:\nIl s'agit de decouvrir en premier l'emplacement des bateaux de son adversaire pour les\ncouler et ainsi faire capituler la flotte adverse.\n\nLes preparatifs de jeu:\nChacun des deux jours a une grille comportant 10 cases sur chacun de ses cotes.\nEn ordonnee, on porte les lettres (de A a J soit 10 cases) et en abscisse les chiffres de\n1 a 10. Les joueurs placent leurs navires sur leur grille.\n\nLa regle de la bataille navale:\nChaque joueur a a sa disposition 5 types de navires : Porte-avions (5 cases),\nSous-marin (4 cases), Cargot (3 cases), Remorqueur (2 cases) et Voilier (1 case).\nLe joueur qui entame la partie declare la ou il pense que son adversaire a cache un navire\nen declarant B5 par exemple. L'adversaire repond par \"rate\" ou \"touche\".\nUn bateau entierement touche est \"coule\".\n\nLa fin de la bataille navale :\nLe gagnant est celui qui en premier a decouvert et detruit l'integralite de la flotte\nadverse.", 20, positionTexte, "default.ttf");


		SDL_Flip(SDL_GetVideoSurface());

		attendreEvent(NULL, touche);

		if(toucheSpec(touche) == SDLK_ESCAPE)
			continuer = 0;

	}
}
