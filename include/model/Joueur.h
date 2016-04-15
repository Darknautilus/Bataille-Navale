/**
 *   \file Joueur.h
 *   \author Aurélien Bertron, Benoît Sauvère
 *   \date 18 avril 2012
 *   \brief Modèle Joueur
 *
 *   Contient les déclaration du module Joueur.
 */

#ifndef JOUEUR_H
#define JOUEUR_H

#define KLGNOMJ 25   /**< Taille maximale du nom du nom d'un joueur **/

#include "model/Bateau.h"

/**
 * \enum ETypeBat
 * \brief Types de bateaux
 *
 * DÈfinit ‡ la fois le type et la taille du bateau
*/
typedef enum {HUMAIN,MACHINE,UNDEF} ETypeJoueur;

/**
 * \struct TInfoBateau
 * \brief Contient les informations sur un bateau
 *
 * Ces informations seront stockées dans un tableau (voir Tparam)
*/
typedef struct
{
	ETypeJoueur type;      /** Type de joueur **/
	char nomJ[KLGNOMJ];    /** Nom du joueur **/
	TBateau ** mesBateaux;  /** Tableau dynamique de pointeurs sur TBateaux **/
}Joueur;

/**
 * Initialise un joueur
 * \return Un joueur initialisé
*/
Joueur * creerJoueur(void);

/**
 * Récupère le type d'un joueur
 * \param[in] pJoueur Le joueur voulu
 * \return Le type de pJoueur
*/
int getTypeJoueur(const Joueur * pJoueur);

/**
 * Récupère le nom d'un joueur
 * \param[in] pJoueur Le joueur voulu
 * \return Le nom de pJoueur
*/
char * getNomJoueur(Joueur * pJoueur);

/**
 * Libère le joueur en mémoire
 * \param[in] pJoueur Le joueur à libérer
*/
void libererJoueur(Joueur * pJoueur);


#endif
