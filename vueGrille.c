



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


#include <unistd.h>
#include <windows.h>
#include "lietrec.h"
#include "coniocouleur.h"
#define KDELTAX 4
#define KDELTAY 2


void afficherGrille(int px, int py, int pnbLignes, int pnbColonnes, COLORS pCouleur)
{
    int i;
    textcolor(YELLOW);

    //affiche colonne chiffres
    for (i=0;i<pnbLignes;i++)
    {
        gotoxy(px-2, py+1+KDELTAY*i);
        cprintf("%c",'A' + i);
    }

    //affiche ligne chiffres
     for (i=0;i<pnbColonnes;i++)
    {
        gotoxy(px+1+KDELTAX*i, py-1);
        cprintf("%d",i+1);
    }

    //trace rectangle
    tracerRectangle(px, py, KDELTAX*pnbColonnes, KDELTAY*pnbLignes);

    //trace lignes horizontales
    for (i=2;i<=pnbLignes;i++)
    {
        tracerLigneH(px, py-2+KDELTAY*i,KDELTAX*pnbColonnes);
    }
    for (i=1;i<=pnbColonnes;i++)
    {
        gotoxy(KDELTAX*i, py-3);
      //  cprintf("%d",i-1);
        tracerLigneV(KDELTAX*i+px-KDELTAX, py+1, KDELTAY*pnbLignes-1);
    }
}
void afficherCaractereDansGrille(COLORS pcouleurCaractere,COLORS pcouleurFond,char pcaractere,int  ppositionXGrille,int ppositionYGrille,int pligne,int pcolonne)
{
    char text[4];
    text[0]=' ';
    text[1]=pcaractere;
    text[2]=' ';
    text[3]='\0';
    textcolor((pcouleurCaractere)|(pcouleurFond<<4));
    gotoxy(  ppositionXGrille+(pcolonne-1)*KDELTAX+1, ppositionYGrille +(pligne-1)*KDELTAY+1);
    cprintf("%s",text);
}

void afficherToutEnTest()
{
    int haut =10;
    int gauche =20;


    gotoxy( gauche,haut/2);
    textcolor((BLACK)|(LIGHTCYAN<<4));
    cprintf("%s","mettre le nom du joueur");
    afficherGrille(gauche,haut,10,10,YELLOW );
    afficherGrille(gauche + 80 ,haut,10,10,YELLOW );

    afficherCaractereDansGrille(BLACK, LIGHTCYAN, 'A', gauche, haut, 1, 5);

    afficherCaractereDansGrille (WHITE,LIGHTRED,'*',gauche, haut, 4,6);
}


/*
int afficherGrille()
{

    char c;
    int i;
    int ligne,colonne;


    textcolor(YELLOW);

    // afficher les paramètres de la partie
    //afficherParam(&param);
  //  scanf("%c",&c);
    clrscr();

    //affiche colonne chiffres
     for (i=0;i<=9;i++)
    {
        gotoxy(1, 4+2*i);
        cprintf("%c",'A' + i);

    }

        //affiche ligne chiffres
     for (i=0;i<=9;i++)
    {
        gotoxy(4+3*i, 2);
        cprintf("%d",i+1);

    }

    //trace rectangle
    tracerRectangle(3, 3, 30, 20);




    //trace lignes horizontales
    for (i=2;i<=10;i++)
    {
        tracerLigneH(3, 1+2*i, 30);
    }


    for (i=1;i<=10;i++)
    {
        gotoxy(3*i, 0);
      //  cprintf("%d",i-1);
        tracerLigneV(3*i, 4, 19);
    }

    return 0;
}
*/
