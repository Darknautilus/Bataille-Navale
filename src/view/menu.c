#include <string.h>

#include "menu.h"

#include "../model/champSaisie.h"
#include "../model/partie.h"

// Permet la portabilité du programme
#include "includeSDL.h"
#include "vueChampSaisie.h"

#include "vueUtilsSDL.h"
#include "vueGrille.h"
#include "vueBateau.h"
#include "SDLButton.h"
#include "SDLImage.h"
#include "SDLRectangle.h"
#include "vueSDLMsgBox.h"

#include "../ctrl/utilsSDL.h"
#include "../ctrl/fichierDebug.h"
#include "../ctrl/CtrlGrille.h"

#include "../test/test.h"
#include "../test/view/testVue.h"

#include "../model/bateau.h"
#include "../model/parametre.h"
#include "../model/random.h"
#include "../model/couleurs.h"

const TtypeBat tabTypesBat[K_NBTYPEBATEAUX] = {
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

    Rectangle * rectLogos;

    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));

    rectLogos = creerRectangle(10, 10, 231, 110);

    afficherRectangle(rectLogos);

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
    libererRectangle(rectLogos);
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

    int nbInstChange = 1;

    // Informations de positions
	SDL_Rect positionBouton, positionTexte;

    // Informations pour AttendreEvent()
	SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
    int controleEvent;

    // Boutons
	SDL_Bouton * boutonOK;
	SDL_Bouton * boutonParam;

    SDL_Bouton * boutonChargerParam;
    SDL_Bouton * boutonRetablirDefaut;
    SDL_Bouton * boutonEnregistrerParam;

    FILE * descFicParam;

    int * nbInstancesbat;
    char chaineInstance[3];
    char nomBatIA[K_LGNOM];

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
    }

    for(i=0;i<getNbBat(parametre);i++)
    {
        strcpy(parametre->bateauxJoueur[i].nomBateau, "Nom :");
        parametre->bateauxJoueur[i].couleur = getCouleurFromNum(0);
    }

    // Positionnement des boutons
	positionBouton.x = 360;
	positionBouton.y = 622;
	boutonParam = CreerBouton("Plus de parametres", &positionBouton, 25);
	positionBouton.x = 360;
	positionBouton.y = 682;
	boutonOK = CreerBouton("Demarrer la partie", &positionBouton, 25);
    positionBouton.x = 630;
    positionBouton.y = 389;
    boutonChargerParam = CreerBouton("Utiliser parametres par defaut", &positionBouton, 20);
    positionBouton.x = 630;
    positionBouton.y = 330;
    boutonEnregistrerParam = CreerBouton("Enregistrer les parametres", &positionBouton, 20);
    positionBouton.x = 630;
    positionBouton.y = 480;
    boutonRetablirDefaut = CreerBouton("Retablir parametres d'origine", &positionBouton, 20);

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
            sprintf(chaineInstance, "%d", nbInstancesbat[i]);
            InitTexte(paramNbBat[i], chaineInstance);
            AfficherChamp(paramNbBat[i]);
        }
		AfficherBouton(boutonOK);
		AfficherBouton(boutonParam);
        AfficherBouton(boutonChargerParam);
        AfficherBouton(boutonEnregistrerParam);
        AfficherBouton(boutonRetablirDefaut);

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
                if(nbInstChange)
                {
                    resetInfoBateau(parametre);
                    nbInstChange = 0;
                }

                MenuParam(parametre);
            }

			else if(ClicSurBouton(boutonOK, positionClic))
			{

                if(!nbInstChange)
                {
                    descFicParam = fopen("dicoNoms.dat", "r");
                    if(descFicParam == NULL)
                        dgFatal("dicoNoms.dat non trouve");

                    for(i=0;i<getNbBat(parametre);i++)
                    {
                        choixMotHasard(nomBatIA, descFicParam, K_LGNOM);
                        setInfoBateau(&(parametre->bateauxMachine[i]), nomBatIA, nombreAleatoire(1, KCOULEURS_NBCOULMAX-1), i);
                    }
                    fclose(descFicParam);


                    /*      / \
                    //     / | \
                    //    /  |  \    globalPartie est une variable GLOBALE
                    //   /___o___\
                    */
                    globalPartie = initialiser(parametre);

                    strcpy(globalPartie->joueur->nomJ, champPseudoHumain->chaine);
                    strcpy(globalPartie->machine->nomJ, champPseudoIA->chaine);


                    EcranGrille(champPseudoHumain);

                    continuer = 0;
                }
                else
                {
                    // Boite Message (non finalise)
                }



			}
            else if(ClicSurBouton(boutonEnregistrerParam, positionClic))
            {
                descFicParam = fopen("paramUser.dat", "w");
                if(descFicParam == NULL)
                    dgFatal("paramUser.dat non trouve");

                memParam(parametre, descFicParam);
                fclose(descFicParam);
            }
            else if(ClicSurBouton(boutonChargerParam, positionClic))
            {
                descFicParam = fopen("paramUser.dat", "r");
                if(descFicParam == NULL)
                    dgFatal("paramUser.dat non trouve");

                resetInfoBateau(parametre);
                chargerParam(descFicParam, parametre);
                fclose(descFicParam);
                nbInstChange = 0;
            }
            else if(ClicSurBouton(boutonRetablirDefaut, positionClic))
            {
                descFicParam = fopen("paramOrigin.dat", "r");
                if(descFicParam == NULL)
                    dgFatal("paramOrigin.dat non trouve");

                resetInfoBateau(parametre);
                chargerParam(descFicParam, parametre);
                dgInfo(parametre->bateauxJoueur[0].nomBateau);
                fclose(descFicParam);
                nbInstChange = 0;
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
                        nbInstChange = 1;
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
    LibererBouton(boutonChargerParam);
    LibererBouton(boutonEnregistrerParam);
    LibererBouton(boutonRetablirDefaut);

    for(i=0;i<K_NBTYPEBATEAUX;i++)
    {
        LibererChamp(paramNbBat[i]);
    }

}

