#include "pileCoup.h"

#include "../ctrl/fichierDebug.h"

#include <stdio.h>
#include <stdlib.h>

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
	struct Cellule * N = (struct Cellule *) malloc(sizeof(struct Cellule));
	if(N == NULL)
	{
		dgErreur("Erreur allocation memoire : Empiler()");
		exit(1);
	}

	N->Info = pElem;
	N->Lien = pPile;

	return N;
}

Pile Depiler(Pile pPile)
{
	Pile N = pPile->Lien;

	free(pPile);

	return N;
}

Coup* Sommet(Pile pPile)
{
	return pPile->Info;
}

int longueurPile(Pile pile){

    int longueur = 0;

    //tant que l'on a pas attein la fin de la pile
    while(pile->Lien != NULL){
        pile = pile->Lien;
        longueur++;
    }

    return longueur;
}
