#ifndef UTILSSDL_H
#define UTILSSDL_H

/*
    Permet d'initialiser tous les modules SDL
 
    width et height : dimensions de la fenêtre
 
    Dans tout le code, la surface renvoyée par cette fonction peut-être retrouvée avec SDL_GetVideoSurface()
*/
SDL_Surface * DemarrerSDL(int width, int height, char * titreFenetre);

/*
    Charge l'image et l'applique sur toute la surface de l'écran courant
 
    cheminImage doit etre relatif à ce fichier
*/
void ImageFond(char * cheminImage);

/*
    Cette méthode de positionnement peut être améliorée mais il me paraît important que le bouton de retour soit toujours au même endroit
*/
#define KABSRETOUR 10 // Abscisse de l'image de retour
#define KORDRETOUR 550 // Ordonnee de l'image de retour
/*
    Permet d'afficher l'image de retour
    L'image de retour est primordiale lors de la navigation dans les menus.
    Cliquer sur elle permet de revenir à l'écran précédent
*/
void ImageRetour(char * cheminImage);

/*
    Renvoit 1 si la position du clic correspond avec l'image de retour et 0 sinon

    positionClic peut être initialisée avec AttendreClic() ci-dessous
*/
int ClicSurRetour(SDL_Rect * positionClic);

/*
    Permet d'écrire du texte en blanc et avec la police par défaut
    
    texte : le texte à écrire
    taille : la taille de la police
    abscisse et ordonnee : postion du texte sur l'ecran
*/
void EcrireTexte(char * texte, int taille, int abscisse, int ordonnee);

/*
    Met le programme en pause et attend un clic gauche ou l'appui sur une touche.
    Si un clic gauche est donné, les coordonnees du clic sont enregistrées et 1 est retourné.
    Si une touche est pressée, sa valeur est enregistrée et 2 est retourné.
 
    coordClic : coordonnees du clic (attention, les données contenues dans coordClic seront écrasées)
    touche : touche pressée (attention, même recommandation)
 
    Ces deux pointeurs doivent être alloués au début du programme appelant et doivent être libérés à la fin de celui-ci.
    Si l'on ne veut utiliser que le clavier ou que la souris, il est possible de mettre l'un des deux paramètres à NULL.
*/
int AttendreEvent(SDL_Rect * coordClic, SDLKey * touche);


// Efface l'ecran en cours
void EffacerEcran(void);

/*
    Arrête tous les modules SDL
    À ne pas oublier à la fin du programme
*/
void ArreterSDL(void);



#endif