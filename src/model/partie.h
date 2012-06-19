#ifndef PARTIE_H
#define PARTIE_H

#include "joueur.h"
#include "parametre.h"
#include "pileCoup.h"
#include "grille.h"

/**
 * \struct TPartie
 * \brief Structure représentant une partie
 *
 * Définis le type Partie.
 * Ce type correspond à une partie de bataille navale.
*/
typedef struct
{
    Joueur *joueur;
    Joueur *machine;
    Tparam *parametres;
    Pile pileCoups;
    Grille *grille;
    Grille *grilleMachine;
    int scorePlayer;
} TPartie;


/**
 * Variable globale contenant les données de la partie.
 * Cette variable contient l'ensemble des données de la partie et
 * peut-être utilisée depuis n"importe quelle partie du programme.
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
 * Cette fonction prépare une structure pour qu'elle soit jouable.
 * \param[in] param Les paramètres à appliquer à la partie
 * \return Un pointeur sur la partie préparée
*/
TPartie* initialiser(Tparam *param);


/**
 * Cette fonction réalise un tir (aussi bien pour la machine que pour le joueur).
 *
 * \param[in] partie La partie concernée.
 * \param[in] cible Les coordonnées où l'on tire.
 * \param[in] estJoueur Booléen indiquant si c'est un coup pour le joueur ou non.
 * \return Retourne le résultat de l'action (1 = touché, 0 = raté)
**/
int jouerUnCoup(TPartie *partie, Coord cible, int estJoueur);

/**
 * Détermine si la partie est finie ou non et indique un éventuel vainqueur.
 * \param[in] partie La partie en question
 * \return 0 = partie toujours en cours, 1 = le joueur à gagné, -1 = la machine à gagné
*/
int partieEstFinie(TPartie *partie);


/**
 * Libère les ressources liées à la partie.
 * \param[in] partie La partie à libérer.
*/
void libererPartie(TPartie *partie);








#endif
