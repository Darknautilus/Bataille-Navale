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

    //Création des structures et ajout des id (commencent à 0)
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

    Joueur *joueur = NULL;
    Coup *tir = NULL;
    TBateau *bateauCible = NULL;
    int idCible = -1;
    int indexCaseBateauTouche;

    //===========================================================================

    //
    // On récupère la cible.
    //

    //Si c'est le joueur qui tire, la cible est sur la grille de la machine
    if(estJoueur){
        idCible = getIdBateauSurCase(partie->grilleMachine, cible);
        joueur = partie->joueur;
    }
    //Sinon on tire sur la grillle du joueur
    else{
        idCible = getIdBateauSurCase(partie->grille, cible);
        joueur = partie->machine;
    }

    //===========================================================================

    //
    // On ajoute le coup à la pile des coups
    //

    tir = CreerCoup(joueur, cible);
    globalPartie->pileCoups = Empiler(globalPartie->pileCoups, tir);

    //===========================================================================

    //
    // Traitement des effets du tir
    //

    //Si il n'y a pas de bateau, le tir ne touche personne
    if(idCible < 0){
        //actions à faire quand case vide touchée
        return 0;
    }
    else{
        //Si on touche un bateau
        bateauCible = getBateauFromId(idCible);

        //On détermine quelle case du bateau toucher

        //Si le bateau est horizontal on calcule l'index de la case à toucher.
        if(bateauCible->position.direction == HORIZONTAL){
            indexCaseBateauTouche = cible.noCol-bateauCible->position.x;
        }
        //Si le bateau est vertical
        else{
            indexCaseBateauTouche = cible.noLin-bateauCible->position.y;
        }

        //On modifie la case touchée par le tir (etat touché)
        toucherBateau(bateauCible, indexCaseBateauTouche);

        return 1;
    }

}

int partieEstFinie(TPartie *partie){

}

void libererPartie(TPartie *partie)
{
    int i;
    int nombreBateaux = getNbBat(partie->parametres);

    for(i=0;i<nombreBateaux;i++)
    {
        LibererBateau(partie->joueur->mesBateaux[i]);
        LibererBateau(partie->machine->mesBateaux[i]);
    }

    LibererJoueur(partie->joueur);
    LibererJoueur(partie->machine);
    LibererGrille(partie->grille);
    LibererGrille(partie->grilleMachine);
    libererParam(partie->parametres);

    while(!PileVide(partie->pileCoups))
        Depiler(partie->pileCoups);

    free(partie);
}
