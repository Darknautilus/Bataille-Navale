#include "jeu.h"

#include "../model/parametre.h"
#include "../model/partie.h"
#include "../model/bateau.h"
#include "../model/random.h"

#include "../view/vueUtilsSDL.h"
#include "../view/SDLButton.h"
#include "../view/SDLRectangle.h"
#include "../view/vueGrille.h"
#include "../view/vueBateau.h"
#include "../view/SDLImage.h"

#include "../ctrl/fichierDebug.h"

#include "menu.h"

void jeu(Tparam * pParam)
{
    globalPartie = initialiser(pParam);
    
    if(menuPlacementChoixBat())
    {
        // On place les bateaux de la machine et on y va !
        placementAleatBat(partie_JMachine());
        EffacerEcran();
        afficherGrille(globalPartie->grilleMachine, 50, 50);
        SDL_Flip(SDL_GetVideoSurface());
        pause();
    }
    
    libererPartie();
}

int menuPlacementChoixBat(void)
{
    int continuer = 1;
    int i, j;
    int nbBat;
    int absInfoBat, ordInfoBat;
    int cptBat;
    
    int retour = 1;
    
    char nomBateau[K_LGNOM];
    
    char labelColonneTypes[KLONGMAXNOMTYPE];
    
    SDL_Rect positionTexte;
    
    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    int controleEvent;
    
    SDL_Bouton * boutonValider;
    SDL_Bouton * boutonAnnuler;
    SDL_Rect positionBouton;
    
    Rectangle *** tabRectChoixBat = (Rectangle***)malloc(K_NBTYPEBATEAUX * sizeof(Rectangle**));
    for(i=0;i<K_NBTYPEBATEAUX;i++)
    {
        nbBat = globalPartie->parametres->nombreInstanceBateaux[i];
        tabRectChoixBat[i] = (Rectangle**)malloc(nbBat*sizeof(Rectangle*));
        
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
            
            strcpy(nomBateau, globalPartie->parametres->bateauxJoueur[getNumBat(i, j, globalPartie->parametres)].nomBateau);
            tabRectChoixBat[i][j] = creerRectangle(absInfoBat, ordInfoBat, strlen(nomBateau)*16 + 10, 35);
            
            if(j < globalPartie->parametres->nombreInstanceBateaux[i])
            {
                tabRectChoixBat[i][j]->couleur = globalPartie->parametres->bateauxJoueur[getNumBat(i, j, globalPartie->parametres)].couleur;
            }
        }
    }
    
    positionBouton.x = 324;
    positionBouton.y = 682;
    boutonValider = CreerBouton("Valider", &positionBouton, 25);
    positionBouton.x = 524;
    positionBouton.y = 682;
    boutonAnnuler = CreerBouton("Annuler", &positionBouton, 25);
    
    while(continuer)
    {
        EffacerEcran();
        
        AfficherBouton(boutonAnnuler);
        if(placementBatValide(partie_JHumain()))
            strcpy(boutonValider->texte, "Valider");
        else
            strcpy(boutonValider->texte, "");
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
                afficherRectangle(tabRectChoixBat[i][j]);
                positionTexte.x = tabRectChoixBat[i][j]->abscisse + 5;
                positionTexte.y = tabRectChoixBat[i][j]->ordonnee + 5;
                EcrireTexte(globalPartie->parametres->bateauxJoueur[getNumBat(i, j, globalPartie->parametres)].nomBateau, 25, positionTexte, "default.ttf");
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
                    if(clicSurRectangle(tabRectChoixBat[i][j], positionClic) && !placementBatValide(partie_JHumain()))
                    {
                        if(!(partie_JHumain()->mesBateaux[cptBat]->estPlace))
                            menuPlacementGrille(partie_JHumain()->mesBateaux[cptBat]);
                    }
                    cptBat++;
                }
            }
            
            if(ClicSurBouton(boutonValider, positionClic))
            {
                if(placementBatValide(partie_JHumain()))
                {
                    continuer = 0;
                }
            }
            else if(ClicSurBouton(boutonAnnuler, positionClic))
            {
                retour = 0;
                continuer = 0;
            }
        }
    }
    
    LibererBouton(boutonValider);
    LibererBouton(boutonAnnuler);
    free(positionClic);
    
    for(i=0;i<K_NBTYPEBATEAUX;i++)
    {
        nbBat = globalPartie->parametres->nombreInstanceBateaux[i];
        for(j=0;j<nbBat;j++)
        {
            libererRectangle(tabRectChoixBat[i][j]);
        }
        free(tabRectChoixBat[i]);
    }
    free(tabRectChoixBat);
    
    return retour;
}

