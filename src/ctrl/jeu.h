#ifndef JEU_H
#define JEU_H

#include "../model/parametre.h"
#include "../model/joueur.h"

void jeu(Tparam * pParam);

int menuPlacementChoixBat(void);

int menuPlacementGrille(TBateau * pBat);

int changerSensBat(int pSensBat);

int placementBatValide(Joueur * pJoueur);

void placementAleatBat(Joueur * pJoueur);

#endif