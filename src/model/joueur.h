/**
 *   \file Joueur.h
 *   \author Aur�lien Bertron
 *   \date 18 avril 2012 
 *   \brief Module Joueur Headers
 *
 *   Contient les d�claration du module Joueur
 */

#ifndef JOUEUR_H
#define JOUEUR_H

#define KLGNOMJ 25

#include "Bateau.h"

/**
 * \enum ETypeBat
 * \brief Types de bateaux
 *
 * D�finit � la fois le type et la taille du bateau
*/
typedef enum {HUMAIN,MACHINE,UNDEF} ETypeJoueur;

/**
 * \struct TInfoBateau
 * \brief Contient les informations sur un bateau
 *
 * Ces informations seront stock�es dans un tableau (voir Tparam)
*/
typedef struct
{
	ETypeJoueur type;      /** Type de joueur **/
	char nomJ[KLGNOMJ];    /** Nom du joueur **/
	TBateau ** mesBateaux;  /** Tableau dynamique de pointeurs sur TBateaux **/
}Joueur;

/**
 * Initialise un joueur
 * \return Un joueur initialis�
*/
Joueur * CreerJoueur(void);

/**
 * R�cup�re le type d'un joueur
 * \param[in] pJoueur Le joueur voulu
 * \return Le type de pJoueur
*/
int getTypeJoueur(const Joueur * pJoueur);

/**
 * R�cup�re le nom d'un joueur
 * \param[in] pJoueur Le joueur voulu
 * \return Le nom de pJoueur
*/
char * getNomJoueur(Joueur * pJoueur);

/**
 * Lib�re le joueur en m�moire
 * \param[in] pJoueur Le joueur � lib�rer
*/
void LibererJoueur(Joueur * pJoueur);


#endif
