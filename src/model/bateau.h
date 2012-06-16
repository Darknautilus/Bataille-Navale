/**
 *   \file bateau.h
 *   \author Benoit Sauvere
 *   \date 13 mai 2012
 *   \brief Module Bateau Headers
 *
 *   Contient les d�claration du module Bateau
*/

#ifndef _BATEAU_H
#define _BATEAU_H

#include "grille.h"

#define KTAILLEMAXBAT 5      /**< \brief Taille maximale d'un bateau */
#define KLONGMAXNOMTYPE 20   /**< \brief Longueur maximale du nom d'un type */

/**
 * \enum ETypeBat
 * \brief Types de bateaux
 *
 * D�finit � la fois le type et la taille du bateau
*/
typedef enum {
    VOILIER = 1,
    REMORQUEUR=2,
    CARGOT=3,
    SOUSMARIN=4,
    PORTEAVION=5,
    NONE=0
} ETypeBat;

/**
 * \struct TtypeBat
 * \brief Types de bateaux et noms
 *
 * D�finit le type du bateau et le nom du type (vise � remplacer ETypeBat)
*/
typedef struct
{
    ETypeBat typeBat;
    char * nomType;
}
TtypeBat;

extern const TtypeBat tabTypesBat[KTAILLEMAXBAT+1];

/**
 * \enum ESens
 * \brief Sens du bateau
 *
 * D�finit le sens du bateau dans la grille
*/
typedef enum {
    HORIZONTAL,
    VERTICAL
}
ESens;

typedef struct
{
    ESens sensBat;
    char * libSens;
}
TSensBat;

extern const TSensBat tabSensBat[2];

/**
 * \enum EEtat
 * \brief �tat d'une case de bateau
 * Est utilis� dans un tableau dont le nombre d'�l�ments est �gal � la taille du bateau
*/
typedef enum {INTACT, TOUCHE, COULE} EEtat;

/**
 * \struct TPosition
 * \brief Position du bateau dans la grille
*/
typedef struct
{
	ESens direction;   /**< Sens/Direction du bateau */
	int x;             /**< Num colonne dans la grille (point en haut � gauche du bateau) */
	int y;             /**< Num ligne dans la grille (point en haut � gauche du bateau) */
}
TPosition;

/**
 * \struct TBateau
 * \brief Caract�ristiques du bateau
*/
typedef struct
{
	int idBateau;              /**< Num�ro du bateau (voir param�tres) */
	TPosition position;        /**< Position du bateau dans la grille */
	EEtat etat[KTAILLEMAXBAT]; /**< Tableau d'�tat du bateau, renseigne l'�tat de chaque case du bateau */
    int estPlace;
}
TBateau;

/**
 * Cr�e un bateau.
 * \return Une strucutre Bateau correctement initialis�e et vide.
*/
TBateau * CreerBateau();

/**
 * \brief R�cup�re l'id du bateau
 *
 * \param[in] pBat Le bateau voulu
 * \return Le numero du bateau
*/
int getIdBat(TBateau * pBat);

/**
 * Cette fonction marque une case d'un bateau donn�e comme touch�e.
 * \param bat Le pointeur sur le bateau en question
 * \param posTouch Le rang de la case touch�e (cases de 1 � type).
 *
*/
void toucherBateau(TBateau * bat, int posTouch);

/**
 * Renvoie le nombre de coups necessaires pour couler le bateau (0 si le bateau est coul�).
 * Utile ?
 * \param bat un pointeur sur le bateau en question.
 * \return Une valeur de l'�num�ration EEtat.
*/
int etatBateau(TBateau * bat);

/**
 * V�rifie si le bateau est coul�.
 * \param bat Un pointeur sur une structure TBateau
 * \return 1 si le bateau est coul�, 0 si il est en vie
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
 * \return Un �l�ment de l'enum�ration ESens.
*/
ESens getSensBateau(TBateau *bat);

/**
 * Retourne le type d'un bateau.
 * \param bat Un pointeur sur le bateau en question.
 * \return Un �l�ment de l'enum�ration ETypeBat.
*/
ETypeBat getTypeBateau(TBateau *bat);

/**
 * Configure la position d'un bateau
 * \param[in] pBat Le bateau a configurer
 * \param[in] pSens Sens du bateau
 * \param[in] pAbs Abscisse du bateau
 * \param[in] pOrd Ordonnee du bateau
*/
void setPosBat(TBateau * pBat, ESens pSens, int pAbs, int pOrd);

int estPlacable(TBateau * bat, Grille * grille);

/**
 * Lib�re le bateau en m�moire
 * \param[in] bat Un pointeur sur le bateau
*/
void LibererBateau(TBateau * bat);

#endif
