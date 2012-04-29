#ifndef UTILSSDL_H
#define UTILSSDL_H

// Permet d'initialiser tous les modules SDL
SDL_Surface * DemarrerSDL(int width, int height, char * titreFenetre);

void ImageFond(char * cheminImage);

void EffacerEcran(void);

// Arrête tous les modules SDL
void ArreterSDL(void);

// Permet d'écrire du texte blanc avec la police par défaut
void EcrireTexte(char * texte, int taille, int abscisse, int ordonnee);

// Attend un clic gauche de l'utilisateur puis renvoit les coordonnées du clic
void AttendreClic(SDL_Rect * coordClic);

#endif