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
    Grille *grilleMachine;
    int scorePlayer;
} TPartie;


/**
 * Variable globale contenant les donn�es de la partie.
 * Cette variable contient l'ensemble des donn�es de la partie et
 * peut-�tre utilis�e depuis n"importe quelle partie du programme.
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
 * Cette fonction pr�pare une structure pour qu'elle soit jouable.
 * \param[in] param Les param�tres � appliquer � la partie
 * \return Un pointeur sur la partie pr�par�e
*/
TPartie* initialiser(Tparam *param);


/**
 * Cette fonction r�alise un tir (aussi bien pour la machine que pour le joueur).
 *
 * \param[in] partie La partie concern�e.
 * \param[in] cible Les coordonn�es o� l'on tire.
 * \param[in] estJoueur Bool�en indiquant si c'est un coup pour le joueur ou non.
 * \return Retourne le r�sultat de l'action (1 = touch�, 0 = rat�)
**/
int jouerUnCoup(TPartie *partie, Coord cible, int estJoueur);

/**
 * D�termine si la partie est finie ou non et indique un �ventuel vainqueur.
 * \param[in] partie La partie en question
 * \return 0 = partie toujours en cours, 1 = le joueur � gagn�, -1 = la machine � gagn�
*/
int partieEstFinie(TPartie *partie);


/**
 * Lib�re les ressources li�es � la partie.
 * \param[in] partie La partie � lib�rer.
*/
void libererPartie(TPartie *partie);








#endif
