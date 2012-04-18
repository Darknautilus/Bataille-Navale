#include <stdio.h>

#include "coniocouleur.h"

/************************************************************************************/
/* N: tracerLigneH																	*/
/* D: trace une ligne horizontale de largeur plargeur à partir de la position px,py*/
/* (px, py) correspond au point gauche												*/
/* E : px, py, plargeur																*/
/* S : rien																			*/
/* R : rien																			*/
/* P: 1 <= px  et 1 <= py <= 25	et px+	plargeur <=80 								*/
/************************************************************************************/
void tracerLigneH(const int px, const int py, const int plargeur);


/************************************************************************************/
/* N: tracerLigneV																	*/
/* D: trace une ligne verticale de hauteur phauteur à partir de la position px,py	*/
/* (px, py) correspond au point haut 												*/
/* E : px, py, phauteur																*/
/* R : rien																			*/
/* S : rien																			*/
/* P: 1 <= px <=80 et 1 <= py et py + phauteur<=25									*/
/************************************************************************************/
void tracerLigneV(const int px, const int py, const int phauteur);

/************************************************************************************/
/* N: tracerRectangle																*/
/* D: trace un rectangle de hauteur phauteur et de langeur plargeur à partir de la 	*/
/* position px,py (px, py) correspond au point haut gauche							*/
/* E : px, py, phauteur	plargeur													*/
/* R : rien																			*/
/* S : rien																			*/
/* P: 1 <= px et 1 <= py et	px+	phauteur <=80 et py + plargeur<=25					*/
/************************************************************************************/
void tracerRectangle(const int px, const int py, const int phauteur, const int plargeur);
