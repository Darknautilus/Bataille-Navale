#include <string.h>

#include "menu.h"

#include "../model/champSaisie.h"

// Permet la portabilité du programme
#include "includeSDL.h"
#include "vueChampSaisie.h"

#include "vueUtilsSDL.h"
#include "vueGrille.h"
#include "vueBateau.h"
#include "SDLButton.h"
#include "SDLImage.h"

#include "../ctrl/utilsSDL.h"
#include "../ctrl/fichierDebug.h"

#include "../test/test.h"
#include "../test/view/testVue.h"

#include "../model/bateau.h"

const TtypeBat tabTypesBat[KTAILLEMAXBAT] = {
    {VOILIER,"Voilier"},
    {REMORQUEUR,"Remorqueur"},
    {CARGOT,"Cargot"},
    {SOUSMARIN,"Sous-marin"},
    {PORTEAVION,"Porte-avion"}
};

void AfficherMenuAccueil(void)
{
	int continuer = 1;
    int controle;
    SDL_Rect positionTexte;
    SDL_Color couleurRectangleImages = {255,255,255};
    
    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
    
    afficherRectangle(10, 10, 231, 110, couleurRectangleImages);
    Image * imageIUT = CreerImage("iutBlagnac.jpg", 15, 15);
    Image * imageUniv = CreerImage("univMirail.gif", 115, 15);
    Image * imageBateau = CreerImage("bateau.png", 454, 418);
    
    positionTexte.x = 219;
    positionTexte.y = 282;
    EcrireLigneTexte("Bataille Navale", 70, positionTexte, "default.ttf");
    
    positionTexte.x = 15;
    positionTexte.y = 700;
    EcrireTexte("Par Aurelien Bertron\net Benoit Sauvere", 20, positionTexte, "default.ttf");
    
    positionTexte.x = 240;
    positionTexte.y = 539;
    EcrireTexte("Appuyez sur espace pour continuer", 25, positionTexte, "default.ttf");
    

    AfficherImage(imageIUT);
    AfficherImage(imageUniv);
    AfficherImage(imageBateau);

	SDL_Flip(SDL_GetVideoSurface());

	while(continuer)
	{
		controle = AttendreEvent(positionClic, touche);

        if (controle == 2)
        {
            switch(ToucheSpec(touche))
            {
                case SDLK_SPACE:
                    continuer = 0;
                    break;

                case SDLK_ESCAPE:
                    exit(EXIT_FAILURE);
                    break;

                default:
                    break;
            }
        }
        else if(controle == 1)
        {
            afficherCoordClic(positionClic, 20, 0, 650, "default.ttf");
            SDL_Flip(SDL_GetVideoSurface());
        }
	}

    LibererImage(imageIUT);
    LibererImage(imageUniv);
    LibererImage(imageBateau);
	free(touche);
    free(positionClic);
}

int AfficherMenuRacine(void)
{
    int continuer = 1;
    int choixMenu = 1;

    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));

	Image * imagePuce = CreerImage("puceMenu.png", 100, 200);
    
    SDL_Rect positionTexte;

	SDL_EnableUNICODE(SDL_ENABLE);

    while(continuer)
    {
        EffacerEcran();
        AfficherImage(imagePuce);
        
        positionTexte.x = 170;
        positionTexte.y = 210;
        EcrireTexte("- Nouvelle Partie", 30, positionTexte, "default.ttf");
        positionTexte.y += 60;
        EcrireTexte("- Charger Partie", 30, positionTexte, "default.ttf");
        positionTexte.y += 60;
        EcrireTexte("- Meilleurs Scores", 30, positionTexte, "default.ttf");
        positionTexte.y += 60;
        EcrireTexte("- Afficher Regles", 30, positionTexte, "default.ttf");
        positionTexte.y += 60;
        EcrireTexte("- Quitter", 30, positionTexte, "default.ttf");

        SDL_Flip(SDL_GetVideoSurface());

        AttendreEvent(NULL, touche);

        if(ToucheChar(touche) == 't')
            MenuTestVue();
		else if(ToucheChar(touche) == 'y')
			MenuTest();

        switch(ToucheSpec(touche))
        {
            case SDLK_RETURN:
                continuer = 0;
            break;

            case SDLK_UP:
                if(choixMenu != 1)
                {
                    choixMenu --;
                    imagePuce->ordonnee -= 60;
                }
            break;

            case SDLK_DOWN:
                if(choixMenu != 5)
                {
                    choixMenu ++;
                    imagePuce->ordonnee += 60;
                }
            break;

            case SDLK_ESCAPE:
                exit(EXIT_SUCCESS);
            break;

            default:
            break;

        }
	}

	SDL_EnableUNICODE(SDL_DISABLE);

	LibererImage(imagePuce);
	free(touche);

	return choixMenu;
}

