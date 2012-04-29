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

int ChainePleine(ChampSaisie * champ);

void AfficherChamp(ChampSaisie * champ, SDL_Surface * ecran);

int ClicSurChamp(ChampSaisie * champ, SDL_Rect * positionClic);

ChampSaisie * ChangeFocus(ChampSaisie * champ, int val);

int EstNombre(SDL_Event * event);

int EstLettre(SDL_Event * event);

char * SupprimerDernierChar(char * chaine);

char * AjouterCharFin(char * chaine, char charEnt);

void EditerChamp(ChampSaisie * champ);

void LibererChamp(ChampSaisie * champ);

#endif