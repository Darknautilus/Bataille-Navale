/**
 *   /file bateau.h
 *   /author Benoit Sauvere
 *   /date 13/05/2012
 *   /brief Module Bateau Headers
 *
 *   Contient les d�claration du module Bateau
*/

#ifndef _BATEAU_H
#define _BATEAU_H

#define KTAILLEMAXBAT 5

typedef enum {VOILIER = 1, REMORQUEUR = 2,  PORTEAVION = 5, SOUSMARIN = 4, CARGOT = 3} ETypeBat;
typedef enum {HORIZONTAL, VERTICAL} ESens;
typedef enum {INTACT, TOUCHE, COULE} EEtat;

typedef struct
{
	ESens direction;
	int x;
	int y; /* position du point en haut gauche du bateau dans la grille de jeu */
}	TPosition;

typedef struct
{
	TPosition position;
 	int idInfoBateau;
	ETypeBat type;
	int *etat; //Un tableau de booleen (1 = touch�, 0 = non touch�)
}	TBateau;

/**
    Cr�er un bateau.
    @param pos La position du bateau
    @param type Le type du bateau
    @return Une strucutre Bateau correctement initialis�e.
*/
TBateau * creerBateau(TPosition pos, ETypeBat type);

/**
    Cette fonction marque une case d'un bateau donn�e comme touch�e.
    @param bat Le pointeur sur le bateau en question
    @param posTouch La postion touch�e.
    @return

*/
void toucherBateau(TBateau * bat, int posTouch);

/**
    Renvoie le nombre de coups necessaires pour couler le bateau (0 si le bateau est coul�).
    @param bat un pointeur sur le bateau en question.
    @return Une valeur de l'�num�ration EEtat.
**/
int etatBateau(TBateau * bat);

/**
    V�rifie si le bateau est coul�.
    @param bat Un pointeur sur une structure TBateau
    @return 1 si le bateau est coul�, 0 si il est en vie
*/
int estCoule(TBateau * bat);

TPosition getPosBateau(TBateau * bat);

/* il faut faire �galemnt des fonctions pour les informations positionnelles direction latitude et logitude=> compl�ter*/
#endif
