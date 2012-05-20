/**
 *   \file bateau.h
 *   \author Benoit Sauvere
 *   \date 13 mai 2012
 *   \brief Module Bateau Headers
 *
 *   Contient les déclaration du module Bateau
*/

#ifndef _BATEAU_H
#define _BATEAU_H

#define KTAILLEMAXBAT 5 /**< \brief Taille maximale d'un bateau */

/**
 * \enum ETypeBat
 * \brief Types de bateaux
 *
 * Définit à la fois le type et la taille du bateau
*/
typedef enum {
    VOILIER = 1,
    REMORQUEUR,
    CARGOT,
    SOUSMARIN,
    PORTEAVION
} ETypeBat;

/**
 * \enum ESens
 * \brief Sens du bateau
 *
 * Définit le sens du bateau dans la grille
*/
typedef enum {
    HORIZONTAL,
    VERTICAL
} ESens;

/**
 * \enum EEtat
 * \brief État d'une case de bateau
 * Est utilisé dans un tableau dont le nombre d'éléments est égal à la taille du bateau
*/
typedef enum {INTACT, TOUCHE, COULE} EEtat;

/**
 * \struct TPosition
 * \brief Position du bateau dans la grille
*/
typedef struct
{
	ESens direction; /**< Sens/Direction du bateau */
	int x; /**< Num colonne dans la grille (point en haut à gauche du bateau) */
	int y; /**< Num ligne dans la grille (point en haut à gauche du bateau) */
}	TPosition;

/**
 * \struct TBateau
 * \brief Caractéristiques du bateau
*/
typedef struct
{
	int idBateau; /**< Numéro du bateau (voir paramètres) */
	TPosition position; /**< Position du bateau dans la grille */
	ETypeBat type; /**< Type/Taille du bateau */
	EEtat etat[KTAILLEMAXBAT]; /**< Tableau d'état du bateau, renseigne l'état de chaque case du bateau */
}	TBateau;

/**
 * Créer un bateau.
 * \param pos La position du bateau
 * \param type Le type du bateau
 * \return Une strucutre Bateau correctement initialisée.
*/
TBateau * creerBateau(TPosition pos, ETypeBat type);

/**
 * \brief Récupère l'id du bateau
 *
 * \param[in] pBat Le bateau voulu
 * \return Le numero du bateau
*/
int getIdBat(TBateau * pBat);

/**
 * Cette fonction marque une case d'un bateau donnÈe comme touchÈe.
 * \param bat Le pointeur sur le bateau en question
 * \param posTouch La postion touchÈe.
 *
*/
void toucherBateau(TBateau * bat, int posTouch);

/**
 * Renvoie le nombre de coups necessaires pour couler le bateau (0 si le bateau est coulÈ).
 * Utile ?
 * \param bat un pointeur sur le bateau en question.
 * \return Une valeur de l'ÈnumÈration EEtat.
*/
int etatBateau(TBateau * bat);

/**
 * Vérifie si le bateau est coulé.
 * \param bat Un pointeur sur une structure TBateau
 * \return 1 si le bateau est coulÈ, 0 si il est en vie
*/
int estCoule(TBateau * bat);

/**
 * Retourne une structure contenant la position d'un bateau.
 * \param bat Un pointeur sur le bateau en question.
 * \return Une structure de type TPosition.
*/
TPosition getPosBateau(TBateau * bat);

/**
 * Retourne la postion en X (latitude) d'un bateau.
 * \param bat Un pointeur sur le bateau en question.
 * \return un entier.
*/
int getPosXBateau(TBateau *bat);

/**
 * Retourne la postion en Y (longitutde) d'un bateau.
 * \param bat Un pointeur sur le bateau en question.
 * \return un entier.
*/
int getPosYBateau(TBateau *bat);

/**
 * Retourne le sens d'un bateau.
 * \param bat Un pointeur sur le bateau en question.
 * \return Un ÈlÈment de l'enumÈration ESens.
*/
ESens getSensBateau(TBateau *bat);

#endif
