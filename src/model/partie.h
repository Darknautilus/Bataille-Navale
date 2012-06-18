#ifndef PARTIE_H
#define PARTIE_H

#include "joueur.h"
#include "parametre.h"
#include "pileCoup.h"
#include "grille.h"

/**
 * \struct TPartie
 * \brief Structure repr�sentant une partie
 *
 * D�finis le type Partie.
 * Ce type correspond � une partie de bataille navale.
*/
typedef struct
{
    Joueur *joueur;
    Joueur *machine;
    Tparam *parametres;
    Pile pileCoups;
    Grille *grille;
    int scorePlayer;
} TPartie;


/**
 * Variable globale contenant les donn�es de la partie.
**/
extern TPartie *globalPartie;



/**
 * Cette fonction pr�pare une structure pour qu'elle soit jouable.
 * \param param Les param�tres � appliquer � la partie
 * \return La partie pr�par�e
*/
TPartie* initialiser(Tparam *param);


/**
 * Cette fonction r�alise un tir (aussi bien pour la machine que pour le joueur).
 *
 * \param partie La partie concern�e.
 * \param cible Les coordonn�es o� l'on tire.
 * \param estJoueur Bool�en indiquant si c'est un coup pour le joueur ou non.
 * \return Retourne le r�sultat de l'action (1 = touch�, 0 = rat�)
**/
int jouerUnCoup(TPartie *partie, Coord cible, int estJoueur);













#endif
