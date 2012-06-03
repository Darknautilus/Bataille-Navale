#ifndef MENU_H
#define MENU_H

#include "champSaisie.h"
#include "parametre.h"

// Affiche le menu d'accueil
void AfficherMenuAccueil(void);

int AfficherMenuRacine(void);

Tparam * MenuNouvellePartie(void);

Tparam * MenuParam(void);

void EcranGrille(ChampSaisie * champ);

#endif