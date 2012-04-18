





//a changer
//***************************
/*	N : afficherGrille
	D : affiche une grille de taille (pnbLignes*pnbColonnes) de couleur pCouleur à partir d'un point haut gauche en px,py
	E : px, int py, int pnbLignes, int pnbColonnes, COLORS pCouleur
	S : ...
	R :  -
	Prec : -fenetre initialisée
*/
void afficherGrille(int px, int py, int pnbLignes, int pnbColonnes, COLORS pCouleur);
//int afficherGrille();

//***************************
/*	N : afficherCaractereDansGrille
	D : afficherCaractereDansGrille dans la grille en position (ppositionXGrille,ppositionYGrille)
	 le caractere pcaractere de couleur pcouleurCaractere avec un arrière plan pcouleurFond en ligne colonne (pligna, pcolonne
	E : tout
	S : ...
	R :  -
	Prec : -fenetre initialisée, gille a au moins pligne et pcolonne dans la grille
*/


void afficherCaractereDansGrille(COLORS pcouleurCaractere,COLORS pcouleurFond,char pcaractere,int  ppositionXGrille,int ppositionYGrille,int pligne,int pcolonne);


void afficherToutEnTest();
