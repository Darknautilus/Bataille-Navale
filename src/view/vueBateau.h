#ifndef VUEBATEAU_H_INCLUDED
#define VUEBATEAU_H_INCLUDED

#include "../model/Grille.h"
#include "../model/Bateau.h"

// insère un bateau dans une grille, renvoie NULL si ce n'est pas possible.
// On peut également insérer des bateaux touché ou coulé (pour le chargement d'une partie par ex.)
Grille * insertBateau(Grille * grille, TBateau * bat);


#endif // VUEBATEAU_H_INCLUDED
