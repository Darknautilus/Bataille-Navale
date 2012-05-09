#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "champSaisie.h"


ChampSaisie * CreerChamp(int longMax, int taille, int abscisse, int ordonnee)
{
	ChampSaisie * champ;

	champ = (ChampSaisie*)malloc(sizeof(ChampSaisie));

	champ->chaine = (char*)malloc((longMax+1)*sizeof(char));
	champ->longMax = longMax;
	champ->tailleTexte = taille;
	champ->abscisse = abscisse;
	champ->ordonnee = ordonnee;
	champ->onFocus = CHAMP_INACTIF;

	return champ;
}

void InitTexte(ChampSaisie * champ, char * chaine)
{
strcpy(champ->chaine, chaine);
}

int ChainePleine(ChampSaisie * champ)
{
	int codeRetour = 1;

	if(strlen(champ->chaine) < champ->longMax)
		codeRetour = 0;

	return codeRetour;
}

void ChangeFocus(ChampSaisie * champ, EtatChamp etat)
{
	champ->onFocus = etat;
}

char * SupprimerDernierChar(char * chaine)
{
	int i=0;
	while(chaine[i]!='\0')
	{
		i++;
	}

	chaine[i-1] = '\0';

	return chaine;
}

char * AjouterCharFin(char * chaine, char charEnt)
{
	int i=0;
	while (chaine[i]!='\0')
	{
		i++;
	}

	chaine[i+1] = '\0';
	chaine[i] = charEnt;

	return chaine;
}

void LibererChamp(ChampSaisie * champ)
{
	free(champ->chaine);
	free(champ);
}
