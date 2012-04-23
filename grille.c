#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>

#include "grille.h"

Grille * CreerGrille(int nbLin, int nbCol)
{
	// Controle des paramètres
	if(nbLin > 0 && nbCol > 0)
	{
		int i;
		int j;
		
		// Allocation de la matrice
		Grille * nouvGrille = (Grille*)malloc(sizeof(Grille));
		if(nouvGrille == NULL) return NULL;
		
		nouvGrille->NbLin = nbLin;
        nouvGrille->NbCol = nbCol;
		
		// Allocation du tableau de lignes
		nouvGrille->TabLignes = (Ligne*)malloc(nbLin * sizeof(Ligne));
		if(nouvGrille->TabLignes == NULL) return NULL;
		
		// Parcours des lignes
		for(i=0;i<nbLin;i++)
		{
			// Allocation de chaque ligne (tableau de reels)
			nouvGrille->TabLignes[i] = (int*)malloc(nbCol * sizeof(int));
			if(nouvGrille->TabLignes[i] == NULL) return NULL;
			
			// Et on remplit avec des 0
			for(j=0;j<nbCol;j++)
			{
				nouvGrille->TabLignes[i][j] = 0;
			}
		}
        
		return nouvGrille;
	}
	else
	{
		return NULL;
	}	
}

int Consulter(Grille * grille, int ligne, int colonne)
{
	return grille->TabLignes[ligne-1][colonne-1];
}

void afficherGrille(Grille * grille, SDL_Surface * ecran, int abscisse, int ordonnee)
{
    SDL_Surface * caseGrille, * numCase;
    SDL_Rect positionCaseGrille, positionNumCase;
    TTF_Font * policeGrille;
    SDL_Color couleurNoire = {0,0,0};
    
    int i,j;
    char * labelLin = (char*)malloc(2*sizeof(char));
    char * labelCol = (char*)malloc(2*sizeof(char));
        
    
    caseGrille = SDL_CreateRGBSurface(SDL_HWSURFACE, 30, 30, 32, 0, 0, 0, 0);
        
    policeGrille = TTF_OpenFont("Fonts/apple.ttf", 30);
    
    for(i=0;i<grille->NbLin;i++)
    {
        sprintf(labelLin, "%c", 'A'+i);
        numCase = TTF_RenderText_Solid(policeGrille, labelLin, couleurNoire);
        positionNumCase.x = abscisse - 30;
        positionNumCase.y = ordonnee + i * 30;
        SDL_BlitSurface(numCase, NULL, ecran, &positionNumCase);
        
        for (j=0; j<grille->NbCol; j++)
        {
            sprintf(labelCol, "%d", j+1);
            numCase = TTF_RenderText_Solid(policeGrille, labelCol, couleurNoire);
            positionNumCase.x = abscisse + j*30;
            positionNumCase.y = ordonnee - 30;
            SDL_BlitSurface(numCase, NULL, ecran, &positionNumCase);
            
            switch(Consulter(grille, i+1, j+1))
            {
                case 0:
                    caseGrille = IMG_Load("Images/caseVide.png");
                    break;
                case 1:
                    caseGrille = IMG_Load("Images/caseBateau.png");
                    break;
                case 2:
                    caseGrille = IMG_Load("Images/caseBateauTouche.png");
                    break;
                case 3:
                    caseGrille = IMG_Load("Images/caseBateauCoule.png");
                    break;
            }
            
            positionCaseGrille.x = j*30 + abscisse;
            positionCaseGrille.y = i*30 + ordonnee;
            
            SDL_BlitSurface(caseGrille, NULL, ecran,&positionCaseGrille);
            SDL_Flip(ecran);
            
        }
    }
    
    SDL_FreeSurface(caseGrille);
    SDL_FreeSurface(numCase);
    TTF_CloseFont(policeGrille);
}

Grille * SetVal(Grille * grille, int ligne, int colonne, int valEnt)
{
    grille->TabLignes[ligne-1][colonne-1] = valEnt;
    
    return grille;
}

Grille * Effacer(Grille * grille)
{
    int i,j;
	
	for(i=0;i<grille->NbLin;i++)
    {	
        for(j=0;j<grille->NbCol;j++)
            grille->TabLignes[i][j] = 0;
    }
    
	return grille;
}
