/**
 * \file jeu.h
 * \author Aurelien Bertron
 * \date 28 avril 2012
 * \brief Header Controleur ecrans jeu
 *
 * Contient les headers des controleurs des ecrans de jeu
 */

#ifndef JEU_H
#define JEU_H

#include "../model/parametre.h"
#include "../model/joueur.h"

/**
 * \param[in] pParam Les parametres de la partie, definis a l'ecran des parametres
 * Initialise la partie et gere l'enchainement des ecrans de jeu
*/
void jeu(Tparam * pParam);

/**
 * \return 1 si la partie est prete et 0 sinon
 * Premier ecran du placement des bateaux avec liste des bateaux
*/
int menuPlacementChoixBat(void);

/**
 * \param[in,out] pBat Le bateau a placer
 * \return 1 si le bateau est bien place et 0 sinon
 * Affiche la grille pour placer le bateau pBat
*/
int menuPlacementGrille(TBateau * pBat);

int ecranJeu(void);


int changerSensBat(int pSensBat);

int placementBatValide(Joueur * pJoueur);

void placementAleatBat(Joueur * pJoueur);

#endif