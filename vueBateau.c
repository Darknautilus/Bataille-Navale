#include <stdlib.h>

#include "vueBateau.h"
#include "grille.h"

// insère un bateau dans une grille
Grille * InsertBateau(Grille * grille, TBateau * bat)
{
	int i;
	Coord coordCaseGrille;

	// détermine si le bateau est en dehors de la grille
	if ( (bat->position.direction == HORIZONTAL && bat->position.x + bat->type > grille->NbLin) ||
	(bat->position.direction == VERTICAL && bat->position.y + bat->type > grille->NbCol) )
		return NULL;

	// détermine si le bateau est plaçé sur un autre bateau et l'insère si tout va bien
	for(i=0;i<bat->type;i++)
	{
		if(bat->position.direction == HORIZONTAL)
		{
			coordCaseGrille.noCol = bat->position.x + i;
			coordCaseGrille.noLin = bat->position.y;
		}
		else
		{
			coordCaseGrille.noCol = bat->position.x;
			coordCaseGrille.noLin = bat->position.y + i;
		}
		
		if(Consulter(grille, coordCaseGrille).estOccupe)
			return NULL;
		
		if(bat->etat[i] == TOUCHE)
			grille = SetEtatCase(grille, coordCaseGrille, GRILLE_CASE_TOUCHE);
		else if(bat->etat[i] == COULE)
			grille = SetEtatCase(grille, coordCaseGrille, GRILLE_CASE_COULE);
		else
			grille = SetEtatCase(grille, coordCaseGrille, GRILLE_CASE_NORMAL);
	}

	return grille;
}

