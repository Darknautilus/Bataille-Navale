/**
 * \file parametre.h
 * \author Aurélien Bertron
 * \date 19 mai 2012
 * \brief Header Module Paramètres
 *
 * Le module parametre d'une partie permet de charger et sauver ces paramètres dans un fichier.
*/

#ifndef _PARAM_H
#define _PARAM_H

#include "Bateau.h"
#include "Couleurs.h"

#include <stdio.h>
#include <stdlib.h>

#define K_NBTYPEBATEAUX KTAILLEMAXBAT /**< \brief Nombre de types de bateaux */
#define K_LGNOM 25 /**< \brief Longueur maximale du nom du bateau */

/**
 * \struct TInfoBateau
 * \brief Contient les informations sur un bateau
 *
 * Ces informations seront stockées dans un tableau (voir Tparam)
*/
typedef struct
{
	int couleur;                /**< Indice dans la table des couleurs */
	ETypeBat type;              /**< Type du bateau */
	char nomBateau[K_LGNOM];    /**< Nom du bateau */
}
TInfoBateau;

//***************************

/**
 * \struct Tparam
 * \brief Les paramètres d'une partie
 *
 * Ces paramètres seront ceux écrits dans un fichier.
*/
typedef struct
{
    int * nombreInstanceBateaux;    /**< Tableau d'entiers : Nombre d'instances de chaque type de bateau */
    TInfoBateau * bateauxJoueur;    /**< Tableau dynamique des bateaux du joueur. Il est ‡ noter que les id dÈclarÈ sont fait dans par taille de bateau croissante.*/
    TInfoBateau * bateauxMachine;   /**< Tableau dynamique des bateaux de la machine */
}Tparam;

//***************************
/**
 * \brief RÈcupère la couleur du bateau
 *
 * \param[in] pB Un pointeur sur les informations du bateau
 * \return Le numÈro de la couleur
 *
 * Retourne l'index de la couleur dans le tableau d'anglais.
*/
int getCouleur(const TInfoBateau * pB);

//***************************
/**
 * \brief Donne le type de l'info bateau pB
 *
 * \param[in] pB Un pointeur sur les informations du bateau
 * \return Le type du bateau
*/

ETypeBat getType(const TInfoBateau *pB);


//***************************
/**
 * \brief Donne le nom du bateau
 *
 * \param[in] pB Un pointeur sur les informations du bateau
 * \param[out] pNom Une chaine de caractères contenant le nom
*/

void getBNom(const TInfoBateau * pB, char pNom[]);


//***************************
/**
 * \brief Affecte les infos pNom, pCouleur et pType à l'info bateau pB
 *
 * \param[out] pB Un pointeur sur les informations du bateau
 * \param[in] pNom Le nom du bateau
 * \param[in] pCouleur La couleur du bateau
 * \param[in] pType Le type du bateau
*/
void setInfoBateau (TInfoBateau *pB, char pNom[], int pCouleur , ETypeBat pType);

//***************************
/**
 * \brief Constructeur de Tparam
 *
 * \param[in] pNbInstances Nombre d'instances de bateaux pour chaque type (tableau dynamique d'entiers)
 * \return Des paramètres initialisÈs
 *
 * Attention, ‡ appeler avant toute manipulation de paramètres (même chargerParam)
 */
Tparam * newTParam(int *pNbInstances);

//***************************
/**
 * \brief Donne le nombre d'instances de chaque bateau pour un joueur
 *
 * \param[in] pParam Les paramètres de la partie
 * \return Un pointeur sur le premier élément d'un tableau d'entiers
*/
int *getNBInstances (const Tparam * pParam);

/**
 * Retourne l'id qu'aurait un bateau avec ces caractéristiques
 * \param[in] pTypeBat Le type du bateau
 * \param[in] pNumBatType La position du bateau par rapport aux bateaux du même type
 * \param[in] pParam Les paramètres de la partie (contient les TInfoBateaux
 * \return Le numéro du bateau
*/
int getNumBat(ETypeBat pTypeBat, int pNumBatType, Tparam * pParam);

//***************************
/**
 * \brief Donne les informations sur le pNum eme bateau des parametres de la partie
 *
 * \param[in] pNum Le numéro du bateau
 * \param[in] pParam Les paramètres de la partie
 * \return Les informations du bateau
 *
 * Les id des bateaux vont de 0 à m pour le joueur et de m+1 à n pour la machine
 * Attention, pNum doit correspondre à un bateau existant
 */
TInfoBateau *getInfoBateau(int pNum ,const Tparam * pParam);

//***************************
/**
 * \brief Donne le nombre d'instances d'un type de bateau pour un joueur
 *
 * \param[in] pParam Les paramètres de la partie
 * \param[in] pType Le type de bateau
 * \return Un nombre
*/
int getNbInstancesType (const Tparam * pParam, ETypeBat pType);

//***************************
/**
 * \brief Donne le nombre total de bateaux pour chaque joueur
 *
 * \param[in] pParam Les paramètres de la partie
 * \return Nombre total de bateaux pour chaque joueur
*/
int getNbBat(const Tparam * pParam);

/**
 * Configure le nom de tous les bateaux à "Nom :" et la couleur à Blanc
 * \param[in,out] pParam Les paramètres de la partie
*/
void resetInfoBateau(Tparam * pParam);


//***************************
/**
 * \brief Lit les paramètres de la partie dans un descripteur de fichier pDesc
 *
 * \param[in,out] pDesc Un descripteur de fichier
 * \param[out] pParam Les paramètres de la partie
 *
 * pDesc doit être ouvert en lecture
*/
void chargerParam(FILE * pDesc, Tparam * pParam);

//***************************
/**
 * \brief Sauve les paramètres de la partie pParam dans un fichier
 *
 * \param[in] pParam Les paramètres de la partie
 * \param[in,out] pDesc Un descripteur de fichier
 *
 * pDesc est un descriteur de fichier ouvert en écriture
*/
void memParam(const Tparam * pParam, FILE * pDesc);

int infoBateauValide(const Tparam * pParam);

void libererParam(Tparam * pParam);


//***************************
/**
 * \brief Configure un bateau selon son numÈro
 *
 * \param[in] pIdBateau Le numéro du bateau voulu
 * \param[out] pP Les paramètres de la partie
 * \param[in] pNom Le nom du bateau
 * \param[in] pCouleur La couleur du bateau
 * \param[in] pType Le type du bateau
*/
void setIemeInfoBateauTParam(int pIdBateau , Tparam * pP, const char pNom[], int pCouleur , ETypeBat pType);

//***************************

/**
    Retire nb bateau(x) de la liste d'un type donnÈ.
	\param param La structure parametre ‡ modifier
    \param nb Le nombre de TInfoBateau du type ‡ supprimer
    \param type Le type de bateau ‡ supprimer
**/
void retierInfoBateauxType(Tparam *param, int nb, ETypeBat type);

//***************************

/**
    DÈtruit la strucutre paramËtre ainsi que toute les ressources qu'elle contient.
    \param param Le paramËtre ‡ libÈrer
**/
void libererParam(Tparam *param);


#endif

