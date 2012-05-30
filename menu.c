// Permet la portabilité du programme
#include "includeSDL.h"

#include "menu.h"
#include "champSaisie.h"
#include "vueChampSaisie.h"
#include "utilsSDL.h"
#include "vueUtilsSDL.h"
#include "vueGrille.h"
#include "testVue.h"
#include "test.h"
#include "vueBateau.h"
#include "SDLButton.h"
#include "SDLImage.h"

void AfficherMenuAccueil(void)
{
	int continuer = 1;
	Image * imageFond = CreerImage("Images/menuAccueil.png", 0, 0);

	SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));

	AfficherImage(imageFond);

	SDL_Flip(SDL_GetVideoSurface());

	while(continuer)
	{
		AttendreEvent(NULL, touche);

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

	LibererImage(imageFond);
	free(touche);
}

int AfficherMenuRacine(void)
{
    int continuer = 1;
    int choixMenu = 1;

    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));

	Image * imageFond = CreerImage("Images/menuRacine.png", 0, 0);
	Image * imagePuce = CreerImage("Images/puceMenu.png", 80, 150);

	SDL_EnableUNICODE(SDL_ENABLE);

    while(continuer)
    {
        AfficherImage(imageFond);
        AfficherImage(imagePuce);

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

	LibererImage(imageFond);
	LibererImage(imagePuce);
	free(touche);

	return choixMenu;
}

Tparam * MenuNouvellePartie(void)
{
	ChampSaisie * champPseudoHumain, * champPseudoIA;
	int continuer = 1;
	SDL_Rect positionBoutonOK, positionBoutonParam;
	SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
	SDL_Bouton * boutonOK;
	SDL_Bouton * boutonParam;
	Image * imageFond = CreerImage("Images/menuNouvellePartie.png", 0, 0);
	Tparam * paramPartie;

	int controleEvent;

	champPseudoHumain = CreerChamp(30, 30, 230, 150);
	champPseudoIA = CreerChamp(30, 30, 230, 200);

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
		AfficherImage(imageFond);

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
	LibererImage(imageFond);

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

    EcrireTexte(champ->chaine, 40, positionTexte);

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
