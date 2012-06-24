#include "Joueur.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Joueur * creerJoueur(void)
{
	Joueur *joueur = (Joueur*)malloc(sizeof(Joueur));
	joueur->type = UNDEF;

    joueur->mesBateaux = NULL;


    strcpy(joueur->nomJ, "");

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

void libererJoueur(Joueur * pJoueur)
{
	free(pJoueur);
}
