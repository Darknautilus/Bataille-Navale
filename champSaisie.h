#ifndef CHAMP_SAISIE_H
#define CHAMP_SAISIE_H

/*
    Ce module implémente la gestion du champ de saisie. Il permet à l'utilisateur de saisir une chaine de caractères

*/

typedef struct
{
    char * chaine;
    int longMax;
    int tailleTexte;
    int abscisse;
    int ordonnee;
    int onFocus;
}ChampSaisie;

ChampSaisie * CreerChamp(int longMax, int taille, int abscisse, int ordonnee);

ChampSaisie * InitTexte(ChampSaisie * champ, char * texte);

void AfficherChamp(ChampSaisie * champ, SDL_Surface * ecran);

int ClicSurChamp(ChampSaisie * champ, SDL_Rect positionClic);

ChampSaisie * ChangeFocus(ChampSaisie * champ);

void LibererChamp(ChampSaisie * champ);

#endif