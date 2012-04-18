#include <stdio.h>

#include "coniocouleur.h"
#include "lietrec.h"


/************************************************************************************/
/* N: tracerLigneH																	*/
/* D: trace une ligne horizontale de largeur plargeur à partir de la position px,py */
/* (px, py) correspond au point gauche												*/
/* E : px, py, plargeur																*/
/* S : rien																			*/
/* R : rien																			*/
/* P: 1 <= px  et 1 <= py <= 25	et px+	plargeur <=80 								*/
/************************************************************************************/
void tracerLigneH(const int px, const int py, const int plargeur)
{
	int i;

	gotoxy( px,  py);
	for (i=1; i<= plargeur; i++) cprintf("%c",'-');
}

/************************************************************************************/
/* N: tracerLigneV																	*/
/* D: trace une ligne verticale de hauteur phauteur à partir de la position px,py	*/
/* (px, py) correspond au point haut 												*/
/* E : px, py, phauteur																*/
/* R : rien																			*/
/* S : rien																			*/
/* P: 1 <= px <=80 et 1 <= py et py + phauteur<=25									*/
/************************************************************************************/
void tracerLigneV(const int px, const int py, const int phauteur)
{
	int i;
	for (i=0; i< phauteur; i++)
	{
		gotoxy( px,  py+i);
		cprintf("%c",'|');
	}
}

/************************************************************************************/
/* N: tracerRectangle																*/
/* D: trace un rectangle de hauteur phauteur et de langeur plargeur à partir de la 	*/
/* position px,py (px, py) correspond au point haut gauche							*/
/* E : px, py, phauteur	plargeur													*/
/* R : rien																			*/
/* S : rien																			*/
/* P: 1 <= px et 1 <= py et	px+	phauteur <=79 et py + plargeur<=24					*/
/************************************************************************************/
void tracerRectangle(const int px, const int py, const int plargeur, const int phauteur)
{
	tracerLigneH(px+1, py, plargeur-1);
	tracerLigneV( px, py+1, phauteur-1);
	tracerLigneV( px+plargeur, py+1, phauteur-1);
	tracerLigneH(px+1,  py+phauteur, plargeur-1);
}
