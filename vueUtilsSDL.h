#ifndef VUE_UTILS_H
#define VUE_UTILS_H

/*
 Charge l'image et l'applique sur toute la surface de l'écran courant
 
 cheminImage doit etre relatif à ce fichier
 */
void ImageFond(char * cheminImage);

/*
 Permet d'afficher l'image de retour
 L'image de retour est primordiale lors de la navigation dans les menus.
 Cliquer sur elle permet de revenir à l'écran précédent
 */
void ImageRetour(char * cheminImage);

void AfficherImage(char * cheminImage, SDL_Rect positionImage);

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
int AttendreEvent(SDL_Rect * coordClic, SDL_keysym * touche);

// Efface l'ecran en cours
void EffacerEcran(void);

#endif