int menuPlacementGrille(TBateau * pBat)
{
    int continuer = 1;
    int placementValide = 0;
    
    char * titreFenetre = (char*)malloc((strlen("Placement de ")+strlen(getInfoBateau(pBat->idBateau, partie_Param())->nomBateau))*sizeof(char));
    
    SDL_Rect positionTexte;
    
    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    int controleEvent;
    
    SDL_Bouton * boutonSensBat;
    SDL_Bouton * boutonOK;
    SDL_Bouton * boutonAnnuler;
    SDL_Rect positionBouton;
    
    TBateau * batInser;
    
    Coord coordClicGrille;
    
    strcpy(titreFenetre, "Placement de ");
    strcat(titreFenetre, getInfoBateau(pBat->idBateau, partie_Param())->nomBateau);
    
    int sensBat = 0;
    positionBouton.x = 676;
    positionBouton.y = 358;
    boutonSensBat = CreerBouton(tabSensBat[sensBat].libSens, &positionBouton, 25);
    positionBouton.x = 322;
    positionBouton.y = 682;
    boutonOK = CreerBouton("OK", &positionBouton, 25);
    positionBouton.x = 500;
    positionBouton.y = 682;
    boutonAnnuler = CreerBouton("Annuler", &positionBouton, 25);
    
    batInser = CreerBateau();
    batInser->idBateau = pBat->idBateau;
        
    while (continuer)
    {
        EffacerEcran();
        afficherGrille(partie_Grille(), 111, 185);
        
        positionTexte.x = 340;
        positionTexte.y = 30;
        EcrireTexte(titreFenetre, 30, positionTexte, "default.ttf");
        positionTexte.x = 614;
        positionTexte.y = 298;
        EcrireTexte("Sens du bateau :", 25, positionTexte, "default.ttf");
        positionTexte.x = 614;
        positionTexte.y = 147;
        EcrireTexte(tabTypesBat[getInfoBateau(pBat->idBateau, partie_Param())->type-1].nomType, 25, positionTexte, "default.ttf");
        
        AfficherBouton(boutonSensBat);
        AfficherBouton(boutonAnnuler);
        
        if(batInser->estPlace == 0)
            strcpy(boutonOK->texte, "");
        else if(batInser->estPlace == 1)
            strcpy(boutonOK->texte, "OK");
        AfficherBouton(boutonOK);
        
        SDL_Flip(SDL_GetVideoSurface());
        
        controleEvent = AttendreEvent(positionClic, touche);
        if(controleEvent == 2)
        {
            if(ToucheSpec(touche) == SDLK_ESCAPE)
                continuer = 0;
        }
        else if(controleEvent == 1)
        {
            if(ClicSurBouton(boutonSensBat, positionClic))
            {
                sensBat = changerSensBat(sensBat);
                strcpy(boutonSensBat->texte, tabSensBat[sensBat].libSens);
            }
            else if(ClicSurBouton(boutonAnnuler, positionClic))
            {
                continuer = 0;
            }
            else if(ClicSurBouton(boutonOK, positionClic))
            {
                if(batInser->estPlace)
                {
                    pBat->estPlace = 1;
                    setPosBat(pBat, tabSensBat[sensBat].sensBat, coordClicGrille.noCol, coordClicGrille.noLin);
                    InsertBateau(partie_Grille(), pBat);
                    
                    placementValide = 1;
                    
                    continuer = 0;
                }
            }
            else if(ClicDansGrille(partie_Grille(), positionClic))
            {
                batInser->estPlace = 0;
                coordClicGrille = ClicCaseGrille(partie_Grille(), positionClic);
                setPosBat(batInser, tabSensBat[sensBat].sensBat, coordClicGrille.noCol, coordClicGrille.noLin);
                if(estPlacable(batInser, partie_Grille()))
                {
                    batInser->estPlace = 1;
                }
            }
        }
        afficherCoordClic(positionClic, 20, 0, 650, "default.ttf");
        SDL_Flip(SDL_GetVideoSurface());
    }
    
    free(titreFenetre);
    free(touche);
    free(positionClic);
    LibererBouton(boutonOK);
    LibererBouton(boutonSensBat);
    LibererBouton(boutonAnnuler);
    LibererBateau(batInser);
    
    return placementValide;
}

int changerSensBat(int pSensBat)
{
    if(pSensBat == 0)
        return 1;
    else if(pSensBat == 1)
        return 0;
}

int placementBatValide(Joueur * pJoueur)
{
    int i;
    int retour = 1;
    
    for(i=0;i<getNbBat(partie_Param());i++)
    {
        if(!(pJoueur->mesBateaux[i]->estPlace))
            retour = 0;
    }
    
    return retour;
}

void placementAleatBat(Joueur * pJoueur)
{
    int i;
    int sens;
    int abscisse;
    int ordonnee;
    
    dgInfo("Bateaux placés :");
    // On place les bateaux tant que tous ne sont pas places
    while(!placementBatValide(pJoueur))
    {
        for(i=0;i<getNbBat(partie_Param());i++)
        {
            if(!(pJoueur->mesBateaux[i]->estPlace))
            {
                sens = nombreAleatoire(0, 1);
                abscisse = nombreAleatoire(1, 10);
                ordonnee = nombreAleatoire(1, 10);
            
                setPosBat(pJoueur->mesBateaux[i], tabSensBat[sens].sensBat, abscisse, ordonnee);
                if(estPlacable(pJoueur->mesBateaux[i], globalPartie->grilleMachine))
                {
                    pJoueur->mesBateaux[i]->estPlace = 1;
                    InsertBateau(globalPartie->grilleMachine, pJoueur->mesBateaux[i]);
                    dgInfo(getInfoBateau(pJoueur->mesBateaux[i]->idBateau, partie_Param())->nomBateau);
                }
            }
        }
    }
}