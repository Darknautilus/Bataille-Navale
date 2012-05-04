// parametre.h le module parametre d'une partie permet de charger et sauver ces param dans un fichier pour simplifier on ne paramettre
// que les couleurs et noms des bateaux du joueur + le nombre d'instance de chaque bateau (les bateaux de la machine peuvent ou non être paramétrés)...

#ifndef _PARAM_H
#define _PARAM_H
//#include <SDL/SDL.h>
#include <stdio.h>
#include "couleurs.h"
#define K_NBCOULEURS 4
#define K_NBTYPEBATEAUX 4
#define K_LGNOM 25


typedef enum  {remorqueur=2,  porteAvion, sousMarin, cargot} EType;

typedef struct
{
     int mCouleur /*indice dans la table des couleurs*/;
     EType mType;
     char mNom[K_LGNOM];
}     TInfoBateau;

//***************************
/*	N : getCouleur
	D : donne le l'index de la couleur dans la table des couleurs de couleurs.h/.c de la couleur de l'info bateau pB
	E : pB
	S :
	R : le numéro de la couleur
	Prec : -
*/

int getCouleur(const TInfoBateau * pB);

//***************************
/*	N : getType
	D : donne le type de l'info bateau pB
	E : pB
	S :
	R : le numéro du type
	Prec : -
*/

EType getType(const TInfoBateau *pB);


//***************************
/*	N : getNom
	D : donne nom du bateau pB
	E : pB
	S : pNom
	R :
	Prec : -
*/

void getBNom(const TInfoBateau * pB, char pNom[]); //voir tp sur les chaines de caractères dynamique*/


//***************************
/*	N : setInfoBateau
	D : affecte les infos pNom pCouleur et pType à l'info bateau pB
	E :  pNom pCouleur et pType
	S : pB
	R :
	Prec : -
*/
void setInfoBateau (TInfoBateau *pB, char pNom[], int pCouleur , EType pType);



typedef struct
{
    int mNombreInstanceBateaux;
    TInfoBateau * mBateauxDuJoueur; /*tableau dynamique de mNombreInstanceBateaux*K_NBTYPEBATEAUX bateaux du joueur*/
    TInfoBateau * mBateauxMachine; /*tableau dynamique de mNombreInstanceBateaux*K_NBTYPEBATEAUX bateaux de la machine*/
}Tparam;

/* on va supposer que les bateaux du joueur sont numérotés de 0 à mNombreInstanceBateaux*K_NBTYPEBATEAUX -1 et donc que leur numéro sera l'indice dans le tableau
mBateauxDuJoueur
et les bateaux de la machine sont nimérotés de  mNombreInstanceBateaux*K_NBTYPEBATEAUX à (2* mNombreInstanceBateaux*K_NBTYPEBATEAUX) -1 et donc que leur numéro -  mNombreInstanceBateaux*K_NBTYPEBATEAUX
sera l'indice dans le tableau mBateauxMachine*/

//***************************
/*	N : getInfoBateau
	D : donne les information sur le pNum eme bateau des parametres de la partie
	E : pNum , pParam
	S :*
	R :  les informations sur le bateau
	Prec : le pNum eme bateau  existe
*/

TInfoBateau *getInfoBateau(int pNum ,const Tparam * pParam);


//***************************
/*	N : getNBInstances
	D : donne le nombre d'instances de chaque bateau pour un joueur pour les parametres de partie pParam
	E : pParam
	S :
	R : ce nombre
	Prec : -
*/
int getNBInstances (const Tparam * pParam);


//***************************
/*	N : chargerParam
	D : lit les paramètres de la partie dans un descripteur de fichier pDesc
	E :pDesc
	S : pP
	R :
	Prec : pDesc est un descriteur de fichier ouvert en lecture placé sur la lecture des paramètres de la partie
*/


void chargerParam(FILE * pDesc, Tparam *pP);

//***************************
/*	N : memParam
	D : sauve les paramètres de la partie pParam dans un fichier de nom pNom
	E :pNom , pParam
	S :
	R :
	Prec : pDesc est un descriteur de fichier ouvert en écriture
*/

void memParam(const Tparam * pParam, FILE * pDesc);


//***************************
/*	N : newTParam
	D : creer un Tparam pour pNbInstances de chaque bateau pour chacun : remarque devra allouer les tableaux dynamiques
	E :pNbInstances,
	S : pP
	R :
	Prec : -
*/
void newTParam(int pNbInstances , Tparam * pP);
/* question a ce poser les tableaux sont vides qui doit faire les saisies des informations sur les bateaux : la vue, le contrôleur va donc appeler la vue
pour saisir les info sur un bateau puis appeler un fonction du module param pour initialiser le nième bateau de la liste des paramètres =>

*/



//***************************
/*	N : setIemeInfoBateauTParam
	D : COMPLETER
	E  pIdBateau  pNom[] pCouleur  pType
	S : pP
	R :
	Prec : ne peut etre appelé qu'apres newTParam
*/
void setIemeInfoBateauTParam(int pIdBateau , Tparam * pP, const char pNom[], int pCouleur , EType pType);



#endif

