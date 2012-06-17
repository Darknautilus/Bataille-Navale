#ifndef JEU_H
#define JEU_H

#include "../model/parametre.h"

void jeu(Tparam * pParam);

int menuPlacementChoixBat(void);

int menuPlacementGrille(TBateau * pBat);

int changerSensBat(int pSensBat);

int placementBatValide(void);

#endif