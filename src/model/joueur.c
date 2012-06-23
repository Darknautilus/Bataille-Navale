/**
 *   \file Joueur.c
 *   \author Aurélien Bertron
 *   \date 18 avril 2012 
 *   \brief Module Joueur
 *
 *   Contient les fonctions du module Joueur
 */

#include "Joueur.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Joueur * CreerJoueur(void)
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

void LibererJoueur(Joueur * pJoueur)
{
	free(pJoueur);
}
