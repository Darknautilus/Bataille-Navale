// bateau.h le module bateau d�finit les couleurs et type et autre info des bateaux
#ifndef _BATEAU_H
#define _BATEAU_H



typedef enum  {SENS_HORIZONTAL, SENS_VERTICAL} ESens;

typedef struct
{
    ESens direction;
    int abscisse;
    char ordonnee; /* en fait position dans la grille de jeu du point en haut � gauche */
}   TPosition;


typedef struct
{
    TPosition coordonnees;
    int idInfoBateau;
    //completer par exemple avec des informations sur l'etat du bateau
}   TBateau;

/* il faut faire �galemnt des fonctions pour les informations positionnelles direction latitude et logitude=> compl�ter*/
#endif