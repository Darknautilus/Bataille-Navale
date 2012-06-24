#include "Partie.h"

#include "../model/Bateau.h"
#include "../model/Grille.h"

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

    partie->joueur = creerJoueur();
    partie->machine = creerJoueur();

    partie->grille = creerGrille(10,10);
    partie->grilleMachine = creerGrille(10, 10);

    partie->parametres = param;

    partie->pileCoups = creerPile();

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
        partie->joueur->mesBateaux[i] = creerBateau();
        partie->machine->mesBateaux[i] = creerBateau();

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
        tir = creerCoup(HUMAIN, cible);
    }
    //Sinon on tire sur la grillle du joueur
    else{
        grilleCible = partie->grille;
        idCible = getIdBateauSurCase(grilleCible, cible);
        tir = creerCoup(MACHINE, cible);
    }

    //===========================================================================

    //
    // On ajoute le coup à la pile des coups
    //


    globalPartie->pileCoups = empiler(globalPartie->pileCoups, tir);

    //===========================================================================

    //
    // Traitement des effets du tir
    //

    //Si il n'y a pas de bateau, le tir ne touche personne
    if(idCible < 0){

        //On place la case à "à l'eau"
        setEtatCase(grilleCible, cible, GRILLE_CASE_EAU);

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
                setEtatCase(grilleCible, cible, GRILLE_CASE_COULE);

                if(bateauCible->position.direction == HORIZONTAL){
                    cible.noCol = cible.noCol+1;
                }
                else{
                    cible.noLin = cible.noLin+1;
                }

                i++;
            }

            return -1;
        }
        //Sinon il est juste touché
        else{
            //On modifie la case à "touché"
            setEtatCase(grilleCible, cible, GRILLE_CASE_TOUCHE);
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
        if(estCoule(getBateauFromId(i))){
            nbCouleJoueur++;
        }

        //Si un bateau de la machine est coulé
        if(estCoule(getBateauFromId(i+nbBateaux))){
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

void annulerDernierCoup(TPartie *partie)
{
	int i = 0;
	int idBatCase;
	Coup * dernierCoup;
	TBateau * bateauCible;
	TPosition positionBat;
	Coord positionCourante;

	// Récupération du sommet de la pile et remise à l'état normal

	// Machine ------

	dernierCoup = sommet(partie->pileCoups);
	idBatCase = getIdBateauSurCase(partie->grille, dernierCoup->coordTir);

	//Si il y a un bateau sur la case
	if(idBatCase >= 0)
	{
		bateauCible = getBateauFromId(idBatCase);
		positionBat = getPosBateau(bateauCible);

		positionCourante.noCol = positionBat.x;
		positionCourante.noLin = positionBat.y;

		// Si le bateau est coulé, on repasse tout à touché
		if(estCoule(bateauCible))
		{
			for(i=0;i<getTypeBateau(bateauCible);i++)
			{
				bateauCible->etat[i] = TOUCHE;

				if(positionBat.direction == HORIZONTAL)
					positionCourante.noCol += 1;
				else if(positionBat.direction == VERTICAL)
					positionCourante.noLin += 1;

				setEtatCase(partie->grille, positionCourante, GRILLE_CASE_TOUCHE);
			}
		}

		// On traite la case du coup à proprement parler

		positionCourante.noCol = positionBat.x;
		positionCourante.noLin = positionBat.y;

		if(positionBat.direction == HORIZONTAL)
			i = dernierCoup->coordTir.noCol - positionCourante.noCol;
		else if(positionBat.direction == VERTICAL)
			i = dernierCoup->coordTir.noLin - positionCourante.noLin;

		bateauCible->etat[i] = INTACT;

	}

	setEtatCase(partie->grille, dernierCoup->coordTir, GRILLE_CASE_NORMAL);

	// On dépile le coup
	partie->pileCoups = depiler(partie->pileCoups);


	// Joueur -------

	dernierCoup = sommet(partie->pileCoups);
	idBatCase = getIdBateauSurCase(partie->grilleMachine, dernierCoup->coordTir);

	if(idBatCase >= 0)
	{
		bateauCible = getBateauFromId(idBatCase);
		positionBat = getPosBateau(bateauCible);

		positionCourante.noCol = positionBat.x;
		positionCourante.noLin = positionBat.y;

		// Si le bateau est coulé, on repasse tout à touché
		if(estCoule(bateauCible))
		{
			for(i=0;i<getTypeBateau(bateauCible);i++)
			{
				bateauCible->etat[i] = TOUCHE;

				if(positionBat.direction == HORIZONTAL)
					positionCourante.noCol += 1;
				else if(positionBat.direction == VERTICAL)
					positionCourante.noLin += 1;

				setEtatCase(partie->grilleMachine, positionCourante, GRILLE_CASE_TOUCHE);
			}
		}

		// On traite la case du coup à proprement parler

		positionCourante.noCol = positionBat.x;
		positionCourante.noLin = positionBat.y;

		if(positionBat.direction == HORIZONTAL)
			i = dernierCoup->coordTir.noCol - positionCourante.noCol;
		else if(positionBat.direction == VERTICAL)
			i = dernierCoup->coordTir.noLin - positionCourante.noLin;

		bateauCible->etat[i] = INTACT;

	}

	setEtatCase(partie->grilleMachine, dernierCoup->coordTir, GRILLE_CASE_NORMAL);

	// On dépile le coup
	partie->pileCoups = depiler(partie->pileCoups);
}



void libererPartie(TPartie *partie){
    int i;
    int nombreBateaux = getNbBat(partie->parametres);

    //On libère tout les bateaux
    for(i=0;i<nombreBateaux;i++)
    {
        libererBateau(partie->joueur->mesBateaux[i]);
        libererBateau(partie->machine->mesBateaux[i]);
    }

    libererJoueur(partie->joueur);
    libererJoueur(partie->machine);
    libererGrille(partie->grille);
    libererGrille(partie->grilleMachine);
    libererParam(partie->parametres);

    //On libère la pile de coups
    while(!pileVide(partie->pileCoups))
        partie->pileCoups = depiler(partie->pileCoups);

    free(partie);
}
