/**
\page presGen Présentation Générale

\tableofcontents

Vous voici dans la Bataille-Navale, développée par deux étudiants en 1ère année de DUT Informatique à l'IUT de Blagnac. Nous allons essayer de vous présenter brièvement ce projet.

\section commentJoueur Comment Jouer ?

Avant de pouvoir vous éclater à couler les navires de l'ordinateur, vous aurez quelques actions à effectuer.<br/>
Le Menu principal vous propose plusieurs possibilités de jeu : Nouvelle Partie ou Chargement

\subsection nouvPart Nouvelle Partie

Vous devez tout d'abord choisir combien de bateaux de chaque type vous aurez. Pour des raisons techniques, il n'est pas possible d'avoir plus de 6 bateaux de chaque type, mais vous pourrez tout autant vous amuser ! Il vous faudra ensuite cliquer sur le bouton "Plus de paramètres" pour choisir le nom et la couleur de chaque bateau. Cliquez sur le carré de couleur pour les faire défiler, vous ne pourrez laisser la couleur à Blanc et le nom à "Nom :".<br/>
De retour à l'écran de paramétrage, vous pourrez enregistrer ces paramètres pour pouvoir les réutiliser plus tard, ou les passer à vos amis. Les paramètres sont dans le répertoire ressources/ et paramUser.dat contient les paramètres que vous enregistrez. paramOrigin contient des paramètres par défaut qu'on vous déconseille de changer (ils permettent de jouer rapidement avec de beaux bateaux bien nommés). Vous pourrez d'ailleurs charger tels ou tels paramètres dans l'écran de paramétrage.<br/>
<br/>
Vient ensuite le placement des bateaux. Vous devrez sélectionner chaque bateau en cliquant sur son nom et le placer dans la grille. Vous pouvez changer son sens en cliquant sur le bouton "Sens". Si tout se passe bien, le bouton "OK" devrait apparaître. Une fois un bateaux placé, vous ne pourrez pas revenir en arrière. Une fois que tous les bateaux sont placés, vous êtes amenés à l'écran de jeu.

\subsection chargPart Charger une Partie

En sélectionnant cette option, vous serez redirigé directement sur l'écran de jeu avec les paramètres contenus dans le fichier (ressources/saves/partieUser.dat).

\subsection ecranJeu Écran de jeu

L'écran de jeu est sans doute la partie la plus intéressante du jeu. Vous avez à gauche votre grille et à droite celle de la machine. Votre mission sera de cliquer dans la grille de la machine pour lui porter des coups. Une croix bleue signifie "Manqué" et une croix rouge signifie "Touché". Lorsqu'un bateau est coulé, il est entièrement coloré en rouge foncé. À tout moment vous pouvez annuler le dernier coup en cliquant sur le bouton correspondant.<br/>
En appuyant sur Échap vous accédez au menu Pause. Le menu Pause vous permet d'enregistrer la partie à un instant donné pour pouvoir la reprendre plus tard. Vous pouvez également quitter la partie (Attention, toute évolution non sauvegardée sera perdue).<br/>
Lorsque la partie est terminée, vous ne pouvez plus jouer ni annuler un coup et êtes redirigé vers un écran de fin correspondant au résultat de la partie.

\section explGen Explications générales

Ce programme a entièrement été développé en C à l'aide de la bibliothèque SDL. Il est donc en mode graphique fenêtré avec prise en charge du clavier et de la souris. L'utilisateur navigue dans le jeu au travers de différents écrans et à l'aide de plusieurs objets d'interface.<br/>
Les boutons par exemple sont représentés par des rectangles gris et sont cliquables ou non selon les circonstances. Souvent la touche Escape (Échap) est utilisable pour revenir à l'écran précédent.

\section explTech Explications techniques

La majeure partie du temps passé l'est dans l'attente d'un événement (clavier ou souris). Ainsi l'affichage d'un écran va toujours se diviser en plusieurs phases :
<ol>
	<li>Déclaration des variables locales</li>
	<li>Affectation des variables locales</li>
	<li>Entrée dans une boucle "infinie", affichage des éléments et attente d'un événement</li>
	<li>Analyse de l'événement et sortie de la boucle (sinon on revient au point précédent)</li>
	<li>Libération de la mémoire</li>
</ol>

 



*/