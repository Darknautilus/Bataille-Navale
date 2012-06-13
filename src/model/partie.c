#include "partie.h"

TPartie *globalPartie = NULL;

TPartie* initialiser(Tparam *param){

    int i = 0;
    int nombreBateaux = 0;

    TPartie *partie = malloc (sizeof(TPartie));

    //=========== Initialisation / Allocation ===================

    partie->joueur = CreerJoueur();
    partie->machine = CreerJoueur();

    partie->grille = CreerGrille(KLARGCASE, KHAUTEURCASE);

    partie->parametres = param;

    partie->pileCoups = CreerPile();

    partie->scorePlayer = 0;

    //On compte le nombre de bateaux à allouer
    nombreBateaux = getNbBat(param);

    //On alloue
    partie->joueur->mesBateaux = malloc( sizeof(TBateau*) * nombreBateaux );
    partie->machine->mesBateaux = malloc( sizeof(TBateau*) * nombreBateaux );

    //=========== Préparation ===================================

    //Préparation des bateaux

    //Création des structures et ajout des id
    for(i = 0 ; i < nombreBateaux ; i++){
        partie->joueur->mesBateaux[i] = CreerBateau();
        partie->machine->mesBateaux[i] = CreerBateau();

        partie->joueur->mesBateaux[i]->idBateau = i;
        partie->machine->mesBateaux[i]->idBateau = i + nombreBateaux;
    }


    return partie;

}


int jouerUnCoup(TPartie *partie, Coord cible, int estJoueur){





}

void libererPartie(TPartie * pPartie)
{
    free(pPartie->joueur->mesBateaux);
    free(pPartie->machine->mesBateaux);
}
