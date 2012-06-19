/**
 * \file jeu.c
 * \author Aurelien Bertron
 * \date 13 juin 2012
 * \brief Controleur ecrans jeu
 *
 * Contient les controleurs des ecrans de jeu
 */

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
    if(menuPlacementChoixBat())
    {
        // On place les bateaux de la machine et on y va !
        placementAleatBat(partie_JMachine(), partie_GrilleMachine());
        ecranJeu();
    }

    libererPartie(globalPartie);
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

        // Sert a mettre les rectangles a la ligne a partir de 3 rectangles (ne tiennent pas sur une ligne)
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
            
            // Cree le rectangle d'affichage du bateau
            strcpy(nomBateau, globalPartie->parametres->bateauxJoueur[getNumBat(i, j, globalPartie->parametres)].nomBateau);
            tabRectChoixBat[i][j] = creerRectangle(absInfoBat, ordInfoBat, strlen(nomBateau)*16 + 10, 35);
            
            // Definit la couleur du rectangle suivant le couleur du bateau
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

    // --------------------------------------------------------------------

    while(continuer)
    {
        EffacerEcran();
        
        // Si la partie n'est pas prete, on affiche un bouton vide
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
            // Affiche les noms des types de bateaux
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

        // --------------------------------------------------------------------

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
                        // On place le bateau selectionne
                        if(!(partie_JHumain()->mesBateaux[cptBat]->estPlace))
                            menuPlacementGrille(partie_JHumain()->mesBateaux[cptBat]);
                    }
                    cptBat++;
                }
            }

            if(ClicSurBouton(boutonValider, positionClic))
            {
                // Si la partie est prete, on continue (code retour = 1)
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

    // --------------------------------------------------------------------

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
    
    TBateau * batInser; // Bateau temporaire

    Coord coordClicGrille;

    // --------------------------------------------------------------------

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
    
    // On cree le bateau temporaire pour ne pas affecter la partie en cas d'erreur
    batInser = CreerBateau();
    batInser->idBateau = pBat->idBateau;

    // --------------------------------------------------------------------

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
        
        // Si le bateau n'est pas place, on affiche un bouton vide
        if(batInser->estPlace == 0)
            strcpy(boutonOK->texte, "");
        else if(batInser->estPlace == 1)
            strcpy(boutonOK->texte, "OK");
        AfficherBouton(boutonOK);

        SDL_Flip(SDL_GetVideoSurface());

        // --------------------------------------------------------------------

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
                // On change le sens du bateau (et le texte du bouton)
                sensBat = changerSensBat(sensBat);
                strcpy(boutonSensBat->texte, tabSensBat[sensBat].libSens);
            }
            else if(ClicSurBouton(boutonAnnuler, positionClic))
            {
                // placementValide = 0
                continuer = 0;
            }
            else if(ClicSurBouton(boutonOK, positionClic))
            {
                // Si le bateau est place, on copie les infos du bateau temporaire dans le vrai
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
                // Lors d'un clic dans la grille, on cherche quelle case a ete cliquee et on verifie que le bateau peut etre place la
                batInser->estPlace = 0;
                coordClicGrille = ClicCaseGrille(partie_Grille(), positionClic);
                setPosBat(batInser, tabSensBat[sensBat].sensBat, coordClicGrille.noCol, coordClicGrille.noLin);
                if(estPlacable(batInser, partie_Grille()))
                {
                    batInser->estPlace = 1;
                }
            }
        }
    }

    // --------------------------------------------------------------------

    free(titreFenetre);
    free(touche);
    free(positionClic);
    LibererBouton(boutonOK);
    LibererBouton(boutonSensBat);
    LibererBouton(boutonAnnuler);
    LibererBateau(batInser);

    return placementValide;
}

