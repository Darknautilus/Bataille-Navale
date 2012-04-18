// pion.h le module pion définit les couleurs et formes de chaque pions
#ifndef _PION_H
#define _PION_H
#define K_NBCOULEURS 4
#define K_LGNOM 25

typedef enum couleur {couleur1, couleur2 ,couleur3, couleur4} ECouleurs;
typedef enum type {remorqueur=2,  porteAvion, sousMarin, cargot} EType;


typedef struct { ECouleurs mCouleur; EType mType; char mNom[K_LGNOM]; int mIdentifiant};

//***************************
/*	N : getCouleur
	D : donne le numéro de la couleur du bateau pB
	E : pB
	S :
	R : le numéro de la couleur
	Prec : -
*/

ECouleurs getCouleur(Tbateau pB);

//***************************
/*	N : getForme
	D : donne le numéro de la forme du bateau pB
	E : pB
	S :
	R : le numéro du type
	Prec : -
*/

EType getForme(Tpion pB);


//***************************
/*	N : getForme
	D : donne le numéro de la forme du bateau pB
	E : pB
	S :
	R : le numéro du bateau
	Prec : -
*/

EType getIdentifiant(Tpion pB);

#endif
