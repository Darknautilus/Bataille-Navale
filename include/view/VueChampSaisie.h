/**
 * \file VueChampSaisie.h
 * \author Aurélien Bertron
 * \date 29 avril 2012
 * \brief Vue Champ Saisies
 *
 *   Contient les en-têtes des fonctions d'entrée/sortie du module de champs de saisie.
 *   Ce module implémente la gestion du champ de saisie. Il permet à l'utilisateur de saisir une chaine de caractères.
*/

#ifndef VUE_CHAMP_SAISIE_H
#define VUE_CHAMP_SAISIE_H

#include "view/IncludeSDL.h"

#include "model/ChampSaisie.h"

/**
 * \brief Affiche le champ
 *
 * \param[in] champ
 *
 * Affiche le champ aux coordonnees données lors de la création.
*/
void afficherChamp(ChampSaisie * champ);

/**
 * \brief Passe le champ en mode édition
 *
 * \param[in] champ
 *
 * Passe le champ en mode édition (possibilité d'ajouter des caractères et d'en supprimer).
 * Pour sortir du mode édition, il est necessaire de cliquer hors du champ.
*/
void editerChamp(ChampSaisie * champ);

/**
 * \brief Détermine si le clic est sur le champ
 *
 * \param[in] champ
 * \param[in] positionClic Coordonnées du clic dans l'écran
 *
 * \return 1 si le clic est sur le champ et 0 sinon
*/
int clicSurChamp(ChampSaisie * champ, SDL_Rect * positionClic);

#endif
