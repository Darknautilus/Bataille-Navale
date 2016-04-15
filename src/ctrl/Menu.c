#include "ctrl/Menu.h"

#include "ctrl/UtilsSDL.h"
#include "ctrl/FichierDebug.h"
#include "ctrl/UtilsModel.h"

#include "model/ChampSaisie.h"
#include "model/Partie.h"
#include "model/Bateau.h"
#include "model/Parametre.h"
#include "model/Random.h"
#include "model/Couleurs.h"

#include "view/IncludeSDL.h"
#include "view/VueChampSaisie.h"
#include "view/VueUtilsSDL.h"
#include "view/VueGrille.h"
#include "view/VueBateau.h"
#include "view/SDLButton.h"
#include "view/SDLImage.h"
#include "view/SDLRectangle.h"
#include "view/VueSDLMsgBox.h"

#include "test/Test.h"
#include "test/view/TestVue.h"

#include <string.h>

void afficherMenuAccueil(void)
{
	int continuer = 1;
    SDL_Rect positionTexte;

    Rectangle * rectLogos;

    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));

    rectLogos = creerRectangle(10, 10, 231, 110);

    Image * imageIUT = creerImage("iutBlagnac.jpg", 15, 15);
    Image * imageUniv = creerImage("univMirail.gif", 115, 15);
    Image * imageBateau = creerImage("bateau.png", 454, 418);

    // --------------------------------------------------------------------

    afficherRectangle(rectLogos);

    positionTexte.x = 219;
    positionTexte.y = 282;
    ecrireTexte("Bataille Navale", 70, positionTexte, "default.ttf");

    positionTexte.x = 15;
    positionTexte.y = 700;
    ecrireTexte("Par Aurelien Bertron\net Benoit Sauvere", 20, positionTexte, "default.ttf");

    positionTexte.x = 240;
    positionTexte.y = 539;
    ecrireTexte("Appuyez sur espace pour continuer", 25, positionTexte, "default.ttf");


    afficherImage(imageIUT);
    afficherImage(imageUniv);
    afficherImage(imageBateau);

	SDL_Flip(SDL_GetVideoSurface());

    // --------------------------------------------------------------------

	while(continuer)
	{
		attendreEvent(NULL, touche);

        switch(toucheSpec(touche))
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

    // --------------------------------------------------------------------

    libererImage(imageIUT);
    libererImage(imageUniv);
    libererImage(imageBateau);
    libererRectangle(rectLogos);
	free(touche);
}

int afficherMenuRacine(void)
{
    int continuer = 1;
    int choixMenu = 1;

    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));

	Image * imagePuce = creerImage("puceMenu.png", 100, 200);

    SDL_Rect positionTexte;

	SDL_EnableUNICODE(SDL_ENABLE);

    // --------------------------------------------------------------------

    while(continuer)
    {
        effacerEcran();
        afficherImage(imagePuce);

        positionTexte.x = 170;
        positionTexte.y = 210;
        ecrireTexte("- Nouvelle Partie", 30, positionTexte, "default.ttf");
        positionTexte.y += 60;
        ecrireTexte("- Charger Partie", 30, positionTexte, "default.ttf");
        positionTexte.y += 60;
        ecrireTexte("- Meilleurs Scores", 30, positionTexte, "default.ttf");
        positionTexte.y += 60;
        ecrireTexte("- Afficher Regles", 30, positionTexte, "default.ttf");
        positionTexte.y += 60;
        ecrireTexte("- Quitter", 30, positionTexte, "default.ttf");

        SDL_Flip(SDL_GetVideoSurface());

        // --------------------------------------------------------------------

        attendreEvent(NULL, touche);

        if(toucheChar(touche) == 't')
            menuTestVue();
        else if(toucheChar(touche) == 'y')
            menuTest();

        switch(toucheSpec(touche))
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

    // --------------------------------------------------------------------

	SDL_EnableUNICODE(SDL_DISABLE);

	libererImage(imagePuce);
	free(touche);

	return choixMenu;
}

