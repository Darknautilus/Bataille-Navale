#include "model/ChampSaisie.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ChampSaisie * creerChamp(int longMax, int taille, int abscisse, int ordonnee)
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

void supprimerDernierChar(char * chaine)
{
    while(*chaine) chaine++;
    *(--chaine) = '\0';
}

void libererChamp(ChampSaisie * champ)
{
    free(champ->chaine);
    free(champ);
}
