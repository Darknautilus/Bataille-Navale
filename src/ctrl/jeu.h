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

#include "../model/Parametre.h"
#include "../model/Joueur.h"

/**
 * \param[in] pParam Les parametres de la partie, definis a l'ecran des parametres
 * \return -1 si la machine a gagne, 1 si l'humain a gagné et 0 sinon
 * Initialise la partie et gere l'enchainement des ecrans de jeu
*/
int jeu(Tparam * pParam);

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

int menuPause(void);

int changerSensBat(int pSensBat);

int placementBatValide(Joueur * pJoueur);

void placementAleatBat(Joueur * pJoueur, Grille * pGrille);

Coord coordAleat(Grille * pGrille);

#endif