void MenuParam(Tparam * parametre)
{
    int continuer = 1;
    int i,j;

    SDL_Bouton * boutonAnnuler, * boutonValider;

    SDL_Rect positionBouton, positionTexte;

    int nbBat;

    int absInfoBat;
    int ordInfoBat; // = 0 si tous les champs tiennent sur une ligne (nbBat <= 3) et vaut 30 sinon

    char labelColonneTypes[KLONGMAXNOMTYPE];

    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));

    // Attention : Tableau à double entrée de pointeurs sur ChampSaisie
    ChampSaisie *** tabChamp = (ChampSaisie***)malloc(K_NBTYPEBATEAUX * sizeof(ChampSaisie**));
    // De même pour les rectangles de couleur
    Rectangle *** tabRectChoixCoul = (Rectangle***)malloc(K_NBTYPEBATEAUX * sizeof(Rectangle**));
    for(i=0;i<K_NBTYPEBATEAUX;i++)
    {
        nbBat = parametre->nombreInstanceBateaux[i]; // getNbInstancesType ne fonctionne pas avec un entier (pourquoi?)

        tabChamp[i] = (ChampSaisie**)malloc(nbBat*sizeof(ChampSaisie*));
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

            tabChamp[i][j] = CreerChamp(K_LGNOM, 15, absInfoBat+30, ordInfoBat);
            tabRectChoixCoul[i][j] = creerRectangle(absInfoBat, ordInfoBat, 25, 25);

            if(j < parametre->nombreInstanceBateaux[i])
            {
                strcpy(tabChamp[i][j]->chaine, parametre->bateauxJoueur[getNumBat(i, j, parametre)].nomBateau);
                tabRectChoixCoul[i][j]->couleur = getNumFromColor(parametre->bateauxJoueur[getNumBat(i, j, parametre)].couleur);
            }
            else
                strcpy(tabChamp[i][j]->chaine, "Nom :");
        }
    }

    positionBouton.x = 303;
    positionBouton.y = 682;
    boutonValider = CreerBouton("Valider", &positionBouton, 25);
    positionBouton.x = 500;
    positionBouton.y = 682;
    boutonAnnuler = CreerBouton("Annuler", &positionBouton, 25);

    while (continuer)
    {
        EffacerEcran();
        AfficherBouton(boutonValider);
        AfficherBouton(boutonAnnuler);

        positionTexte.x = 259;
        positionTexte.y = 10;
        EcrireTexte("Noms et couleurs des bateaux", 35, positionTexte, "default.ttf");

        for(i=0;i<K_NBTYPEBATEAUX;i++)
        {
            positionTexte.x = 20;
            positionTexte.y = 100+i*120;

            strcpy(labelColonneTypes,tabTypesBat[i].nomType);
            strcat(labelColonneTypes, "s");

            EcrireTexte(labelColonneTypes, 25, positionTexte, "default.ttf");

            nbBat = parametre->nombreInstanceBateaux[i];
            for(j=0;j<nbBat;j++)
            {
                AfficherChamp(tabChamp[i][j]);
                afficherRectangle(tabRectChoixCoul[i][j]);
            }
        }

        SDL_Flip(SDL_GetVideoSurface());

        AttendreEvent(positionClic, NULL);

        for(i=0;i<K_NBTYPEBATEAUX;i++)
        {
            nbBat = parametre->nombreInstanceBateaux[i];
            for(j=0;j<nbBat;j++)
            {
                if(ClicSurChamp(tabChamp[i][j], positionClic))
                {
                    ChangeFocus(tabChamp[i][j], CHAMP_ACTIF);
                    EditerChamp(tabChamp[i][j]);
                }
                else if(clicSurRectangle(tabRectChoixCoul[i][j], positionClic))
                    incrCouleurRectangle(tabRectChoixCoul[i][j]);
            }
        }

        if(ClicSurBouton(boutonAnnuler, positionClic))

            continuer = 0;
        else if(ClicSurBouton(boutonValider, positionClic))
        {
            for(i=0;i<K_NBTYPEBATEAUX;i++)
            {
                nbBat = parametre->nombreInstanceBateaux[i];
                for(j=0;j<nbBat;j++)
                {
                    setInfoBateau(&(parametre->bateauxJoueur[getNumBat(i, j, parametre)]), tabChamp[i][j]->chaine, tabRectChoixCoul[i][j]->couleur, i);
                }
            }
            continuer = 0;
        }
        else
        {
            afficherCoordClic(positionClic, 20, 0, 650, "default.ttf");
            SDL_Flip(SDL_GetVideoSurface());
        }
    }

    LibererBouton(boutonValider);
    LibererBouton(boutonAnnuler);

    for(i=0;i<K_NBTYPEBATEAUX;i++)
    {
        nbBat = parametre->nombreInstanceBateaux[i];
        for(j=0;j<nbBat;j++)
        {
            LibererChamp(tabChamp[i][j]);
            libererRectangle(tabRectChoixCoul[i][j]);
        }

        free(tabChamp[i]);
        free(tabRectChoixCoul[i]);
    }
    free(tabChamp);

    free(tabRectChoixCoul);

    free(positionClic);
}
