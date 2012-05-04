#ifndef VUEGRILLE_H
#define VUEGRILLE_H

#include "grille.h"

/*
 afficherGrille
 
 Affiche la grille à l'écran à une abscisse et une ordonnee donnees.
 
 grille doit être initialisée
 */
void afficherGrille(Grille * grille, SDL_Surface * ecran, int abscisse, int ordonnee);

/*
 updateGrille
 
 Met à jour l'affichage de la grille
 
 grille doit être initialisée, noLin et noCol doivent être cohérents avec les dimensions de la grille
 */
void updateGrille(Grille * grille, SDL_Surface * ecran, int noLin, int noCol);

#endif