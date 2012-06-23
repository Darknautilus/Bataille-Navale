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

/**
 * \return L'état de la partie (voir fonction partieEstFinie)
 * Ecran principal de jeu avec affichage des grilles, et gestions des actions du joueur (jouer un coup, annuler, mise en pause)
*/
int ecranJeu(void);

/**
 * \return Le choix de l'utilisateur (1:continuer, 2:sauvegarder, 3:quitter)
 * Affiche le menu de pause
*/
int menuPause(void);

/**
 * \param[in] pSensBat L'indice dans la table des sens de bateaux
 * \return Le sens opposé à celui passé en paramètre (1 pour 0 et 0 pour 1)
 * Inverse le sens d'un bateau
*/
int changerSensBat(int pSensBat);

/**
 * \param[in] pJoueur Un joueur
 * \return 1 si valide et 0 sinon
 * Détermine si tous les bateaux d'un joueur pJoueur sont bien placés
*/
int placementBatValide(Joueur * pJoueur);

/**
 * \param[in,out] pJoueur Un joueur
 * \param[in,out] pGrille La grille où placer les bateaux
 * Place les bateaux d'un joueur pJoueur aléatoirement dans la grille pGrille
*/
void placementAleatBat(Joueur * pJoueur, Grille * pGrille);

/**
 * \param[in] pGrille Une grille
 * \return Les coordonnées déterminées
 * Détermine aléatoirement un couple de coordonnées dans la grille pGrille
*/
Coord coordAleat(Grille * pGrille);

#endif