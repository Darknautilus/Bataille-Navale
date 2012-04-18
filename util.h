#ifndef _UTIL_H
#define _UTIL_H
#include <time.h>
#include <stdlib.h>


#include <stdio.h>

#include <conio.h>


#include <unistd.h>
#include <windows.h>
#include "lietrec.h"
#include "coniocouleur.h"

//initialisation de la source du générateur automatique de valeurs aléatoires avec l'heure

void initRandom(void);

//création d'une fenètre en mode console avec le titre du jeu
int initConsoleJeu();

#endif
