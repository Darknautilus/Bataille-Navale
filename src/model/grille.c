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
#include "bateau.h"

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
		nouvGrille->Matrice = (Ligne*) malloc(nbLin * sizeof(Ligne));
		if(nouvGrille->Matrice == NULL)
			return NULL;

		// Parcours des lignes
		for(i=0; i<nbCol; i++)
		{
			nouvGrille->Matrice[i] = (CaseGrille*) malloc(nbLin * sizeof(CaseGrille));
			if(nouvGrille->Matrice[i] == NULL)
				return NULL;

			// Et on initialise
			for(j=0; j<nbLin; j++)
			{
				nouvGrille->Matrice[i][j].etatCase = GRILLE_CASE_NORMAL;
				nouvGrille->Matrice[i][j].couleur = KIDCOULDEFAUT;
                nouvGrille->Matrice[i][j].idBateauOccupe = -1;
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

CaseGrille * Consulter(Grille * grille, Coord coord)
{
	return &(grille->Matrice[coord.noCol-1][coord.noLin-1]);
}

Grille * SetEtatCase(Grille * grille, Coord coord, EtatCase etat)
{
	grille->Matrice[coord.noCol-1][coord.noLin-1].etatCase = etat;

	return grille;
}

int getIdBateauSurCase(Grille *grille, Coord coord){
    return Consulter(grille, coord)->idBateauOccupe;
}

Grille * EffacerGrille(Grille * grille)
{
	int i,j;

	for(i=0;i<grille->NbCol;i++)
	{
		for(j=0;j<grille->NbLin;j++)
		{
			grille->Matrice[i][j].etatCase = GRILLE_CASE_NORMAL;
		}
	}

	return grille;
}

void LibererGrille(Grille * grille)
{
	int i;

	for(i=0;i<grille->NbCol;i++)
		free(grille->Matrice[i]);

	free(grille->Matrice);
	free(grille);
}
