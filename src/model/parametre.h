/**
 * \file parametre.h
 * \author Aur�lien Bertron
 * \date 19 mai 2012
 * \brief Header Module Param�tres
 *
 * Le module parametre d'une partie permet de charger et sauver ces param�tres dans un fichier.
*/

#ifndef _PARAM_H
#define _PARAM_H

#include <stdio.h>
#include <stdlib.h>
#include "bateau.h"

#define K_NBTYPEBATEAUX KTAILLEMAXBAT /**< \brief Nombre de types de bateaux */
#define K_LGNOM 25 /**< \brief Longueur maximale du nom du bateau */

/**
 * \struct TInfoBateau
 * \brief Contient les informations sur un bateau
 *
 * Ces informations seront stock�es dans un tableau (voir Tparam)
*/
typedef struct
{
	int couleur;/**< Indice dans la table des couleurs */
	ETypeBat type;/**< Type du bateau */
	char nomBateau[K_LGNOM];/**< Nom du bateau */
}	TInfoBateau;

//***************************
/**
 * \brief R�cup�re la couleur du bateau
 *
 * \param[in] pB Un pointeur sur les informations du bateau
 * \return Le num�ro de la couleur
 *
 * Donne l'index de la couleur de l'info bateau pB dans la table des couleurs de couleurs.h/.c
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
 * \param[out] pNom Une chaine de caract�res contenant le nom
*/

void getBNom(const TInfoBateau * pB, char pNom[]);


//***************************
/**
 * \brief Affecte les infos pNom, pCouleur et pType � l'info bateau pB
 *
 * \param[out] pB Un pointeur sur les informations du bateau
 * \param[in] pNom Le nom du bateau
 * \param[in] pCouleur La couleur du bateau
 * \param[in] pType Le type du bateau
*/
void setInfoBateau (TInfoBateau *pB, char pNom[], int pCouleur , ETypeBat pType);


//***************************
/**
 * \struct Tparam
 * \brief Les param�tres d'une partie
 *
 * Ces param�tres seront ceux �crits dans un fichier.
 * Les noms du joueur et de la machine devront �tre d�plac�s dans la structure Tpartie
*/
typedef struct
{
    int * nombreInstanceBateaux;    /**< Nombre d'instances de chaque type de bateau */
    char nomJoueur[K_LGNOM];        /**< Nom du joueur (� d�placer) */
    char nomMachine[K_LGNOM];       /**< Nom de l'IA (� d�placer) */
    TInfoBateau * bateauxJoueur;    /**< Tableau dynamique des bateaux du joueur */
    TInfoBateau * bateauxMachine;   /**< Tableau dynamique des bateaux de la machine */
}Tparam;

//***************************
/**
 * \brief Constructeur de Tparam
 *
 * \param[in] pNbInstances Nombre d'instances de bateaux pour chaque type
 * \return Des param�tres initialis�s
 *
 * Attention, � appeler avant toute manipulation de param�tres (m�me chargerParam)
 */
Tparam * newTParam(int pNbInstances);

//***************************
/**
 * \brief Donne le nombre d'instances de chaque bateau pour un joueur
 *
 * \param[in] pParam Les param�tres de la partie
 * \return Un pointeur sur le premier �l�ment d'un tableau d'entiers
*/
int *getNBInstances (const Tparam * pParam);

//***************************
/**
 * \brief Donne les informations sur le pNum eme bateau des parametres de la partie
 *
 * \param[in] pNum Le num�ro du bateau
 * \param[in] pParam Les param�tres de la partie
 * \return Les informations du bateau
 *
 * Les id des bateaux vont de 0 � m pour le joueur et de m+1 � n pour la machine
 * Attention, pNum doit correspondre � un bateau existant
 */
TInfoBateau *getInfoBateau(int pNum ,const Tparam * pParam);

//***************************
/**
 * \brief Donne le nombre d'instances d'un type de bateau pour un joueur
 *
 * \param[in] pParam Les param�tres de la partie
 * \param[in] pType Le type de bateau
 * \return Un nombre
*/
int getNbInstancesType (const Tparam * pParam, ETypeBat pType);

//***************************
/**
 * \brief Donne le nombre total de bateaux pour chaque joueur
 *
 * \param[in] pParam Les param�tres de la partie
 * \return Nombre total de bateaux pour chaque joueur
*/
int getNbBat(const Tparam * pParam);





//***************************
/**
 * \brief Lit les param�tres de la partie dans un descripteur de fichier pDesc
 *
 * \param[in,out] pDesc Un descripteur de fichier
 * \param[out] pParam Les param�tres de la partie
 *
 * pDesc doit �tre ouvert en lecture
*/
void chargerParam(FILE * pDesc, Tparam * pParam);

//***************************
/**
 * \brief Sauve les param�tres de la partie pParam dans un fichier
 *
 * \param[in] pParam Les param�tres de la partie
 * \param[in,out] pDesc Un descripteur de fichier
 *
 * pDesc est un descriteur de fichier ouvert en �criture
*/
void memParam(const Tparam * pParam, FILE * pDesc);


//***************************
/**
 * \brief Configure un bateau selon son num�ro
 *
 * \param[in] pIdBateau Le num�ro du bateau voulu
 * \param[out] pP Les param�tres de la partie
 * \param[in] pNom Le nom du bateau
 * \param[in] pCouleur La couleur du bateau
 * \param[in] pType Le type du bateau
*/
void setIemeInfoBateauTParam(int pIdBateau , Tparam * pP, const char pNom[], int pCouleur , ETypeBat pType);



#endif

