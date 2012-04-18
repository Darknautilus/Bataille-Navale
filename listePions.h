// listePion.h ce module
#ifndef _LPION_H
#define _LPION_H
#include "bateau.h"
#define K_NBPIONCHAQUETYPE 2

typedef struct { int contenu [K_NBCOULEURS][K_NBFORMES];}TlistePions;

//***************************
/*	N : creerVide
	D : cree une liste vide de pions
	E :
	S :
	R : liste de pions
	Prec : -
*/

TlistePions creerVide(void);

//***************************
/*	N : creerPioche
	D : cree une liste de pions avec tous les pions (pioche initiale)
	E :
	S :
	R : liste de pions
	Prec : -
*/

TlistePions creerPioche(void);



//***************************
/*	N : addPion
	D : ajoute le pion pP à la liste pL
	E : pP pL
	S : pL
	R : la nouvelle liste
	Prec : -
*/

TlistePions * addPion(Tpion pP, TlistePions * pL);

//***************************
/*	N : remPion
	D : supprime le pion pP à la liste pL
	E : pP pL
	S : pL
	R : la nouvelle liste
	Prec : le pion est dans la liste
*/

TlistePions * remPion(Tpion pP, TlistePions * pL);

//***************************
/*	N : existePion
	D : teste si le pion pP est dans la liste pL
	E : pP pL
	S :
	R : est présent ou pas
	Prec :
*/

int existePion(Tpion pP, TlistePions * pL);

//***************************
/*	N : piocher
	D : pioche pNbPions ou le nombre de pions restant dans la pioche dans la pioche pLPioche et les met dans pLJoueur
	E :pLPioche pLJoueur pNbPions
	S : pLPioche pLJoueur
	R : _
	Prec :  pNbPions > 0 et pioche non vide
*/

void piocher(TlistePions * pLPioche, TlistePions * pLJoueur, int pNbPions);


//***************************
/*	N : estVide
	D : teste si la liste est vide
	E :pLP
	S :
	R : est présent ou pas
	Prec :
*/

int estVide(TlistePions * pL);


#endif