void MenuNouvellePartie(Tparam * parametre)
{
    // Champs de saisie
	ChampSaisie * champPseudoHumain, * champPseudoIA;
    ChampSaisie * paramNbBat[K_NBTYPEBATEAUX]; // Choix du nombre de bateaux (tableau de champs)
    
	int continuer = 1;
    int i;
    
    // Informations de positions
	SDL_Rect positionBoutonOK, positionBoutonParam, positionTexte;
    
    // Informations pour AttendreEvent()
	SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
    int controleEvent;
    
    // Boutons
	SDL_Bouton * boutonOK;
	SDL_Bouton * boutonParam;
    
    
    int * nbInstancesbat;
    char chaineInstance[3];

    // --------------------------------------------------------------------

    // Initialisation des champs de saisie
	champPseudoHumain = CreerChamp(30, 20, 230, 150);
	champPseudoIA = CreerChamp(30, 20, 230, 200);
    InitTexte(champPseudoHumain, "Anonyme");
	InitTexte(champPseudoIA, "GlaDos");
    
    // Champs du nombre d'instances de chaque bateaux : récupération des valeurs déjà paramétrées et initialisation des champs
    nbInstancesbat = getNBInstances(parametre);
    for(i=0;i<K_NBTYPEBATEAUX;i++)
    {
        paramNbBat[i] = CreerChamp(2, 20, 279, 372+i*40);
        sprintf(chaineInstance, "%d", nbInstancesbat[i]);
        InitTexte(paramNbBat[i], chaineInstance);
    }
    
    // Positionnement des boutons
	positionBoutonParam.x = 360;
	positionBoutonParam.y = 622;
	boutonParam = CreerBouton("Plus de parametres", &positionBoutonParam, 25);
	positionBoutonOK.x = 360;
	positionBoutonOK.y = 682;
	boutonOK = CreerBouton("Demarrer la partie", &positionBoutonOK, 25);

    // --------------------------------------------------------------------

	while (continuer)
	{
        // Affichage de tous les objets
        EffacerEcran();
        positionTexte.x = 300;
        positionTexte.y = 15;
        EcrireTexte("Nouvelle Partie", 50, positionTexte, "default.ttf");
        positionTexte.x = 10;
        positionTexte.y = 150;
        EcrireTexte("Pseudo Humain :", 26, positionTexte, "default.ttf");
        positionTexte.x = 10;
        positionTexte.y = 200;
        EcrireTexte("Pseudo IA :", 26, positionTexte, "default.ttf");
        positionTexte.x = 86;
        positionTexte.y = 297;
        EcrireTexte("Nombre de bateaux :", 25, positionTexte, "default.ttf");

		AfficherChamp(champPseudoHumain);
		AfficherChamp(champPseudoIA);
        
        for(i=0;i<K_NBTYPEBATEAUX;i++)
        {
            positionTexte.x = 89;
            positionTexte.y = 372+i*40;
            EcrireTexte(tabTypesBat[i].nomType, 25, positionTexte, "default.ttf");
            AfficherChamp(paramNbBat[i]);
        }
		AfficherBouton(boutonOK);
		AfficherBouton(boutonParam);
		SDL_Flip(SDL_GetVideoSurface());
        
        
        // Traitement de l'événement
		controleEvent = AttendreEvent(positionClic, touche);
        
        // Événement souris
		if(controleEvent == 1)
		{
			if(ClicSurChamp(champPseudoHumain, positionClic))
			{
				ChangeFocus(champPseudoHumain, CHAMP_ACTIF);
				EditerChamp(champPseudoHumain);
			}

			else if(ClicSurChamp(champPseudoIA, positionClic))
			{
				ChangeFocus(champPseudoIA, CHAMP_ACTIF);
				EditerChamp(champPseudoIA);
			}
            
            else if(ClicSurBouton(boutonParam, positionClic))
            {
                MenuParam(parametre);
            }

			else if(ClicSurBouton(boutonOK, positionClic))
			{
				EcranGrille(champPseudoHumain);
			}
            else
            {
                for(i=0;i<K_NBTYPEBATEAUX;i++)
                {
                    if(ClicSurChamp(paramNbBat[i], positionClic))
                    {
                        ChangeFocus(paramNbBat[i], CHAMP_ACTIF);
                        EditerChamp(paramNbBat[i]);
                        parametre->nombreInstanceBateaux[i] = strtol(paramNbBat[i]->chaine, NULL, 10);
                    }
                }
                afficherCoordClic(positionClic, 20, 0, 650, "default.ttf");
                SDL_Flip(SDL_GetVideoSurface());
            }

		}
        
        // Événement clavier
		if(controleEvent == 2 && ToucheSpec(touche) == SDLK_ESCAPE)
			continuer = 0;
	}

    // --------------------------------------------------------------------
    
	free(positionClic);
	free(touche);
	LibererChamp(champPseudoHumain);
	LibererChamp(champPseudoIA);
	LibererBouton(boutonOK);
	LibererBouton(boutonParam);
    
    for(i=0;i<K_NBTYPEBATEAUX;i++)
    {
        LibererChamp(paramNbBat[i]);
    }
    
}

