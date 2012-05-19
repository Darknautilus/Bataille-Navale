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

void AfficherMenuAccueil(void)
{
	int continuer = 1;

	SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));

	ImageFond("Images/menuAccueil.png");
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

	free(touche);
}

int AfficherMenuRacine(void)
{
    SDL_Rect positionPuce;
    int continuer = 1;
    int choixMenu = 1;

    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));

    positionPuce.x = 80;
    positionPuce.y = 150;
	
	SDL_EnableUNICODE(SDL_ENABLE);

    while(continuer)
    {
        ImageFond("Images/menuRacine.png");

        AfficherImage("Images/puceMenu.png", positionPuce);

        SDL_Flip(SDL_GetVideoSurface());

        AttendreEvent(NULL, touche);

        if(ToucheChar(touche) == 't')
            MenuTestVue();
		
        switch(ToucheSpec(touche))
        {
            case SDLK_RETURN:
                continuer = 0;
            break;

            case SDLK_UP:
                if(choixMenu != 1)
                {
                    choixMenu --;
                    positionPuce.y -= 60;
                }
            break;

            case SDLK_DOWN:
                if(choixMenu != 5)
                {
                    choixMenu ++;
                    positionPuce.y += 60;
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

	free(touche);

	return choixMenu;
}

void MenuNouvellePartie(void)
{
	ChampSaisie * champPseudoHumain, * champPseudoIA;
	int continuer = 1;
	SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
	int controleEvent;

	champPseudoHumain = CreerChamp(30, 30, 230, 150);
	champPseudoIA = CreerChamp(30, 30, 230, 200);

	InitTexte(champPseudoHumain, "Anonyme");
	InitTexte(champPseudoIA, "GlaDos");

	while (continuer)
	{
		ImageFond("Images/menuNouvellePartie.png");
		ImageRetour("Images/flecheRetour.png");

		EcrireTexte("Appuyez sur Entree pour continuer", 30, 270, 400);

		AfficherChamp(champPseudoHumain);
		AfficherChamp(champPseudoIA);
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

			else if(ClicSurRetour(positionClic))
			{
				continuer = 0;
			}
		}

		else if(controleEvent == 2)
		{
			if(ToucheSpec(touche) == SDLK_ESCAPE)
				continuer = 0;

			else if(ToucheSpec(touche) == SDLK_RETURN)
				EcranGrille(champPseudoHumain);
		}
	}

	free(positionClic);
	free(touche);
	LibererChamp(champPseudoHumain);
	LibererChamp(champPseudoIA);
}

void EcranGrille(ChampSaisie * champ)
{
    Grille * grilleJoueur;
    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    int controleEvent;
    Coord coord;
    CaseGrille caseGrille;

    int continuer = 1;


    grilleJoueur = CreerGrille(10, 10);

    EffacerEcran();
    afficherGrille(grilleJoueur, 40, 100);

    EcrireTexte(champ->chaine, 40, 40, 20);

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

    free(touche);
    free(positionClic);
}
