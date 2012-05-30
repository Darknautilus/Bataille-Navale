#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"

Joueur * nouvJoueur(void)
{
	return (Joueur*)malloc(sizeof(Joueur));
}

int getIDJoueur(const Joueur * pJoueur)
{
	return pJoueur->idJ;
}

char * getNomJoueur(Joueur * pJoueur)
{
	return pJoueur->nomJ;
}

void LibererJoueur(Joueur * pJoueur)
{
	free(pJoueur);
}