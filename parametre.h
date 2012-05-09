// parametre.h le module parametre d'une partie permet de charger et sauver ces param dans un fichier.
// Pour simplifier, on ne paramettre que les couleurs, le nom des bateaux du joueur et le nombre d'instance de chaque bateau.
// Les bateaux de la machine peuvent ou non être paramétrés.

#ifndef _PARAM_H
#define _PARAM_H

#include <stdio.h>
#include "couleurs.h"
#include "bateau.h"

#define K_NBTYPEBATEAUX KTAILLEMAXBAT-1
#define K_LGNOM 25

typedef struct
{
	int couleur /*indice dans la table des couleurs*/;
	ETypeBat type;
    int idInfoBateau;
	char nomBateau[K_LGNOM];
}	TInfoBateau;

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

ETypeBat getType(const TInfoBateau *pB);


//***************************
/*	N : getNom
	D : donne nom du bateau pB
	E : pB
	S : pNom
	R :
	Prec : -
*/

void getBNom(const TInfoBateau * pB, char pNom[]);


//***************************
/*	N : setInfoBateau
	D : affecte les infos pNom pCouleur et pType à l'info bateau pB
	E :  pNom pCouleur et pType
	S : pB
	R :
	Prec : -
*/
void setInfoBateau (TInfoBateau *pB, char pNom[], int pCouleur , ETypeBat pType);



typedef struct
{
    int nombreInstanceBateaux[K_NBTYPEBATEAUX];
    char nomJoueur[K_LGNOM];
    char nomMachine[K_LGNOM];
    TInfoBateau * bateauxJoueur; /*tableau dynamique des bateaux du joueur*/
    TInfoBateau * bateauxMachine; /*tableau dynamique des bateaux de la machine*/
}Tparam;


//***************************
/*	N : getNBInstances
 D : donne le nombre d'instances de chaque bateau pour un joueur pour les parametres de partie pParam
 E : pParam
 S :
 R : ce nombre
 Prec : -
 */
int *getNBInstances (const Tparam * pParam);

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
	D : donne le nombre d'instances d'un type de bateau pour un joueur pour les parametres de partie pParam
	E : pParam
	S :
	R : ce nombre
	Prec : -
*/
int getNbInstances (const Tparam * pParam);


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


//***************************
/*	N : setIemeInfoBateauTParam
	D : COMPLETER
	E  pIdBateau  pNom[] pCouleur  pType
	S : pP
	R :
	Prec : ne peut etre appelé qu'apres newTParam
*/
void setIemeInfoBateauTParam(int pIdBateau , Tparam * pP, const char pNom[], int pCouleur , ETypeBat pType);



#endif

