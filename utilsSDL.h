#ifndef UTILSSDL_H
#define UTILSSDL_H

/*
    Permet d'initialiser tous les modules SDL
 
    width et height : dimensions de la fenêtre
 
    Dans tout le code, la surface renvoyée par cette fonction peut-être retrouvée avec SDL_GetVideoSurface()
*/
SDL_Surface * DemarrerSDL(int width, int height, char * titreFenetre);

/*
 Cette méthode de positionnement peut être améliorée mais il me paraît important que le bouton de retour soit toujours au même endroit
 */
#define KABSRETOUR 10 // Abscisse de l'image de retour
#define KORDRETOUR 550 // Ordonnee de l'image de retour
/*
    Renvoit 1 si la position du clic correspond avec l'image de retour et 0 sinon

    positionClic peut être initialisée avec AttendreClic() ci-dessous
*/
int ClicSurRetour(SDL_Rect * positionClic);

/*
    Arrête tous les modules SDL
    À ne pas oublier à la fin du programme
*/
void ArreterSDL(void);



#endif