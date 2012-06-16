#include "jeu.h"

#include "../model/parametre.h"
#include "../model/partie.h"

#include "../view/vueUtilsSDL.h"
#include "../view/SDLButton.h"
#include "../view/SDLRectangle.h"
#include "../view/vueGrille.h"

#include "menu.h"

void jeu(Tparam * pParam)
{
    globalPartie = initialiser(pParam);
    
    
}

void menuPlacementChoixBat(void)
{
    int continuer = 1;
    int i, j;
    int nbBat;
    int absInfoBat, ordInfoBat;
    int cptBat;
    
    char labelColonneTypes[KLONGMAXNOMTYPE];
    
    SDL_Rect positionTexte;
    
    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    int controleEvent;
    
    SDL_Bouton * boutonValider;
    SDL_Rect positionBouton;
    
    Rectangle *** tabRectChoixCoul = (Rectangle***)malloc(K_NBTYPEBATEAUX * sizeof(Rectangle**));
    for(i=0;i<K_NBTYPEBATEAUX;i++)
    {
        nbBat = globalPartie->parametres->nombreInstanceBateaux[i];
        tabRectChoixCoul[i] = (Rectangle**)malloc(nbBat*sizeof(Rectangle*));
        
        for(j=0;j<nbBat;j++)
        {
            if(j >= 3)
            {
                ordInfoBat = 140+i*120;
                absInfoBat = 230+(j-3)*245;
            }
            else
            {
                ordInfoBat = 100+i*120;
                absInfoBat = 230+j*245;
            }
            
            tabRectChoixCoul[i][j] = creerRectangle(absInfoBat, ordInfoBat, 25, 25);
            
            if(j < globalPartie->parametres->nombreInstanceBateaux[i])
            {
                tabRectChoixCoul[i][j]->couleur = globalPartie->parametres->bateauxJoueur[getNumBat(i, j, globalPartie->parametres)].couleur;
            }
        }
    }
    
    positionBouton.x = 424;
    positionBouton.y = 682;
    boutonValider = CreerBouton("Valider", &positionBouton, 25);
    
    while(continuer)
    {
        EffacerEcran();
        AfficherBouton(boutonValider);
        
        positionTexte.x = 370;
        positionTexte.y = 10;
        EcrireTexte("Placement des bateaux", 30, positionTexte, "default.ttf");
        
        for(i=0;i<K_NBTYPEBATEAUX;i++)
        {
            positionTexte.x = 20;
            positionTexte.y = 100+i*120;
            
            strcpy(labelColonneTypes,tabTypesBat[i].nomType);
            strcat(labelColonneTypes, "s");
            
            EcrireTexte(labelColonneTypes, 25, positionTexte, "default.ttf");
            
            nbBat = globalPartie->parametres->nombreInstanceBateaux[i];
            for(j=0;j<nbBat;j++)
            {
                afficherRectangle(tabRectChoixCoul[i][j]);
            }
        }
        
        SDL_Flip(SDL_GetVideoSurface());
        
        controleEvent = AttendreEvent(positionClic, NULL);
        
        cptBat = 0;
        if(controleEvent == 1)
        {
            for(i=0;i<K_NBTYPEBATEAUX;i++)
            {
                nbBat = globalPartie->parametres->nombreInstanceBateaux[i];
                for(j=0;j<nbBat;j++)
                {
                    if(clicSurRectangle(tabRectChoixCoul[i][j], positionClic))
                        menuPlacementGrille(partie_JHumain()->mesBateaux[cptBat]);
                    
                    cptBat++;
                }
            }
            afficherCoordClic(positionClic, 20, 0, 650, "default.ttf");
            SDL_Flip(SDL_GetVideoSurface());
        }
    }
    
    LibererBouton(boutonValider);
    free(positionClic);
}

void menuPlacementGrille(TBateau * pBat)
{
    int continuer = 1;
    int i, j;
    
    char * titreFenetre = (char*)malloc((strlen("Placement de ")+strlen(partie_Param()->bateauxJoueur[pBat->idBateau].nomBateau))*sizeof(char));
    
    SDL_Rect positionTexte;
    
    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    int controleEvent;
    
    while (continuer)
    {
        EffacerEcran();
        afficherGrille(partie_Grille(), 111, 185);
        
        positionTexte.x = 340;
        positionTexte.y = 30;
        strcpy(titreFenetre, "Placement de ");
        strcat(titreFenetre, partie_Param()->bateauxJoueur[pBat->idBateau].nomBateau);
        EcrireTexte(titreFenetre, 30, positionTexte, "default.ttf");
        
        SDL_Flip(SDL_GetVideoSurface());
        
        controleEvent = AttendreEvent(positionClic, touche);
        if(controleEvent == 2)
        {
            if(ToucheSpec(touche) == SDLK_ESCAPE)
                continuer = 0;
        }
        else if(controleEvent == 1)
        {
            afficherCoordClic(positionClic, 20, 0, 650, "default.ttf");
            SDL_Flip(SDL_GetVideoSurface());
        }
    }
    
    free(titreFenetre);
    free(touche);
    free(positionClic);
}