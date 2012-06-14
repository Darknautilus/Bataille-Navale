#ifndef MENU_H
#define MENU_H

#include "../model/champSaisie.h"
#include "../model/parametre.h"

// Affiche le menu d'accueil
void AfficherMenuAccueil(void);

int AfficherMenuRacine(void);

int MenuNouvellePartie(Tparam * parametre);

void MenuParam(Tparam * parametre);

#endif
