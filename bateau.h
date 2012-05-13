// bateau.h le module bateau définit les couleurs et type et autre info des bateaux
#ifndef _BATEAU_H
#define _BATEAU_H

#define KTAILLEMAXBAT 5

typedef enum {VOILIER = 1, REMORQUEUR,  PORTEAVION, SOUSMARIN, CARGOT} ETypeBat;
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
	int etat[KTAILLEMAXBAT];
}	TBateau;

/**
    Créer un bateau.
    @param pos La position du bateau
    @param type Le type du bateau
    @return Une strucutre Bateau correctement initialisée.
*/
TBateau * creerBateau(TPosition pos, ETypeBat type);

/**
    Cette fonction marque une case d'un bateau donnée comme touchée.
    @param bat Le pointeur sur le bateau en question
    @param posTouch La postion touchée.
    @return

*/
void toucherBateau(TBateau * bat, int posTouch);

// renvoie le nombre de coups necessaires pour couler le bateau (0 si le bateau est coulé)
int etatBateau(TBateau * bat);

/**
    Vérifie si le bateau est coulé.
    @param bat Un pointeur sur une structure TBateau
    @return 1 si le bateau est coulé, 0 si il est en vie
*/
int estCoule(TBateau * bat);

TPosition getPosBateau(TBateau * bat);

/* il faut faire égalemnt des fonctions pour les informations positionnelles direction latitude et logitude=> compléter*/
#endif
