// Permet la portabilité du programme
#include "includeSDL.h"


#include "vueUtilsSDL.h"
#include "utilsSDL.h"

void ImageFond(char * cheminImage)
{
	SDL_Surface * imageFond;
	SDL_Rect positionFond;

	// Pour que l'image couvre tout l'écran
	positionFond.x = 0;
	positionFond.y = 0;

	// On charge l'image et on la colle à l'écran
	imageFond = IMG_Load(cheminImage);
	SDL_BlitSurface(imageFond, NULL, SDL_GetVideoSurface(), &positionFond);

	SDL_FreeSurface(imageFond);
}

void ImageRetour(char * cheminImage)
{
	SDL_Surface * imageRetour;
	SDL_Rect positionImageRetour;

	positionImageRetour.x = KABSRETOUR;
	positionImageRetour.y = KORDRETOUR;

	imageRetour = IMG_Load(cheminImage);
	SDL_BlitSurface(imageRetour, NULL, SDL_GetVideoSurface(), &positionImageRetour);

	EcrireTexte("RETOUR", 35, KABSRETOUR + 30, KORDRETOUR);

	SDL_FreeSurface(imageRetour);
}

void AfficherImage(char * cheminImage, SDL_Rect positionImage)
{
	SDL_Surface * image;

	image = IMG_Load(cheminImage);

	SDL_BlitSurface(image, NULL, SDL_GetVideoSurface(), &positionImage);
	SDL_FreeSurface(image);
}

void EcrireCar(char car,int taille, int abscisse, int ordonnee)
{
	SDL_Surface * zoneTexte;
	TTF_Font * police = TTF_OpenFont("Fonts/apple.ttf", taille);
	SDL_Color couleur = {255,255,255};
	SDL_Rect position;

	position.x = abscisse;
	position.y = ordonnee;

	zoneTexte = TTF_RenderUTF8_Blended(police, &car, couleur);
	SDL_BlitSurface(zoneTexte, NULL, SDL_GetVideoSurface(), &position);
	SDL_FreeSurface(zoneTexte);

	TTF_CloseFont(police);
}

void EcrireTexte(char * texte,int taille, int abscisse, int ordonnee)
{
	SDL_Surface * zoneTexte;
	TTF_Font * police = TTF_OpenFont("Fonts/apple.ttf", taille);
	SDL_Color couleur = {255,255,255};
	SDL_Rect position;

	position.x = abscisse;
	position.y = ordonnee;

	zoneTexte = TTF_RenderUTF8_Blended(police, texte, couleur);
	SDL_BlitSurface(zoneTexte, NULL, SDL_GetVideoSurface(), &position);
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
	return (char)(touche->unicode);
}

SDLKey ToucheSpec(SDL_keysym * touche)
{
	return touche->sym;
}

void EffacerEcran(void)
{
	SDL_FillRect(SDL_GetVideoSurface(), NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, 0, 0, 0));
}



