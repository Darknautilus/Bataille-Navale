// Permet la portabilité du programme
#ifdef __APPLE__

#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>

#else

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#endif

#include "grille.h"
#include "vueGrille.h"

void afficherGrille(Grille * grille, SDL_Surface * ecran, int abscisse, int ordonnee)
{
    SDL_Surface * caseGrille, * numCase;
    SDL_Rect positionCaseGrille, positionNumCase;
    TTF_Font * policeGrille;
    SDL_Color couleurBlanche = {255,255,255};
    Coord coord;
    
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
        numCase = TTF_RenderText_Blended(policeGrille, labelLin, couleurBlanche);
        positionNumCase.x = abscisse - 30;
        positionNumCase.y = ordonnee + i * 30;
        SDL_BlitSurface(numCase, NULL, ecran, &positionNumCase);
        
        for (j=0; j<grille->NbCol; j++)
        {
            sprintf(labelCol, "%d", j+1);
            numCase = TTF_RenderText_Blended(policeGrille, labelCol, couleurBlanche);
            positionNumCase.x = abscisse + j*30;
            positionNumCase.y = ordonnee - 30;
            SDL_BlitSurface(numCase, NULL, ecran, &positionNumCase);
            
            coord.noCol = i+1;
            coord.noLin = j+1;
            
            switch(Consulter(grille, coord))
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

void updateGrille(Grille * grille, SDL_Surface * ecran, Coord coord)
{
    SDL_Surface * caseGrille;
    SDL_Rect positionCaseGrille;
    
    positionCaseGrille.x = grille->abscisse + 30 * (coord.noCol-1);
    positionCaseGrille.y = grille->ordonnee + 30 * (coord.noLin-1);
    
    caseGrille = SDL_CreateRGBSurface(SDL_HWSURFACE, 30, 30, 32, 0, 0, 0, 0);
    
    switch(Consulter(grille, coord))
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
    
    SDL_BlitSurface(caseGrille, NULL, ecran, &positionCaseGrille);
    SDL_Flip(ecran);
    SDL_FreeSurface(caseGrille);
}

int ClicDansGrille(Grille * grille, SDL_Rect * positionClic)
{
    if(positionClic->x >= grille->abscisse && positionClic->x <= grille->abscisse+30*grille->NbCol &&
       positionClic->y >= grille->ordonnee && positionClic->y <= grille->ordonnee+30*grille->NbLin)
        return 1;
    else
        return 0;
}

Coord ClicCaseGrille(Grille * grille, SDL_Rect * positionClic)
{
    Coord coordClic;
    int compteurCol, compteurLin;
    
    if(ClicDansGrille(grille, positionClic))
    {
        for(compteurCol=0;positionClic->x > grille->abscisse+compteurCol*30;compteurCol++){}
        
        for(compteurLin=0;positionClic->y > grille->ordonnee+compteurLin*30;compteurLin++){}
        
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