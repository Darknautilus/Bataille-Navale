#include "partie.h"

TPartie *globalPartie = NULL;

Joueur * partie_JHumain()
{
    return globalPartie->joueur;
}

Joueur * partie_JMachine()
{
    return globalPartie->machine;
}

Tparam * partie_Param()
{
    return globalPartie->parametres;
}

Pile * partie_PileCoups()
{
    return globalPartie->pileCoups;
}

Grille * partie_Grille()
{
    return globalPartie->grille;
}

int partie_Score()
{
    return globalPartie->scorePlayer;
}

TPartie* initialiser(Tparam *param){

    int i = 0;
    int nombreBateaux = 0;

    TPartie *partie = malloc (sizeof(TPartie));

    //=========== Initialisation / Allocation ===================

    partie->joueur = CreerJoueur();
    partie->machine = CreerJoueur();

    partie->grille = CreerGrille(10,10);

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
        
        partie->joueur->mesBateaux[i]->estPlace = 0;
        partie->machine->mesBateaux[i]->estPlace = 0;
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
