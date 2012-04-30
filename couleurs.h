#ifndef _COULEURS_H
#define _COULEURS_H

#define KCOULEURS_NBCOULMAX 7
#define KCOULEURS_LGNOMCOUL 10

typedef enum {
    /*  dark colors     */
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    /*  light colors    */
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
} COLORS;

typedef
	struct
	{
		char lettre;
		char nom[KCOULEURS_LGNOMCOUL+1];
		COLORS  num;
	}
Couleur;

//   mettre une precondition lettre existe retourne la couleur associ�e � la lettre
Couleur lettreToCouleur (char pLettre);
//   mettre une precondition ...[pI] d�fini
//retourne la couleur � l'indice pI dans le tableau des couleurs  tableCouleurs
Couleur getCouleurFromNum (int pI);

// fonction d'acc�s � chacun des champs de la structure couleur
COLORS getColor (Couleur pCouleur);
char getChar (Couleur pCouleur);
void getNom (Couleur pCouleur, char pNom[]);

#endif

