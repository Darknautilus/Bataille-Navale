// parametre.h le module parametre d'une partie permet de charger et sauver ces param dans un fichier.
// Pour simplifier, on ne paramettre que les couleurs, le nom des bateaux du joueur et le nombre d'instance de chaque bateau.
// Les bateaux de la machine peuvent ou non Ítre paramÈtrÈs.

#ifndef _PARAM_H
#define _PARAM_H

#include <stdio.h>
#include "couleurs.h"
#include "bateau.h"

#define K_NBTYPEBATEAUX KTAILLEMAXBAT
#define K_LGNOM 25

typedef struct
{
	int couleur /*indice dans la table des couleurs*/;
	ETypeBat type;
	char nomBateau[K_LGNOM];
}	TInfoBateau;

//***************************
/*	N : getCouleur
	D : donne le l'index de la couleur dans la table des couleurs de couleurs.h/.c de la couleur de l'info bateau pB
	E : pB
	S :
	R : le numÈro de la couleur
	Prec : -
*/

int getCouleur(const TInfoBateau * pB);

//***************************
/*	N : getType
	D : donne le type de l'info bateau pB
	E : pB
	S :
	R : le numÈro du type
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
    int * nombreInstanceBateaux;
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

/**
 * \brief Donne le nombre total de bateaux pour chaque joueur
 *
 * \param[in] pParam
 * \return Nombre total de bateaux pour chaque joueur
*/
int nbBat(const Tparam * pParam);

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
int getNbInstancesType (const Tparam * pParam, ETypeBat pType);


//***************************
/*	N : chargerParam
	D : lit les paramËtres de la partie dans un descripteur de fichier pDesc
	E :pDesc
	S : pP
	R :
	Prec : pDesc est un descriteur de fichier ouvert en lecture placÈ sur la lecture des paramËtres de la partie
*/


void chargerParam(FILE * pDesc, Tparam * pParam);

//***************************
/*	N : memParam
	D : sauve les paramËtres de la partie pParam dans un fichier de nom pNom
	E :pNom , pParam
	S :
	R :
	Prec : pDesc est un descriteur de fichier ouvert en Ècriture
*/

void memParam(const Tparam * pParam, FILE * pDesc);


//***************************
/*	N : newTParam
	D : creer un Tparam pour pNbInstances de chaque bateau pour chaque type : remarque devra allouer les tableaux dynamiques
	E :pNbInstances,
	S :
	R : un paramètre initialisé
	Prec : -
*/
Tparam * newTParam(int pNbInstances);


//***************************
/*	N : setIemeInfoBateauTParam
	D : COMPLETER
	E  pIdBateau  pNom[] pCouleur  pType
	S : pP
	R :
	Prec : ne peut etre appelÈ qu'apres newTParam
*/
void setIemeInfoBateauTParam(int pIdBateau , Tparam * pP, const char pNom[], int pCouleur , ETypeBat pType);



#endif

