#ifndef JOUEUR_H
#define JOUEUR_H

#define KLGNOMJ 25

#include "bateau.h"

/**
 * \enum ETypeBat
 * \brief Types de bateaux
 *
 * DÈfinit ‡ la fois le type et la taille du bateau
*/
typedef enum {HUMAIN,MACHINE,UNDEF} ETypeJoueur;

/**
 * \struct TInfoBateau
 * \brief Contient les informations sur un bateau
 *
 * Ces informations seront stockées dans un tableau (voir Tparam)
*/
typedef struct
{
	ETypeJoueur type;     /** Type de joueur **/
	char nomJ[KLGNOMJ];   /** Nom du joueur **/
	TBateau ** mesBateaux;  /** Tableau dynamique de bateaux **/
}Joueur;


Joueur * CreerJoueur(void);

int getTypeJoueur(const Joueur * pJoueur);

char * getNomJoueur(Joueur * pJoueur);

void LibererJoueur(Joueur * pJoueur);


#endif