void MenuParam(Tparam * parametre)
{
    int continuer = 1;
    int i,j;
    
    SDL_Bouton * boutonRetour;
    SDL_Rect positionBouton, positionTexte;
    
    int nbBat;
    
    char labelColonneTypes[KLONGMAXNOMTYPE];
    
    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    
    // Attention : Tableau à double entrée de pointeurs sur ChampSaisie
    ChampSaisie *** tabChamp = (ChampSaisie***)malloc(K_NBTYPEBATEAUX * sizeof(ChampSaisie**));
    for(i=0;i<K_NBTYPEBATEAUX;i++)
    {
        nbBat = parametre->nombreInstanceBateaux[i]; // getNbInstancesType ne fonctionne pas avec un entier (pourquoi?)
        tabChamp[i] = (ChampSaisie**)malloc(nbBat*sizeof(ChampSaisie*));
        for(j=0;j<nbBat;j++)
        {
            tabChamp[i][j] = CreerChamp(K_LGNOM, 15, 10+i*200, 50+j*40);
            InitTexte(tabChamp[i][j], "Champ");
        }
    }
    
    positionBouton.x = 360;
    positionBouton.y = 622;
    boutonRetour = CreerBouton("Retour", &positionBouton, 25);
    
    while (continuer)
    {
        EffacerEcran();
        AfficherBouton(boutonRetour);
        
        for(i=0;i<K_NBTYPEBATEAUX;i++)
        {
            positionTexte.x = 20+i*200;
            positionTexte.y = 10;
            
            strcpy(labelColonneTypes,tabTypesBat[i].nomType);
            strcat(labelColonneTypes, "s");
            
            EcrireTexte(labelColonneTypes, 25, positionTexte, "default.ttf");
            
            nbBat = parametre->nombreInstanceBateaux[i];
            for(j=0;j<nbBat;j++)
            {
                AfficherChamp(tabChamp[i][j]);
            }
        }
        
        SDL_Flip(SDL_GetVideoSurface());
        
        AttendreEvent(positionClic, NULL);
        
        if(ClicSurBouton(boutonRetour, positionClic))
            continuer = 0;
        else {
            afficherCoordClic(positionClic, 20, 0, 650, "default.ttf");
            SDL_Flip(SDL_GetVideoSurface());
        }
    }

    LibererBouton(boutonRetour);
    
    for(i=0;i<K_NBTYPEBATEAUX;i++)
    {
        nbBat = parametre->nombreInstanceBateaux[i];
        for(j=0;j<nbBat;j++)
        {
            LibererChamp(tabChamp[i][j]);
        }
        
        free(tabChamp[i]);
    }
    free(tabChamp);
    
    free(positionClic);
}

void EcranGrille(ChampSaisie * champ)
{
    Grille * grilleJoueur;
    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	SDL_Rect positionTexte;
    int controleEvent;
    Coord coord;
    CaseGrille caseGrille;
	TBateau * bat;
	TPosition posBat = {HORIZONTAL,2,2};

    int continuer = 1;


    grilleJoueur = CreerGrille(10, 10);

	bat = creerBateau(posBat, CARGOT);
	toucherBateau(bat, 1);

    EffacerEcran();
    afficherGrille(grilleJoueur, 40, 100);
	InsertBateau(grilleJoueur, bat);

	positionTexte.x = 40;
	positionTexte.y = 20;

    EcrireLigneTexte(champ->chaine, 40, positionTexte, "default.ttf");

    while (continuer)
    {
        SDL_Flip(SDL_GetVideoSurface());
        controleEvent = AttendreEvent(positionClic, touche);
        if(controleEvent == 2)
        {
            if(ToucheSpec(touche) == SDLK_ESCAPE)
                continuer = 0;
        }
        else
        {
            coord = ClicCaseGrille(grilleJoueur, positionClic);
            caseGrille = Consulter(grilleJoueur, coord);
            if(ClicDansGrille(grilleJoueur, positionClic))
            {
                if(caseGrille.etatCase == GRILLE_CASE_NORMAL)
                    grilleJoueur = SetEtatCase(grilleJoueur, coord, GRILLE_CASE_TOUCHE);
                else if(caseGrille.etatCase == GRILLE_CASE_TOUCHE)
                    grilleJoueur = SetEtatCase(grilleJoueur, coord, GRILLE_CASE_NORMAL);

                updateGrille(grilleJoueur, coord);
            }
        }
    }

    LibererGrille(grilleJoueur);
	LibererBateau(bat);

    free(touche);
    free(positionClic);
}
