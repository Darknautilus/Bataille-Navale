/**
 * \file champSaisie.c
 * \author Aurélien Bertron
 * \date 29 avril 2012
 * \brief Modele champ saisie
 *
 * Contient les corps des fonctions du module de champs de saisie.
 * Ce module implémente la gestion du champ de saisie. Il permet à l'utilisateur de saisir une chaine de caractères.
*/

#include "ChampSaisie.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ChampSaisie * CreerChamp(int longMax, int taille, int abscisse, int ordonnee)
{
	ChampSaisie * champ;

	champ = (ChampSaisie*)malloc(sizeof(ChampSaisie));
    if(champ != NULL)
    {
        champ->chaine = (char*)malloc((longMax+1)*sizeof(char));
        champ->longMax = longMax;
        champ->tailleTexte = taille;
		champ->largCarac = champ->tailleTexte/2;
        champ->abscisse = abscisse;
        champ->ordonnee = ordonnee;
        champ->onFocus = CHAMP_INACTIF;
    }

	return champ;
}

void initTexte(ChampSaisie * champ, const char * chaine)
{
    strcpy(champ->chaine, chaine);
}

int chainePleine(const ChampSaisie * champ)
{
	int codeRetour = 1;

	if(strlen(champ->chaine) < champ->longMax)
		codeRetour = 0;

	return codeRetour;
}

void changeFocus(ChampSaisie * champ, EtatChamp etat)
{
	champ->onFocus = etat;
}

char * supprimerDernierChar(char * chaine)
{
	int i=0;
	while(chaine[i]!='\0')
		i++;

	chaine[i-1] = '\0';

	return chaine;
}

char * ajouterCharFin(char * chaine, char charEnt)
{
	int i=0;
	while (chaine[i] != '\0')
		i++;

	chaine[i+1] = '\0';
	chaine[i] = charEnt;

	return chaine;
}

void LibererChamp(ChampSaisie * champ)
{
	free(champ->chaine);
	free(champ);
}
