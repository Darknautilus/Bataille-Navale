#ifndef JOUEUR_H
#define JOUEUR_H

#define KLGNOMJ 25

typedef enum {HUMAIN,MACHINE} IdJoueur;

typedef struct
{
	IdJoueur idJ;
	char nomJ[KLGNOMJ];
}Joueur;

Joueur * nouvJoueur(void);

int getIDJoueur(const Joueur * pJoueur);

char * getNomJoueur(Joueur * pJoueur);

void LibererJoueur(Joueur * pJoueur);


#endif