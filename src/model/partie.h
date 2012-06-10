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
    Pile *pileCoups;
    Grille *grille;
    int scorePlayer;
} TPartie;


/**
 * Variable globale contenant les données de la partie.
**/
extern TPartie *globalPartie;



/**
 * Cette fonction prépare une structure pour qu'elle soit jouable.
 * \param param Les paramètres à appliquer à la partie
 * \return La partie préparée
*/
TPartie* initialiser(Tparam *param);
















#endif
