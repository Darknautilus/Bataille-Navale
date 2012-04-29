#ifndef UTILSSDL_H
#define UTILSSDL_H

void EffacerEcran(SDL_Surface * ecran);

// Permet d'initialiser tous les modules SDL
SDL_Surface * DemarrerSDL(int width, int height, char * titreFenetre);

// Arrête tous les modules SDL
void ArreterSDL();

// Permet d'écrire du texte blanc avec la police par défaut
void EcrireTexte(char * texte, int taille, int abscisse, int ordonnee);

#endif