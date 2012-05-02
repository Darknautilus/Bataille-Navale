#ifndef CHAMP_SAISIE_H
#define CHAMP_SAISIE_H

/*
    Ce module implémente la gestion du champ de saisie. Il permet à l'utilisateur de saisir une chaine de caractères

    Un champ de saisie est une structure simple mais efficace qui ne doit être manipulée que sous forme de pointeur.
    Détaillons les différents champs du champ :
*/

typedef enum{CHAMP_ACTIF,CHAMP_INACTIF} EtatChamp;

typedef struct
{
    char * chaine;// Chaine tapée dans le champ
    int longMax;// Longueur maximum de la chaine
    int tailleTexte;// Taille de la police de texte
    int abscisse;// Abscisse du champ
    int ordonnee;// Ordonnee du champ
    EtatChamp onFocus;// Vaut CHAMP_ACTIF si le champ est actif (mode édition) et CHAMP_INACTIF sinon
}ChampSaisie;

/*
    Initialise le champ
 
    longMax : longueur maximale du champ
    taille : taille de la police
    abscisse et ordonnee : coordonnees du champ
*/
ChampSaisie * CreerChamp(int longMax, int taille, int abscisse, int ordonnee);

/*
    Initialise le champ avec une chaine de caractères
*/
void InitTexte(ChampSaisie * champ, char * chaine);

/*
    Renvoit 1 si la chaine du champ est pleine et 0 sinon
*/
int ChainePleine(ChampSaisie * champ);

/*
    Renvoit 1 si le clic est sur le champ et 0 sinon
    
    positionClic : coordonnées du clic
*/
int ClicSurChamp(ChampSaisie * champ, SDL_Rect * positionClic);

/*
    Définit le focus du champ (voir champ onFocus de la structure)
*/
void ChangeFocus(ChampSaisie * champ, EtatChamp etat);

/*
    Supprime le dernier caractère d'une chaine
*/
char * SupprimerDernierChar(char * chaine);

/*
    Ajoute un caractère à la fin de la chaine
*/
char * AjouterCharFin(char * chaine, char charEnt);

/*
    Supprime le champ en libérant l'espace mémoire
    Ne pas oublier à la fin du programme
*/
void LibererChamp(ChampSaisie * champ);

#endif