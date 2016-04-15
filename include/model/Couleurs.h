/**
 *   \file Couleurs.h
 *   \author Aurélien Bertron, Benoît Sauvère
 *   \date 18 avril 2012
 *   \brief Modèle Couleurs
 *
 *   Contient les déclaration du module Couleurs
*/

#ifndef _COULEURS_H
#define _COULEURS_H

#include "view/IncludeSDL.h"

#define KCOULEURS_NBCOULMAX 8
#define KCOULEURS_LGNOMCOUL 10

typedef
	struct
	{
		char lettre;
		char nom[KCOULEURS_LGNOMCOUL+1];
		SDL_Color rgb;
	}
Couleur;

extern const Couleur tableCouleurs[KCOULEURS_NBCOULMAX];

/**
 * \return Le nombre de couleurs gérées
*/
int getNbCouleurs (void);

/**
 Retourne la couleur correspondant à la lettre entrée.
 pLettre doit exister dans le tableau de couleurs.

 \param[in] pLettre La lettre de la couleur
 \return La couleur recherchée
*/
Couleur lettreToCouleur (char pLettre);

/**
    Retourne la couleur associée à l'indice pI dans le tableau des couleurs.
    Le tableau doit avoir au moins pI+1 éléments.
	\param[in] pI L'indice de la couleur
	\return La couleur recherchée
*/
Couleur getCouleurFromNum (int pI);

/**
 * Fonction d'accès au champ rgb de la structure couleur.
*/
SDL_Color getColor (Couleur pCouleur);
/**
 * Fonction d'accès au champ lettre de la structure couleur.
 */
char getChar (Couleur pCouleur);
/**
 * Fonction d'accès au champ nom de la structure couleur.
 */
void getNom (Couleur pCouleur, char pNom[]);

/**
    Recupère l'index d'une couleur dans le tableau des coueleurs depuis la structure color.
    \param color La couleur en question
    \return L'index de la couleur dans le tableau des couleurs
*/
int getNumFromColor(Couleur color);

#endif
