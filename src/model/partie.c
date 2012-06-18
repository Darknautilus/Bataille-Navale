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

Pile partie_PileCoups()
{
    return globalPartie->pileCoups;
}

Grille * partie_Grille()
{
    return globalPartie->grille;
}

Grille * partie_GrilleMachine()
{
    return globalPartie->grilleMachine;
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
    partie->grilleMachine = CreerGrille(10, 10);

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


    //Traiter pile de coup
    //Modifier etat bateau
    //Vérifier les règles
    //  - Bateau touché => coulé

    //On ajoute le coup à la pile de coups
    Joueur *joueur = partie->joueur;
    Coup *tir = CreerCoup(joueur, cible);
    globalPartie->pileCoups = Empiler(globalPartie->pileCoups, tir);




}

void libererPartie(void)
{
    int i;
    int nombreBateaux = getNbBat(partie_Param());

    for(i=0;i<nombreBateaux;i++)
    {
        LibererBateau(partie_JHumain()->mesBateaux[i]);
        LibererBateau(partie_JMachine()->mesBateaux[i]);
    }

    LibererJoueur(partie_JHumain());
    LibererJoueur(partie_JMachine());
    LibererGrille(partie_Grille());
    libererParam(partie_Param());

    while(!PileVide(partie_PileCoups()))
        Depiler(partie_PileCoups());

    free(globalPartie);
}
