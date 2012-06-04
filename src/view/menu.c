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

#include "../test/test.h"
#include "../test/view/testVue.h"

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
    
    positionTexte.x = 223;
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

Tparam * MenuNouvellePartie(void)
{
	ChampSaisie * champPseudoHumain, * champPseudoIA;
	int continuer = 1;
	SDL_Rect positionBoutonOK, positionBoutonParam, positionTexte;
	SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
	SDL_Bouton * boutonOK;
	SDL_Bouton * boutonParam;
	//Image * imageFond = CreerImage("menuNouvellePartie.png", 0, 0);
	Tparam * paramPartie;

	int controleEvent;

	champPseudoHumain = CreerChamp(30, 20, 230, 150);
	champPseudoIA = CreerChamp(30, 20, 230, 200);

	positionBoutonParam.x = 230;
	positionBoutonParam.y = 300;
	boutonParam = CreerBouton("Plus de parametres", &positionBoutonParam, 25);
	positionBoutonOK.x = 230;
	positionBoutonOK.y = 350;
	boutonOK = CreerBouton("Demarrer la partie", &positionBoutonOK, 25);


	InitTexte(champPseudoHumain, "Anonyme");
	InitTexte(champPseudoIA, "GlaDos");

	while (continuer)
	{
        EffacerEcran();
		//AfficherImage(imageFond);
        positionTexte.x = 300;
        positionTexte.y = 15;
        EcrireTexte("Nouvelle Partie", 50, positionTexte, "default.ttf");
        positionTexte.x = 10;
        positionTexte.y = 150;
        EcrireTexte("Pseudo Humain :", 26, positionTexte, "default.ttf");
        positionTexte.x = 10;
        positionTexte.y = 200;
        EcrireTexte("Pseudo IA :", 26, positionTexte, "default.ttf");

		AfficherChamp(champPseudoHumain);
		AfficherChamp(champPseudoIA);
		AfficherBouton(boutonOK);
		AfficherBouton(boutonParam);
		SDL_Flip(SDL_GetVideoSurface());

		controleEvent = AttendreEvent(positionClic, touche);

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

			else if(ClicSurBouton(boutonOK, positionClic))
			{
				EcranGrille(champPseudoHumain);
			}

		}

		if(controleEvent == 2 && ToucheSpec(touche) == SDLK_ESCAPE)
			continuer = 0;
	}

	free(positionClic);
	free(touche);
	LibererChamp(champPseudoHumain);
	LibererChamp(champPseudoIA);
	LibererBouton(boutonOK);
	LibererBouton(boutonParam);
	//LibererImage(imageFond);

	return paramPartie;
}

Tparam * MenuParam(void)
{


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
