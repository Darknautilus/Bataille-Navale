/**
 *   \file partie.c
 *   \author Benoit Sauvere
 *   \date 19 juin 2012
 *   \brief Module Partie
 *
 *   Contient le module de gestion de la partie.
*/


#include "partie.h"

#include "bateau.h"
#include "grille.h"

TPartie *globalPartie = NULL;

Joueur * partie_JHumain(){
    return globalPartie->joueur;
}

Joueur * partie_JMachine(){
    return globalPartie->machine;
}

Tparam * partie_Param(){
    return globalPartie->parametres;
}

Pile partie_PileCoups(){
    return globalPartie->pileCoups;
}

Grille * partie_Grille(){
    return globalPartie->grille;
}

Grille * partie_GrilleMachine(){
    return globalPartie->grilleMachine;
}

int partie_Score(){
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

    Coup *tir = NULL;
    TBateau *bateauCible = NULL;
    Grille *grilleCible = NULL;
    CaseGrille *caseGrille = NULL;
    int idCible = -1;
    int i;
    int indexCaseBateauTouche;

    //===========================================================================

    //
    // On récupère la cible.
    //

    //Si c'est le joueur qui tire, la cible est sur la grille de la machine
    if(estJoueur){
        grilleCible = partie->grilleMachine;
        idCible = getIdBateauSurCase(grilleCible, cible);
        tir = CreerCoup(HUMAIN, cible);
    }
    //Sinon on tire sur la grillle du joueur
    else{
        grilleCible = partie->grille;
        idCible = getIdBateauSurCase(grilleCible, cible);
        tir = CreerCoup(MACHINE, cible);
    }

    //On récupère la case cible
    caseGrille = Consulter(grilleCible, cible);

    //===========================================================================

    //
    // On ajoute le coup à la pile des coups
    //


    globalPartie->pileCoups = Empiler(globalPartie->pileCoups, tir);

    //===========================================================================

    //
    // Traitement des effets du tir
    //

    //Si il n'y a pas de bateau, le tir ne touche personne
    if(idCible < 0){

        //On place la case à "à l'eau"
        caseGrille->etatCase = GRILLE_CASE_EAU;

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

        //Si le bateau est coulé
        if(estCoule(bateauCible)){
            //On place toute ses cases à "coulé"
            i = 0;

            //On place la première coordonnée
            cible.noCol = bateauCible->position.x;
            cible.noLin = bateauCible->position.y;

            while(i < getTypeBateau(bateauCible)){
                //On place la case à touché
                Consulter(grilleCible, cible)->etatCase = GRILLE_CASE_COULE;

                if(bateauCible->position.direction == HORIZONTAL){
                    cible.noCol = cible.noCol+1;
                }
                else{
                    cible.noLin = cible.noLin+1;
                }

                i++;
            }
        }
        //Sinon il est juste touché
        else{
            //On modifie la case à "touché"
            caseGrille->etatCase = GRILLE_CASE_TOUCHE;
        }

        return 1;
    }

}

int partieEstFinie(TPartie *partie){

    int etatPartie = 0;
    int i = 0;
    int nbBateaux;
    int nbCouleJoueur, nbCouleMachine;

    //
    //On recherche un joueur dont tout les bateaux sont coulé
    //

    //On récupère le nombre de bateau par joueur
    nbBateaux = getNbBat(partie->parametres);

    //Compteur de bateaux touchés
    nbCouleJoueur = 0;
    nbCouleMachine = 0;

    //On parcourt les id de bateaux
    while(etatPartie == 0 && i < nbBateaux){

        //Si un bateau du joueur est coulé
        if(getBateauFromId(i)->etat[0] == COULE){
            nbCouleJoueur++;
        }

        //Si un bateau de la machine est coulé
        if(getBateauFromId(i+nbBateaux)->etat[0] == COULE){
            nbCouleMachine++;
        }

        i++;
    }

    //Si tout les bateaux du joueur sont coulé
    //La machine gagne
    if(nbCouleJoueur == nbBateaux){
        return -1;
    }
    //Si tout les bateaux de la machine sont coulé
    //Le joueur gagne
    else if(nbCouleMachine == nbBateaux){
        return 1;
    }

    //Si aucun des deux n'a perdu.
    return 0;
}

void annulerDernierCoup(TPartie *partie){







}



void libererPartie(TPartie *partie){
    int i;
    int nombreBateaux = getNbBat(partie->parametres);

    //On libère tout les bateaux
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

    //On libère la pile de coups
    while(!PileVide(partie->pileCoups))
        Depiler(partie->pileCoups);

    free(partie);
}
