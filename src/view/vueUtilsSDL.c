#include "VueUtilsSDL.h"

// Permet la portabilité du programme
#include "includeSDL.h"

#include "../ctrl/UtilsSDL.h"
#include "../ctrl/UtilsPoliceEcriture.h"

#include "../model/ChampSaisie.h"

#include "../view/SDLImage.h"

void ecranVictoire(void)
{
    int continuer = 1;
    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    int controleEvent;
    Image * imageCaptain;
    Image * imageClavier;
    SDL_Rect positionTexte;
    
    imageCaptain = CreerImage("captain.png", 446, 389);
    imageClavier = CreerImage("clavier.png", 300, 600);
    
    while (continuer)
    {
        EffacerEcran();
        AfficherImage(imageCaptain);
        AfficherImage(imageClavier);
        positionTexte.x = 278;
        positionTexte.y = 230;
        EcrireTexte("VICTOIRE !", 100, positionTexte, "default.ttf");
        positionTexte.x = 380;
        positionTexte.y = 625;
        EcrireTexte("Espace", 30, positionTexte, "default.ttf");
        SDL_Flip(SDL_GetVideoSurface());
        
        controleEvent = AttendreEvent(positionClic, touche);
        
        if(controleEvent == 2 && ToucheSpec(touche) == SDLK_SPACE)
        {
            continuer = 0;
        }
        else if(controleEvent == 1)
        {
            afficherCoordClic(positionClic, 20, 0, 650, "default.ttf");
            SDL_Flip(SDL_GetVideoSurface());
        }
    }
    
    LibererImage(imageCaptain);
    free(touche);
    free(positionClic);
}

void EcrireTexte(char * texte, int taille, SDL_Rect positionTexte, char * cheminPolice)
{
    int longTexte = strlen(texte);
    char * nouvTexte = (char*)malloc((longTexte+1)*sizeof(char)); // chaine de travail
    
    int i = 0;
    
    // On initialise la chaine de travail
    strcpy(nouvTexte, "");
    
    // On parcourt la chaine principale caractère par caractère
    while(texte[i] != '\0')
    {
        // Si c'est un saut de ligne, on écrit la ligne et on passe à la suivante
        if(texte[i] == '\n')
        {
            EcrireLigneTexte(nouvTexte, taille, positionTexte, cheminPolice);
            positionTexte.y += taille;
            strcpy(nouvTexte, "");
        }
        // Sinon, on ajoute le caractère à la chaine de travail (ligne en cours)
        else
        {
            AjouterCharFin(nouvTexte, texte[i]);
        }
        
        // On passe au caractère suivant et si l'on est à la fin, on écrit la ligne.
        i++;
        if(texte[i] == '\0')
            EcrireLigneTexte(nouvTexte, taille, positionTexte, cheminPolice);
    }
    
    // Libération chaine de travail
    free(nouvTexte);
}

void EcrireLigneTexte(char * texte,int taille, SDL_Rect positionTexte, char * cheminPolice)
{
	SDL_Surface * zoneTexte;
	TTF_Font * police = chargerPoliceEcriture(cheminPolice, taille);
	SDL_Color couleur = {255,255,255};
    
	zoneTexte = TTF_RenderUTF8_Blended(police, texte, couleur);
	SDL_BlitSurface(zoneTexte, NULL, SDL_GetVideoSurface(), &positionTexte);
	SDL_FreeSurface(zoneTexte);
    
	TTF_CloseFont(police);
}

int AttendreEvent(SDL_Rect * coordClic, SDL_keysym * touche)
{
	SDL_Event event;
	int continuer = 1;
	int controle;// Permet de retourner si l'événement est un clic ou une touche

	while(continuer)
	{
		// On attend que quelque chose se passe
		SDL_WaitEvent(&event);
		// Si c'est un clic gauche et qu'on a activé l'option
		if (event.type == SDL_MOUSEBUTTONDOWN && coordClic != NULL && event.button.button == SDL_BUTTON_LEFT)
		{
			coordClic->x = event.button.x;
			coordClic->y = event.button.y;
			controle = 1;
			continuer = 0;
		}

		// Si c'est une touche et qu'on a activé l'option
		else if(event.type == SDL_KEYDOWN && touche != NULL)
		{
			* touche = event.key.keysym;
			controle = 2;
			continuer = 0;
		}

		// Si l'utilisateur a fait n'importe quoi
		else if(coordClic == NULL && touche == NULL)
			continuer = 0;

		// Si l'utilisateur veut quitter brutalement
		else if(event.type == SDL_QUIT)
			exit(EXIT_FAILURE);
	}

    return controle;
}

char ToucheChar(SDL_keysym * touche)
{
    char charTouche;

    charTouche = (char)(touche->unicode);

	return charTouche;
}

SDLKey ToucheSpec(SDL_keysym * touche)
{
	return touche->sym;
}

Uint32 convertSDL_Color(SDL_Color pCouleur)
{

	return SDL_MapRGB(SDL_GetVideoSurface()->format, pCouleur.r, pCouleur.g, pCouleur.b);
}

void afficherCoordClic(SDL_Rect * pPosClic, int pTaille, int pAbs, int pOrd, char * pPolice)
{
    SDL_Rect posTexte;
    char texte[25];
    
    sprintf(texte, "x : %d ; y : %d", pPosClic->x, pPosClic->y);
    
    posTexte.x = pAbs;
    posTexte.y = pOrd;
    EcrireLigneTexte(texte, pTaille, posTexte, pPolice);
}

void pause(void)
{
	int continuer = 1;
	SDL_Event event;
    
	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				exit(EXIT_FAILURE);
                break;
                
			case SDL_KEYDOWN:
				continuer = 0;
                break;
        }
    }
    
}

void EffacerEcran(void)
{
	SDL_FillRect(SDL_GetVideoSurface(), NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, 0, 0, 0));
}



