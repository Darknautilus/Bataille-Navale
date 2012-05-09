#ifndef VUEGRILLE_H
#define VUEGRILLE_H

#include "grille.h"

/*
 afficherGrille

 Affiche la grille à l'écran à une abscisse et une ordonnee donnees.

 grille doit être initialisée
 */
void afficherGrille(Grille * grille, int abscisse, int ordonnee);

/*
 updateGrille

 Met à jour l'affichage de la grille

 grille doit être initialisée, noLin et noCol doivent être cohérents avec les dimensions de la grille
 */
void updateGrille(Grille * grille, Coord coord);

/*
    ClicCaseGrille

    Détermine la case qui a été cliquée
*/
Coord ClicCaseGrille(Grille * grille, SDL_Rect * positionClic);

/*
    ClicDansGrille

    Détermine si un clic est sur la grille (1) ou non (0)
*/
int ClicDansGrille(Grille * grille, SDL_Rect * positionClic);


#endif
