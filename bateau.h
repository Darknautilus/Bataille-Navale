// bateau.h le module bateau d�finit les couleurs et type et autre info des bateaux
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
//	int idInfoBateau;
	ETypeBat type;
	int etat[KTAILLEMAXBAT];
}	TBateau;

// cr�e un bateau
TBateau * creerBateau(TPosition pos, ETypeBat type);

// touche le bateau � un emplacement d�fini
TBateau * toucherBateau(TBateau * bat, int posTouch);

// renvoie le nombre de coups necessaires pour couler le bateau (0 si le bateau est coul�)
int etatBateau(TBateau * bat);

/* il faut faire �galemnt des fonctions pour les informations positionnelles direction latitude et logitude=> compl�ter*/
#endif
