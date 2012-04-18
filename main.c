#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


#include "util.h"
#include "bateau.h"
#include "parametre.h"
#include "vuev1.h"
#include "lietrec.h"
#include "vueGrille.h"

void controleurParametreVersionTest(Tparam *param)
{
    newTParam(1 , param);

    // boucles avec void newTParam(int pIdBateau , Tparam * pP, char pNom[], int pCouleur , EType pType) doit remplacer ce qui suit
    setIemeInfoBateauTParam(0 , param, "redon", 0 , remorqueur);
    setIemeInfoBateauTParam(1 , param, "peninou", 1 , porteAvion);
    setIemeInfoBateauTParam(2 , param, "canut", 2 , sousMarin);
    setIemeInfoBateauTParam(3, param , "caplain", 3 , cargot);
    setIemeInfoBateauTParam(4 , param , "bruel", 4 , remorqueur);
    setIemeInfoBateauTParam(5 , param , "inglebert", 5 , porteAvion);
    setIemeInfoBateauTParam(6 , param , "verdier", 0 , sousMarin);
    setIemeInfoBateauTParam(7 , param , "nonne", 1 , cargot);


}


int main()
{
    FILE * f;
    char c;


    Tparam param;
    initRandom();// pour initialiser la suite de valeurs aléatoires cf util.h

    controleurParametreVersionTest(&param);


    // afficher les paramètres de la partie
    afficherParam(&param);

    // sauver les paramètres de la partie dans un fichier essai.don
    f = fopen ("essai.don", "wb");
    if (f==NULL) exit (1);
    memParam(&param, f);
    fclose(f);

     //lire les paramètres sauves dans essai.don
    f = fopen ("essai.don", "rb");
    if (f==NULL) exit (1);
    chargerParam(f,&param);
    fclose(f);

    textcolor(YELLOW);

    // afficher les paramètres de la partie
    afficherParam(&param);
    scanf("%c",&c);
    clrscr();
    initConsoleJeu();

    // afficher les paramètres de la partie
    //afficherParam(&param);
  //  scanf("%c",&c);
    clrscr();

    afficherToutEnTest();

    gotoxy( 30,50);
    scanf("%c",&c);

    return 0;
}
