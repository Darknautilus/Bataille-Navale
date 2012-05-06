#ifndef CHAMP_SAISIE_H
#define CHAMP_SAISIE_H

#define KLARGCHAR 13 // Largeur caractère
#define KESP_VERT 5 // Espacement du texte avec le bord du champ
#define KESP_HORI 5

// Couleur du texte (format RGB)
#define KCOULTXT_R 0
#define KCOULTXT_G 0
#define KCOULTXT_B 0

// Couleur du champ (mode normal)
#define KCOULNORM_R 200
#define KCOULNORM_G 207
#define KCOULNORM_B 212

// Couleur du champ (mode édition)
#define KCOULEDIT_R 255
#define KCOULEDIT_G 255
#define KCOULEDIT_B 255

/*
    Ce module implémente la gestion du champ de saisie. Il permet à l'utilisateur de saisir une chaine de caractères

    Un champ de saisie est une structure simple mais efficace qui ne doit être manipulée que sous forme de pointeur.
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