int menuNouvellePartie(Tparam * parametre)
{
    // Champs de saisie
	ChampSaisie * champPseudoHumain, * champPseudoIA;
    ChampSaisie * paramNbBat[K_NBTYPEBATEAUX]; // Choix du nombre de bateaux (tableau de champs)

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

    // Autres
    int continuer = 1;
    int i, j;

    int nbInstChange = 1;
    int nbBat;
    FILE * descFicParam;

	int nbInstTemp;
    int * nbInstancesbat;
    char chaineInstance[3];
    char nomBatIA[K_LGNOM];

    int partiePrete = 0;

    // --------------------------------------------------------------------

    // Initialisation des champs de saisie
	champPseudoHumain = creerChamp(30, 20, 230, 150);
	champPseudoIA = creerChamp(30, 20, 230, 200);
    initTexte(champPseudoHumain, "Anonyme");
	initTexte(champPseudoIA, "GlaDos");

    // Champs du nombre d'instances de chaque bateaux : récupération des valeurs déjà paramétrées et initialisation des champs
    nbInstancesbat = getNBInstances(parametre);
    for(i=0;i<K_NBTYPEBATEAUX;i++)
    {
        paramNbBat[i] = creerChamp(2, 20, 279, 372+i*40);
    }

    for(i=0;i<getNbBat(parametre);i++)
    {
        strcpy(parametre->bateauxJoueur[i].nomBateau, "Nom :");
        parametre->bateauxJoueur[i].couleur = 0;
    }

    // Positionnement des boutons
	positionBouton.x = 360;
	positionBouton.y = 622;
	boutonParam = creerBouton("Plus de parametres", &positionBouton, 25);
	positionBouton.x = 360;
	positionBouton.y = 682;
	boutonOK = creerBouton("Demarrer la partie", &positionBouton, 25);
    positionBouton.x = 630;
    positionBouton.y = 389;
    boutonChargerParam = creerBouton("Utiliser parametres par defaut", &positionBouton, 20);
    positionBouton.x = 630;
    positionBouton.y = 330;
    boutonEnregistrerParam = creerBouton("Enregistrer les parametres", &positionBouton, 20);
    positionBouton.x = 630;
    positionBouton.y = 480;
    boutonRetablirDefaut = creerBouton("Retablir parametres d'origine", &positionBouton, 20);

    // --------------------------------------------------------------------

	while (continuer)
	{
        // Affichage de tous les objets
        effacerEcran();
        positionTexte.x = 300;
        positionTexte.y = 15;
        ecrireTexte("Nouvelle Partie", 50, positionTexte, "default.ttf");
        positionTexte.x = 10;
        positionTexte.y = 150;
        ecrireTexte("Pseudo Humain :", 26, positionTexte, "default.ttf");
        positionTexte.x = 10;
        positionTexte.y = 200;
        ecrireTexte("Pseudo IA :", 26, positionTexte, "default.ttf");
        positionTexte.x = 86;
        positionTexte.y = 297;
        ecrireTexte("Nombre de bateaux (6 max):", 25, positionTexte, "default.ttf");

		afficherChamp(champPseudoHumain);
		afficherChamp(champPseudoIA);

        // Champs pour le choix du nombre d'instance de chaque type
        for(i=0;i<K_NBTYPEBATEAUX;i++)
        {
            positionTexte.x = 89;
            positionTexte.y = 372+i*40;
            ecrireTexte(tabTypesBat[i].nomType, 25, positionTexte, "default.ttf");
            sprintf(chaineInstance, "%d", nbInstancesbat[i]);
            initTexte(paramNbBat[i], chaineInstance);
            afficherChamp(paramNbBat[i]);
        }

		if(!nbInstChange)
			afficherBouton(boutonOK);

		afficherBouton(boutonParam);
        afficherBouton(boutonChargerParam);
        afficherBouton(boutonEnregistrerParam);
        afficherBouton(boutonRetablirDefaut);

		SDL_Flip(SDL_GetVideoSurface());


        // Traitement de l'événement
		controleEvent = attendreEvent(positionClic, touche);

        // Événement souris
		if(controleEvent == 1)
		{
			if(clicSurChamp(champPseudoHumain, positionClic))
			{
				editerChamp(champPseudoHumain);
			}

			else if(clicSurChamp(champPseudoIA, positionClic))
			{
				editerChamp(champPseudoIA);
			}

            else if(clicSurBouton(boutonParam, positionClic))
            {
                if(nbInstChange)
                    resetInfoBateau(parametre);

                menuParam(parametre);

                if(infoBateauValide(parametre))
                   nbInstChange = 0;
            }

			else if(clicSurBouton(boutonOK, positionClic))
			{

                if(!nbInstChange)
                {
                    descFicParam = ouvrirFichierRessources("dicoNoms.dat", "r");

                    nbBat = 0;
                    for(i=0;i<K_NBTYPEBATEAUX;i++)
                    {
                        for(j=0;j<nbInstancesbat[i];j++)
                        {
                            choixMotHasard(nomBatIA, descFicParam, K_LGNOM);
                            setInfoBateau(&(parametre->bateauxMachine[nbBat]), nomBatIA, 0, tabTypesBat[i].typeBat);
                            nbBat++;

                        }
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

                    partiePrete = 1;
                    continuer = 0;
                }
                else
                {
                    // TODO: Boite Message (non finalise)
                }



			}
            else if(clicSurBouton(boutonEnregistrerParam, positionClic))
            {
                if(!nbInstChange)
                {
                    descFicParam = ouvrirFichierRessources("paramUser.dat", "w");
                    memParam(parametre, descFicParam);
                    fclose(descFicParam);
                }
            }
            else if(clicSurBouton(boutonChargerParam, positionClic))
            {
                descFicParam = ouvrirFichierRessources("paramUser.dat", "r");
                resetInfoBateau(parametre);
                chargerParam(descFicParam, parametre);
                fclose(descFicParam);
                nbInstChange = 0;
            }
            else if(clicSurBouton(boutonRetablirDefaut, positionClic))
            {
                descFicParam = ouvrirFichierRessources("paramOrigin.dat", "r");
                resetInfoBateau(parametre);
                chargerParam(descFicParam, parametre);
                fclose(descFicParam);
                nbInstChange = 0;
            }
            else
            {
                for(i=0;i<K_NBTYPEBATEAUX;i++)
                {
                    if(clicSurChamp(paramNbBat[i], positionClic))
                    {
                        changeFocus(paramNbBat[i], CHAMP_ACTIF);
                        editerChamp(paramNbBat[i]);

						// Si le nombre d'instances est erroné, n'enregistre pas les modifs
						nbInstTemp = strtol(paramNbBat[i]->chaine, NULL, 10);
						if(nbInstTemp > 0 && nbInstTemp <= 6)
						{
							parametre->nombreInstanceBateaux[i] = nbInstTemp;
							nbInstChange = 1;
						}
                    }
                }
                afficherCoordClic(positionClic, 20, 0, 650, "default.ttf");
                SDL_Flip(SDL_GetVideoSurface());
            }

		}

        // Événement clavier
		if(controleEvent == 2 && toucheSpec(touche) == SDLK_ESCAPE)
			continuer = 0;
	}

    // --------------------------------------------------------------------

	free(positionClic);
	free(touche);
	libererChamp(champPseudoHumain);
	libererChamp(champPseudoIA);
	libererBouton(boutonOK);
	libererBouton(boutonParam);
    libererBouton(boutonChargerParam);
    libererBouton(boutonEnregistrerParam);
    libererBouton(boutonRetablirDefaut);

    for(i=0;i<K_NBTYPEBATEAUX;i++)
    {
        libererChamp(paramNbBat[i]);
    }

    return partiePrete;
}

void menuParam(Tparam * parametre)
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

            tabChamp[i][j] = creerChamp(K_LGNOM, 15, absInfoBat+30, ordInfoBat);
            tabRectChoixCoul[i][j] = creerRectangle(absInfoBat, ordInfoBat, 25, 25);

            if(j < parametre->nombreInstanceBateaux[i])
            {
                strcpy(tabChamp[i][j]->chaine, parametre->bateauxJoueur[getNumBat(i, j, parametre)].nomBateau);
                tabRectChoixCoul[i][j]->couleur = parametre->bateauxJoueur[getNumBat(i, j, parametre)].couleur;
            }
            else
                strcpy(tabChamp[i][j]->chaine, "Nom :");
        }
    }

    positionBouton.x = 303;
    positionBouton.y = 682;
    boutonValider = creerBouton("Valider", &positionBouton, 25);
    positionBouton.x = 500;
    positionBouton.y = 682;
    boutonAnnuler = creerBouton("Annuler", &positionBouton, 25);

    // --------------------------------------------------------------------

    while (continuer)
    {
        effacerEcran();
        afficherBouton(boutonValider);
        afficherBouton(boutonAnnuler);

        positionTexte.x = 259;
        positionTexte.y = 10;
        ecrireTexte("Noms et couleurs des bateaux", 35, positionTexte, "default.ttf");

        for(i=0;i<K_NBTYPEBATEAUX;i++)
        {
            positionTexte.x = 20;
            positionTexte.y = 100+i*120;

            strcpy(labelColonneTypes,tabTypesBat[i].nomType);
            strcat(labelColonneTypes, "s");

            ecrireTexte(labelColonneTypes, 25, positionTexte, "default.ttf");

            nbBat = parametre->nombreInstanceBateaux[i];
            for(j=0;j<nbBat;j++)
            {
                afficherChamp(tabChamp[i][j]);
                afficherRectangle(tabRectChoixCoul[i][j]);
            }
        }

        SDL_Flip(SDL_GetVideoSurface());

        // --------------------------------------------------------------------

        attendreEvent(positionClic, NULL);

        for(i=0;i<K_NBTYPEBATEAUX;i++)
        {
            nbBat = parametre->nombreInstanceBateaux[i];
            for(j=0;j<nbBat;j++)
            {
                if(clicSurChamp(tabChamp[i][j], positionClic))
                {
                    changeFocus(tabChamp[i][j], CHAMP_ACTIF);
                    editerChamp(tabChamp[i][j]);
                }
                else if(clicSurRectangle(tabRectChoixCoul[i][j], positionClic))
                    incrCouleurRectangle(tabRectChoixCoul[i][j]);
            }
        }

        if(clicSurBouton(boutonAnnuler, positionClic))
            continuer = 0;

        else if(clicSurBouton(boutonValider, positionClic))
        {
            for(i=0;i<K_NBTYPEBATEAUX;i++)
            {
                nbBat = parametre->nombreInstanceBateaux[i];
                for(j=0;j<nbBat;j++)
                {
                    setInfoBateau(&(parametre->bateauxJoueur[getNumBat(i, j, parametre)]), tabChamp[i][j]->chaine, tabRectChoixCoul[i][j]->couleur, i+1);
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

    // --------------------------------------------------------------------

    libererBouton(boutonValider);
    libererBouton(boutonAnnuler);

    for(i=0;i<K_NBTYPEBATEAUX;i++)
    {
        nbBat = parametre->nombreInstanceBateaux[i];
        for(j=0;j<nbBat;j++)
        {
            libererChamp(tabChamp[i][j]);
            libererRectangle(tabRectChoixCoul[i][j]);
        }

        free(tabChamp[i]);
        free(tabRectChoixCoul[i]);
    }
    free(tabChamp);

    free(tabRectChoixCoul);

    free(positionClic);
}
