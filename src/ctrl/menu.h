/**
 * \file menu.h
 * \author Aurelien Bertron
 * \date 28 avril 2012
 * \brief Header Controleur ecrans menu
 *
 * Contient les headers des controleurs des ecrans de menu
*/

#ifndef MENU_H
#define MENU_H

#include "../model/champSaisie.h"
#include "../model/parametre.h"

/**
 * Affiche le menu de presentation
*/
void afficherMenuAccueil(void);

/**
 * \return Le choix du menu a charger
 * Affiche le menu de choix. L'utilisateur a le choix entre plusieurs actions comme debuter une nouvelle partie, afficher les meilleurs scores, etc.
*/
int afficherMenuRacine(void);

/**
 * \param[in,out] parametre Les parametres a modifier
 * \return 1 si la partie peut etre lancee et 0 si l'on doit retourner au menu precedent.
 * Affiche le premier menu de saisie des parametres de la partie, avec la possibilite de charger des parametres
*/
int menuNouvellePartie(Tparam * parametre);

/**
 * \param[in,out] parametre Les parametres a modifier
 * Affiche le second menu de saisie des parametres, choix des noms et des couleurs des bateaux
*/
void menuParam(Tparam * parametre);

#endif
