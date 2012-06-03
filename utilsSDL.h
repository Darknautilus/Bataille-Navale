#ifndef UTILSSDL_H
#define UTILSSDL_H

/*
    Permet d'initialiser tous les modules SDL
 
    width et height : dimensions de la fenêtre
 
    Dans tout le code, la surface renvoyée par cette fonction peut-être retrouvée avec SDL_GetVideoSurface()
*/
SDL_Surface * DemarrerSDL(int width, int height, char * titreFenetre);

/*
    Arrête tous les modules SDL
    À ne pas oublier à la fin du programme
*/
void ArreterSDL(void);



#endif