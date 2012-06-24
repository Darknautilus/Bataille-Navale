/**
 *   \file partie.h
 *   \author Benoit Sauvere
 *   \date 19 juin 2012
 *   \brief Module Partie
 *
 *   Contient les dÈclarations du module de gestion de la partie.
*/


#ifndef PARTIE_H
#define PARTIE_H

#include "Joueur.h"
#include "Parametre.h"
#include "PileCoup.h"
#include "Grille.h"

/**
 * \struct TPartie
 * \brief Structure reprÈsentant une partie
 *
 * DÈfinis le type Partie.
 * Ce type correspond ‡ une partie de bataille navale.
*/
typedef struct
{
    Joueur *joueur; /**< Joueur humain */
    Joueur *machine; /**< Joueur IA */
    Tparam *parametres; /**< Paramètres de la partie */
    Pile pileCoups; /**< Pile de coups */
    Grille *grille; /**< Grille de l'humain */
    Grille *grilleMachine; /**< Grille de l'IA */
    int scorePlayer; /**< Score du joueur */
} TPartie;


/**
 * Variable globale contenant les données de la partie.
 * Cette variable contient l'ensemble des données de la partie et
 * peut-être utilisée depuis n'importe quelle partie du programme.
**/
extern TPartie *globalPartie;

/**
 * Getters de la structure TPartie
*/
Joueur * partie_JHumain();
Joueur * partie_JMachine();
Tparam * partie_Param();
Pile partie_PileCoups();
Grille * partie_Grille();
Grille * partie_GrilleMachine();
int partie_Score();


/**
 * Cette fonction prÈpare une structure pour qu'elle soit jouable.
 * \param[in] param Les paramËtres ‡ appliquer ‡ la partie
 * \return Un pointeur sur la partie prÈparÈe
*/
TPartie* initialiser(Tparam *param);


/**
 * Cette fonction rÈalise un tir (aussi bien pour la machine que pour le joueur).
 *
 * \param[in] partie La partie concernÈe.
 * \param[in] cible Les coordonnÈes o˘ l'on tire.
 * \param[in] estJoueur BoolÈen indiquant si c'est un coup pour le joueur ou non.
 * \return Retourne le rÈsultat de l'action (1 = touchÈ, 0 = ratÈ)
**/
int jouerUnCoup(TPartie *partie, Coord cible, int estJoueur);

/**
 * DÈtermine si la partie est finie ou non et indique un Èventuel vainqueur.
 * \param[in] partie La partie en question
 * \return 0 = partie toujours en cours, 1 = le joueur ‡ gagnÈ, -1 = la machine ‡ gagnÈ
*/
int partieEstFinie(TPartie *partie);

/**
 * Annule le dernier coups jouÈ (aussi bien par la machine que par le joueur).
 *
 * \param[out] partie La partie dans laquelle on veux annuler le dernier coups.
 *
*/
void annulerDernierCoup(TPartie *partie);

/**
 * LibËre les ressources liÈes ‡ la partie.
 * \param[in] partie La partie ‡ libÈrer.
*/
void libererPartie(TPartie *partie);

#endif
