#ifndef GRILLE_H
#define GRILLE_H

#define KLARGCASE 40
#define KHAUTEURCASE 40
#define KTAILLEPOLICE 30
#define KESP_VERT 5
#define KESP_HORI 5

typedef int * Ligne;

typedef struct
{
	Ligne * TabLignes;
	int NbLin;
	int NbCol;
	int abscisse;
	int ordonnee;
}
Grille;

/*
 Structure Grille : tableau dynamique à deux dimensions
 Dans le cadre de la bataille navale, on associe à chaque case une valeur correspondant à un état
 */
typedef enum {GRILLE_CASE_VIDE, GRILLE_CASE_BATEAU, GRILLE_CASE_TOUCHE, GRILLE_CASE_COULE } EtatCase;

/*typedef struct
 {
 EtatCase etatCase;
 TBateau bateau;
 }
 CaseGrille;*/

/*
    Cette structure représente les coordonnées dans la grille.
    Il est important de différencier coordonnées dans la grille et coordonnées dans l'écran.
    Dans le cas de la bataille navale, les numéros de ligne sont normalement des lettres mais il n'est pas nécessaire de les traiter comme tels, car tout est transparent pour l'utilisateur (saisie à la souris)
*/
typedef struct
{
	int noLin;
	int noCol;
} Coord;

/*
 CreerGrille

 Retourne une grille initialisee ou NULL en cas d'erreur.

 nbLin et nbCol doivent etre > 0
 */
Grille * CreerGrille(int nbLin, int nbCol);

/*
 Consulter

 Retourne l'element a l'emplacement indique

 ligne et colonne doivent etre coherents avec les dimensions de la matrice
 */
int Consulter(Grille * grille, Coord coord);

/*
    SetVal

    Insère un élément dans la grille

    La grille n'accepte que 0, 1, 2 et 3, la grille doit être initialisée
*/
Grille * SetVal(Grille * grille, Coord coord, int valEnt);

/*
    Effacer

    Efface la grille en la remplissant de 0

    La grille doit être initialisée
*/
Grille * EffacerGrille(Grille * grille);

/*
    LibererGrille

    Libere la grille en memoire
*/
void LibererGrille(Grille * grille);

#endif
