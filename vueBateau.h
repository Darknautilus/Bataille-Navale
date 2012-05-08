#ifndef VUEBATEAU_H_INCLUDED
#define VUEBATEAU_H_INCLUDED

#include "grille.h"
#include "bateau.h"

/*
    SetVal

    Insère un élément dans la grille

    La grille n'accepte que 0, 1, 2 et 3, la grille doit être initialisée
*/
Grille * InsertBateau(Grille * grille, TBateau * bat);


#endif // VUEBATEAU_H_INCLUDED
