/**
 * \file grille.c
 * \author Aurélien Bertron
 * \date 21 avril 2012
 * \brief Code modèle grille
 *
 * Contient les corps des fonctions du module de grille
 *
 */

#include <stdlib.h>

#include "grille.h"
#include "couleurs.h"

Grille * CreerGrille(int nbLin, int nbCol)
{
	Grille * grille;
	int i;
	int j;

	// Controle des paramètres
	if(nbLin > 0 && nbCol > 0)
	{
		// Allocation de la matrice
		Grille * nouvGrille = (Grille*) malloc(sizeof(Grille));

		if(nouvGrille == NULL)
			return NULL;

		nouvGrille->NbLin = nbLin;
		nouvGrille->NbCol = nbCol;

		// Allocation du tableau de lignes
		nouvGrille->TabLignes = (Ligne*) malloc(nbLin * sizeof(Ligne));
		if(nouvGrille->TabLignes == NULL)
			return NULL;

		// Parcours des lignes
		for(i=0; i<nbLin; i++)
		{
			nouvGrille->TabLignes[i] = (CaseGrille*) malloc(nbCol * sizeof(CaseGrille));
			if(nouvGrille->TabLignes[i] == NULL)
				return NULL;
			
			// Et on initialise
			for(j=0; j<nbCol; j++)
			{
				nouvGrille->TabLignes[i][j].etatCase = GRILLE_CASE_NORMAL;
				nouvGrille->TabLignes[i][j].couleur = KIDCOULDEFAUT;
			}
		}

		grille = nouvGrille;
	}
	else
	{
		grille = NULL;
	}

	return grille;
}

CaseGrille Consulter(Grille * grille, Coord coord)
{
	return grille->TabLignes[coord.noLin-1][coord.noCol-1];
}

Grille * SetEtatCase(Grille * grille, Coord coord, EtatCase etat)
{
	grille->TabLignes[coord.noLin-1][coord.noCol-1].etatCase = etat;

	return grille;
}

Grille * EffacerGrille(Grille * grille)
{
	int i,j;

	for(i=0;i<grille->NbLin;i++)
	{
		for(j=0;j<grille->NbCol;j++)
		{
			grille->TabLignes[i][j].etatCase = GRILLE_CASE_NORMAL;
		}
	}

	return grille;
}

void LibererGrille(Grille * grille)
{
	int i;

	for(i=0;i<grille->NbLin;i++)
		free(grille->TabLignes[i]);

	free(grille->TabLignes);
	free(grille);
}
