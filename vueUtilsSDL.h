#ifndef VUE_UTILS_H
#define VUE_UTILS_H

/**
 * \brief Permet d'écrire du texte en blanc et avec la police par défaut
 *
 * \param[in] texte Le texte à écrire
 * \param[in] taille La taille de la police
 * \param[in] positionTexte Coordonnées du texte sur l'ecran
 */
void EcrireTexte(char * texte,int taille, SDL_Rect positionTexte);


/**
 * \brief Permet d'écrire un caractère à l'écran
 *
 * \param[in] car Le caractère à écrire
 * \param[in] taille Taille du texte
 * \param[in] positionChar Coordonnées du caractère dans l'écran
*/
void EcrireCar(char car,int taille, SDL_Rect positionChar);

/**
 * \brief Récupère un événement
 *
 * \param[out] coordClic Coordonnees du clic
 * \param[out] touche Touche pressée
 *
 * Met le programme en pause et attend un clic gauche ou l'appui sur une touche.
 * Si un clic gauche est donné, les coordonnees du clic sont enregistrées et 1 est retourné.
 * Si une touche est pressée, sa valeur est enregistrée et 2 est retourné.
 * Si l'on ne veut utiliser que le clavier ou que la souris, il est possible de mettre l'un des deux paramètres à NULL.
*/
int AttendreEvent(SDL_Rect * coordClic, SDL_keysym * touche);

/*
 * \brief Renvoit le caractere Unicode correspondant à la touche tapée
 *
 * \param[in] touche Touche récupérée avec la fonction AttendreEvent()
 * \return Un caractère
 *
 * Attention, le traitement du retour de cette fonction nécessite Unicode activé.
 * Utiliser SDL_EnableUNICODE(SDL_ENABLE) au début du programme appelant et SDL_EnableUNICODE(SDL_DISABLE) à la fin.
*/
char ToucheChar(SDL_keysym * touche);

/*
 * \brief Renvoit la valeur de la touche tapée
 *
 * \param[in] touche Touche récupérée avec la fonction AttendreEvent()
 * \return La valeur de la touche (géré par SDL)
 *
 * Le retour de cette fonction peut être utilisé pour tester si la touche appuyée est RETURN ou BACKSPACE par exemple,
 * pour les caractères normaux, voir ToucheCar()
*/
SDLKey ToucheSpec(SDL_keysym * touche);

/**
 * \brief Convertit les couleurs
 *
 * \param[in] pCouleur
 * \return Le type de couleur accepté par SDL_FillRect
 *
 * Pour remplir une surface d'une couleur, SDL_FillRect n'accepte que le type Uint32 or, on ne manipule que des SDL_Color.
 * Il est donc nécessaire de réaliser une conversion
*/
Uint32 convertSDL_Color(SDL_Color pCouleur);

/**
 * \brief Efface l'écran
*/
void EffacerEcran(void);

#endif
