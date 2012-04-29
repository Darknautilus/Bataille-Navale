#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>

#include "grille.h"
#include "vueGrille.h"

void afficherGrille(Grille * grille, SDL_Surface * ecran, int abscisse, int ordonnee)
{
    SDL_Surface * caseGrille, * numCase;
    SDL_Rect positionCaseGrille, positionNumCase;
    TTF_Font * policeGrille;
    SDL_Color couleurBlanche = {255,255,255};
    
    int i,j;
    char * labelLin = (char*)malloc(2*sizeof(char));
    char * labelCol = (char*)malloc(2*sizeof(char));
    
    grille->abscisse = abscisse;
    grille->ordonnee = ordonnee;
    
    caseGrille = SDL_CreateRGBSurface(SDL_HWSURFACE, 30, 30, 32, 0, 0, 0, 0);
    
    policeGrille = TTF_OpenFont("Fonts/apple.ttf", 30);
    
    for(i=0;i<grille->NbLin;i++)
    {
        sprintf(labelLin, "%c", 'A'+i);
        numCase = TTF_RenderText_Solid(policeGrille, labelLin, couleurBlanche);
        positionNumCase.x = abscisse - 30;
        positionNumCase.y = ordonnee + i * 30;
        SDL_BlitSurface(numCase, NULL, ecran, &positionNumCase);
        
        for (j=0; j<grille->NbCol; j++)
        {
            sprintf(labelCol, "%d", j+1);
            numCase = TTF_RenderText_Solid(policeGrille, labelCol, couleurBlanche);
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
            
        }
    }
    
    SDL_Flip(ecran);
    
    SDL_FreeSurface(caseGrille);
    SDL_FreeSurface(numCase);
    TTF_CloseFont(policeGrille);
}

void updateGrille(Grille * grille, SDL_Surface * ecran, int noLin, int noCol)
{
    SDL_Surface * caseGrille;
    SDL_Rect positionCaseGrille;
    
    positionCaseGrille.x = grille->abscisse + 30 * (noCol-1);
    positionCaseGrille.y = grille->ordonnee + 30 * (noLin-1);
    
    caseGrille = SDL_CreateRGBSurface(SDL_HWSURFACE, 30, 30, 32, 0, 0, 0, 0);
    
    switch(Consulter(grille, noLin, noCol))
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
    
    SDL_BlitSurface(caseGrille, NULL, ecran,&positionCaseGrille);
    SDL_Flip(ecran);
    SDL_FreeSurface(caseGrille);
}