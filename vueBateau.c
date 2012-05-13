#include <stdlib.h>

#include "vueBateau.h"
#include "grille.h"

// insère un bateau dans une grille
Grille * InsertBateau(Grille * grille, TBateau * bat)
{
	int i;

	// détermine si le bateau est en dehors de la grille
	if ( (bat->position.direction == HORIZONTAL && bat->position.x + bat->type > grille->NbLin) ||
	(bat->position.direction == VERTICAL && bat->position.y + bat->type > grille->NbCol) )
		return NULL;

	// détermine si le bateau est plaçé sur un autre bateau
	//if (bat->position)

	// insère le bateau
	Coord pos;
	pos.noLin = bat->position.x;
	pos.noCol = bat->position.y;

	// 1ere case du bateau
	if (bat->etat[0] == INTACT)
		grille = SetEtatCase(grille, pos, GRILLE_CASE_NORMAL);

	else if (bat->etat[0] == TOUCHE)
		grille = SetEtatCase(grille, pos, GRILLE_CASE_TOUCHE);

	else
		grille = SetEtatCase(grille, pos, GRILLE_CASE_COULE);

	for (i=0; i < bat->type; i++)
	{
		if (bat->position.direction == HORIZONTAL)
			pos.noLin = bat->position.x + i;
		else
			pos.noCol = bat->position.y + i;

		grille = SetEtatCase(grille, pos, GRILLE_CASE_NORMAL);
	}

	return grille;
}

