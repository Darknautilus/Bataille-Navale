#ifndef GRILLE_H
#define GRILLE_H

/*
    Structure Grille : tableau dynamique à deux dimensions
    Dans le cadre de la bataille navale, on associe à chaque case une valeur correspondant à un état
        0 - Case vide (par défaut)
        1 - Morceau bateau
        2 - bateau touché
        3 - bateau coulé
*/

/*typedef struct
{
    int etatCase;
    TBateau bateau;
}
CaseGrille;*/

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
int Consulter(Grille * grille, int ligne, int colonne);

/*
    SetVal
 
    Insère un élément dans la grille
 
    La grille n'accepte que 0, 1, 2 et 3, la grille doit être initialisée
*/
Grille * SetVal(Grille * grille, int ligne, int colonne, int valEnt);

/*
    Effacer
 
    Efface la grille en la remplissant de 0
 
    La grille doit être initialisée
*/
Grille * Effacer(Grille * grille);

#endif