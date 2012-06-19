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
int partie_Score();


/**
 * Cette fonction prépare une structure pour qu'elle soit jouable.
 * \param param Les paramètres à appliquer à la partie
 * \return La partie préparée
*/
TPartie* initialiser(Tparam *param);


/**
 * Cette fonction réalise un tir (aussi bien pour la machine que pour le joueur).
 *
 * \param partie La partie concernée.
 * \param cible Les coordonnées où l'on tire.
 * \param estJoueur Booléen indiquant si c'est un coup pour le joueur ou non.
 * \return Retourne le résultat de l'action (1 = touché, 0 = raté)
**/
int jouerUnCoup(TPartie *partie, Coord cible, int estJoueur);



/**
 * Libère les ressources liées à la partie.
 * \param[in] partie La partie à libérer.
*/
void libererPartie(TPartie *partie);








#endif
