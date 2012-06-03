#include <stdio.h>
#include <stdlib.h>

#include "pileCoup.h"

Pile CreerPile(void)
{
	return NULL;
}

int PileVide(Pile pPile)
{	
	return pPile == NULL;
}

Pile Empiler(Pile pPile, Coup * pElem)
{
	struct Cellule * N = (struct Cellule *)malloc(sizeof(struct Cellule));
	if(N == NULL)
	{
		printf("Erreur allocation memoire : Empiler()");
		exit(1);
	}
	
	N->Info = pElem;
	N->Lien = pPile;
	
	return N;
}

Pile Depiler(Pile pPile)
{
	struct Cellule * N = pPile->Lien;
	
	free(pPile);
	
	return N;
}

Coup * Sommet(Pile pPile)
{
	return pPile->Info;
}