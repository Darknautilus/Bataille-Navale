#ifndef MENU_H
#define MENU_H

#include "../model/champSaisie.h"
#include "../model/parametre.h"

// Affiche le menu d'accueil
void AfficherMenuAccueil(void);

int AfficherMenuRacine(void);

Tparam * MenuNouvellePartie(void);

Tparam * MenuParam(void);

void EcranGrille(ChampSaisie * champ);

#endif
