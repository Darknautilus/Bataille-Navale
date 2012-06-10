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
    Pile *pileCoups;
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
















#endif
