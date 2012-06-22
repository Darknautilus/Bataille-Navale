#include "VueBateau.h"

#include "../model/Grille.h"
#include "../model/Bateau.h"
#include "../model/Parametre.h"
#include "../model/Partie.h"

#include <stdlib.h>

// insère un bateau dans une grille
Grille * InsertBateau(Grille * grille, TBateau * bat)
{
	int i;
	Coord coordCaseGrille;

	for(i=0;i<getTypeBateau(bat);i++)
	{
        if(bat->position.direction == VERTICAL)
        {
            coordCaseGrille.noCol = bat->position.x;
            coordCaseGrille.noLin = bat->position.y+i;
        }
        else if(bat->position.direction == HORIZONTAL)
        {
            coordCaseGrille.noCol = bat->position.x+i;
            coordCaseGrille.noLin = bat->position.y;
        }

        Consulter(grille, coordCaseGrille)->idBateauOccupe = bat->idBateau;
        Consulter(grille, coordCaseGrille)->couleur = getInfoBateau(bat->idBateau, partie_Param())->couleur;

		if(bat->etat[i] == TOUCHE)
			grille = SetEtatCase(grille, coordCaseGrille, GRILLE_CASE_TOUCHE);
		else if(bat->etat[i] == COULE)
			grille = SetEtatCase(grille, coordCaseGrille, GRILLE_CASE_COULE);
		else
			grille = SetEtatCase(grille, coordCaseGrille, GRILLE_CASE_NORMAL);
	}

	return grille;
}

