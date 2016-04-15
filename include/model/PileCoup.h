/**
 *   \file PileCoup.h
 *   \author Aurélien Bertron
 *   \date 21 mai 2012
 *   \brief Modèle Pile Coups
 *
 *   Contient les déclarations du module de pile de coups.
 */

#ifndef PILE_COUP_H
#define PILE_COUP_H

#include "model/Grille.h"
#include "model/Joueur.h"
#include "model/Coups.h"

struct Cellule
{
	Coup * Info;            /**< Pointeur vers coups **/
	struct Cellule * Lien;  /**< Pointeur vers la cellule suivante **/
};

typedef struct Cellule * Pile;

/**
 * Initialise une pile
 * \return Retourne une pile initialisee
*/
Pile creerPile(void);

/*
 * Détermine si la pile est vide
 * \param[in] pPile Une pile
 * \return 1 : pile vide, 0 sinon
*/
int pileVide(Pile pPile);

/*
 * Empile un élément au sommet
 * \param[in] pPile Une pile
 * \param[in] pElem Un élément à ajouter
 * \return La pile modifiee
*/
Pile empiler(Pile pPile, Coup * pElem);

/*
 * Dépile le premier élément de la pile
 * La liste ne doit pas etre vide.
 * \param[in] pPile Une pile
 * \return La pile modifiee
*/
Pile depiler(Pile pPile);

/*
 * Récupère le premier élément de la pile
 * La pile ne doit pas etre vide
 * \param[in] pPile Une pile
 * \return Le premier element de la pile
*/
Coup * sommet(Pile pPile);

/**
 * Détermine la longueur de la pile.
 * \param[in] pile Un strucutre Pile
 * \return Un entier contenant la longueur de la pile.
**/
int longueurPile(Pile pile);


#endif
