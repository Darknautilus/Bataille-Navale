#include "vueBateau.h"

#include "../model/grille.h"
#include "../model/bateau.h"

#include <stdlib.h>

// insère un bateau dans une grille
Grille * InsertBateau(Grille * grille, TBateau * bat)
{
	int i;
	Coord coordCaseGrille;

	if(!estPlacable(bat, grille))
        return NULL;

	// détermine si le bateau est plaçé sur un autre bateau et l'insère si tout va bien
	for(i=0;i<getTypeBateau(bat);i++)
	{
		if(bat->etat[i] == TOUCHE)
			grille = SetEtatCase(grille, coordCaseGrille, GRILLE_CASE_TOUCHE);
		else if(bat->etat[i] == COULE)
			grille = SetEtatCase(grille, coordCaseGrille, GRILLE_CASE_COULE);
		else
			grille = SetEtatCase(grille, coordCaseGrille, GRILLE_CASE_NORMAL);
	}

	return grille;
}