int ecranJeu(void)
{
    int continuer = 1;
    int resultCoup;
    int partieFinie = 0;
    
    int cptCoups = 0;

    char messageJoueur[K_LGMAXMESSAGE];
    char messageMachine[K_LGMAXMESSAGE];

    SDL_Rect positionTexte;

    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
    int controleEvent;
    
    Coord coordCoup;
    
    SDL_Bouton * boutonFinPartie;
    SDL_Rect positionBouton;

    strcpy(messageJoueur, "Pret a commencer");
    strcpy(messageMachine, "Pret a commencer");

    while(continuer)
    {
        EffacerEcran();

        positionTexte.x = 5;
        positionTexte.y = 682;
        EcrireTexte(messageJoueur, 30, positionTexte, "default.ttf");
        positionTexte.x = 750;
        positionTexte.y = 682;
        EcrireTexte(messageMachine, 30, positionTexte, "default.ttf");

        afficherGrille(partie_Grille(), 50, 50);
        afficherGrille(partie_GrilleMachine(), 530, 50);

        SDL_Flip(SDL_GetVideoSurface());

        // Traitement des événements
        controleEvent = AttendreEvent(positionClic, touche);
        
        // Événement clavier
        if(controleEvent == 2)
        {
            if(ToucheSpec(touche) == SDLK_ESCAPE){}
                //continuer = 0; // Remplacer par menu pause
        }
        
        // Événement souris
        else if(controleEvent == 1)
        {
            // Si l'on clique dans la grille de la machine
            if(ClicDansGrille(partie_GrilleMachine(), positionClic) && partieFinie == 0 )
            {
                // On joue le coup et on récupère le résultat
                coordCoup = ClicCaseGrille(partie_GrilleMachine(), positionClic);
                resultCoup = jouerUnCoup(globalPartie, coordCoup, 1);
                partieFinie = partieEstFinie(globalPartie);
                
                cptCoups++;
                
                if(resultCoup == 1)
                    strcpy(messageMachine, "Touche !");
                else
                    strcpy(messageMachine, "A l'eau !");
                
                // Si la partie n'est pas finie,
                if(partieFinie == 0)
                {
                    // On fait jouer la machine
                    coordCoup = coordAleat(partie_Grille());
                    resultCoup = jouerUnCoup(globalPartie, coordCoup, 0);
                    partieFinie = partieEstFinie(globalPartie);
                    
                    cptCoups++;
                    
                    if(resultCoup == 1)
                        strcpy(messageJoueur, "Touche !");
                    else
                        strcpy(messageJoueur, "A l'eau !");
                }
            }
        }
    }

    free(positionClic);
    free(touche);

    return 1;
}

int changerSensBat(int pSensBat)
{
    if(pSensBat == 0)
        pSensBat = 1;
    else if(pSensBat == 1)
        pSensBat = 0;

    return pSensBat;
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

void placementAleatBat(Joueur * pJoueur, Grille * pGrille)
{
    int i;
    int sens;
    int abscisse;
    int ordonnee;

    // On place les bateaux tant que tous ne sont pas places
    while(!placementBatValide(pJoueur))
    {
        for(i=0;i<getNbBat(partie_Param());i++)
        {
            if(!(pJoueur->mesBateaux[i]->estPlace))
            {
                // Tirage au sort de la position du bateau
                sens = nombreAleatoire(0, 1);
                abscisse = nombreAleatoire(1, 10);
                ordonnee = nombreAleatoire(1, 10);

                setPosBat(pJoueur->mesBateaux[i], tabSensBat[sens].sensBat, abscisse, ordonnee);
                if(estPlacable(pJoueur->mesBateaux[i], globalPartie->grilleMachine))
                {
                    pJoueur->mesBateaux[i]->estPlace = 1;
                    InsertBateau(pGrille, pJoueur->mesBateaux[i]);
                }
            }
        }
    }
}

Coord coordAleat(Grille * pGrille)
{
    Coord coordRetour;
    
    coordRetour.noCol = nombreAleatoire(1, getNbCol(pGrille));
    coordRetour.noLin = nombreAleatoire(1, getNbLin(pGrille));
    
    return coordRetour;
}
