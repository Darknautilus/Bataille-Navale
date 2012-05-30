#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"

Joueur * nouvJoueur(void)
{
	Joueur *joueur = (Joueur*)malloc(sizeof(Joueur));
	joueur->type = UNDEF;

	return joueur;
}

int getTypeJoueur(const Joueur * pJoueur)
{
	return pJoueur->type;
}

char * getNomJoueur(Joueur * pJoueur)
{
	return pJoueur->nomJ;
}

void LibererJoueur(Joueur * pJoueur)
{
	free(pJoueur);
}
