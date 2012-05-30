/**
 * \file vueGrille.c
 * \author Aurélien Bertron
 * \date 21 avril 2012
 * \brief Code vue grille
 *
 * Contient le corps des fonctions d'entrée-sortie du module de grille
 *
 */

// Permet la portabilité du programme
#include "includeSDL.h"

#include "grille.h"
#include "vueGrille.h"
#include "couleurs.h"
#include "vueUtilsSDL.h"

void afficherGrille(Grille * grille, int abscisse, int ordonnee)
{
	SDL_Surface * caseGrille, * numCase;
	SDL_Rect positionCaseGrille, positionNumCase;
	TTF_Font * policeGrille;
	SDL_Color couleurBlanche = {255,255,255};
	Coord coord;
    CaseGrille contenuCaseGrille;

	int i,j;
	char * labelLin = (char*)malloc(2*sizeof(char));
	char * labelCol = (char*)malloc(2*sizeof(char));

	grille->abscisse = abscisse;
	grille->ordonnee = ordonnee;

	caseGrille = SDL_CreateRGBSurface(SDL_HWSURFACE, KLARGCASE, KHAUTEURCASE, 32, 0, 0, 0, 0);
	caseGrille = SDL_DisplayFormat(caseGrille);// Règle le problème de couleur imprévisible


	policeGrille = TTF_OpenFont("Fonts/default.ttf", KTAILLEPOLICE);

    // Parcours de la matrice/grille
    
    // Parcours des lignes
	for(i=0;i<grille->NbLin;i++)
	{
        // Écriture du numéro de ligne
        sprintf(labelLin, "%c", 'A'+i);
		numCase = TTF_RenderText_Blended(policeGrille, labelLin, couleurBlanche);
		positionNumCase.x = abscisse - KLARGCASE;
		positionNumCase.y = ordonnee + i * (KHAUTEURCASE + KESP_CASE_VERT);
		SDL_BlitSurface(numCase, NULL, SDL_GetVideoSurface(), &positionNumCase);

        // Parcours des colonnes
		for (j=0; j<grille->NbCol; j++)
		{
            // Si l'on est à la première ligne
            if(i == 0)
            {
                // Écriture du numéro de colonne
                sprintf(labelCol, "%d", j+1);
                numCase = TTF_RenderText_Blended(policeGrille, labelCol, couleurBlanche);
                positionNumCase.x = abscisse + j*(KLARGCASE + KESP_CASE_HORI);
                positionNumCase.y = ordonnee - KHAUTEURCASE;
                SDL_BlitSurface(numCase, NULL, SDL_GetVideoSurface(), &positionNumCase);
            }
            
            //Consultation du contenu de la case et chargement de l'image correspondante
                
			coord.noCol = i+1;
			coord.noLin = j+1;
			
			positionCaseGrille.x = j*(KLARGCASE + KESP_CASE_HORI) + abscisse;
			positionCaseGrille.y = i*(KHAUTEURCASE + KESP_CASE_VERT) + ordonnee;
			
			contenuCaseGrille = Consulter(grille, coord);
			
			SDL_FillRect(caseGrille, NULL, convertSDL_Color(getColor(getCouleurFromNum(contenuCaseGrille.couleur))));
			SDL_BlitSurface(caseGrille, NULL, SDL_GetVideoSurface(),&positionCaseGrille);
			
			switch(contenuCaseGrille.etatCase)
			{
				case GRILLE_CASE_TOUCHE:
					caseGrille = IMG_Load("Images/caseBateauTouche.png");
					SDL_BlitSurface(caseGrille, NULL, SDL_GetVideoSurface(),&positionCaseGrille);
					break;
					
				case GRILLE_CASE_COULE:
					caseGrille = IMG_Load("Images/caseBateauCoule.png");
					SDL_BlitSurface(caseGrille, NULL, SDL_GetVideoSurface(),&positionCaseGrille);
					break;
					
				default:
					break;
			}
		}
	}

    // Mise à jour de l'écran pour faire apparaître la grille
	SDL_Flip(SDL_GetVideoSurface());

    // Fin du sous-programme
	free(labelCol);
	free(labelLin);

	SDL_FreeSurface(caseGrille);
	SDL_FreeSurface(numCase);
	TTF_CloseFont(policeGrille);
}

void updateGrille(Grille * grille, Coord coord)
{
	SDL_Surface * caseGrille;
	SDL_Rect positionCaseGrille;
    CaseGrille contenuCaseGrille;

	positionCaseGrille.x = grille->abscisse + (KLARGCASE + KESP_CASE_HORI) * (coord.noCol-1);
	positionCaseGrille.y = grille->ordonnee + (KHAUTEURCASE + KESP_CASE_VERT) * (coord.noLin-1);

	caseGrille = SDL_CreateRGBSurface(SDL_HWSURFACE, 30, 30, 32, 0, 0, 0, 0);
	caseGrille = SDL_DisplayFormat(caseGrille);// Règle le problème de couleur imprévisible
	
	contenuCaseGrille = Consulter(grille, coord);
	
	SDL_FillRect(caseGrille, NULL, convertSDL_Color(getColor(getCouleurFromNum(contenuCaseGrille.couleur))));
	SDL_BlitSurface(caseGrille, NULL, SDL_GetVideoSurface(),&positionCaseGrille);
	
	switch(contenuCaseGrille.etatCase)
	{
		case GRILLE_CASE_TOUCHE:
			caseGrille = IMG_Load("Images/caseBateauTouche.png");
			SDL_BlitSurface(caseGrille, NULL, SDL_GetVideoSurface(),&positionCaseGrille);
			break;
			
		case GRILLE_CASE_COULE:
			caseGrille = IMG_Load("Images/caseBateauCoule.png");
			SDL_BlitSurface(caseGrille, NULL, SDL_GetVideoSurface(),&positionCaseGrille);
			break;
			
		default:
			break;
	}
	
	SDL_Flip(SDL_GetVideoSurface());
	SDL_FreeSurface(caseGrille);
}

int ClicDansGrille(Grille * grille, SDL_Rect * positionClic)
{
	int codeRetour = 0;

	if(positionClic->x >= grille->abscisse && positionClic->x <= grille->abscisse+(KLARGCASE + KESP_CASE_HORI)*grille->NbCol &&
       positionClic->y >= grille->ordonnee && positionClic->y <= grille->ordonnee+(KHAUTEURCASE + KESP_CASE_VERT)*grille->NbLin)
		codeRetour = 1;

    return codeRetour;
}

Coord ClicCaseGrille(Grille * grille, SDL_Rect * positionClic)
{
	Coord coordClic;
	int compteurCol, compteurLin;

	if(ClicDansGrille(grille, positionClic))
	{
		for(compteurCol=0;positionClic->x > grille->abscisse+compteurCol*(KLARGCASE + KESP_CASE_HORI);compteurCol++)
		{}

		for(compteurLin=0;positionClic->y > grille->ordonnee+compteurLin*(KHAUTEURCASE + KESP_CASE_VERT);compteurLin++)
		{}

		coordClic.noCol = compteurCol;
		coordClic.noLin = compteurLin;
	}
	else
	{
		coordClic.noCol = 0;
		coordClic.noLin = 0;
	}

	return coordClic;
}
