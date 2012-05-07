// bateau.h le module bateau définit les couleurs et type et autre info des bateaux
#ifndef _BATEAU_H
#define _BATEAU_H

typedef enum  {SENS_HORIZONTAL, SENS_VERTICAL} ESens;

typedef struct
{
	ESens direction;
	int abscisse;
	char ordonnee; /* position du point en haut gauche du bateau dans la grille de jeu */
}	TPosition;

typedef struct
{
	TPosition coordonnees;
	int idInfoBateau;
	int taille;
	int etat[5];
	//completer par exemple avec des informations sur l'etat du bateau
}	TBateau;

/* il faut faire égalemnt des fonctions pour les informations positionnelles direction latitude et logitude=> compléter*/
#endif
