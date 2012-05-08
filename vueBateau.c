#include "vueBateau.h"
#include <stdlib.h>

// insère un bateau dans une grille
Grille * InsertBateau(Grille * grille, TBateau * bat)
{
	// détermine si le bateau est en dehors de la grille
	if ( (bat->position.direction == HORIZONTAL && bat->position.x + bat->type > grille->NbLin) ||
	(bat->position.direction == VERTICAL && bat->position.y + bat->type > grille->NbCol) )
		return NULL;

	return grille;
}
