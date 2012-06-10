#ifndef RANDOM_H
#define RANDOM_H

#include <stdio.h>

void initRandom(void);

int nombreAleatoire(int pNbMin, int pNbMax);

void choixMotHasard(char * pMot, FILE * pDesc, int longMax);

#endif