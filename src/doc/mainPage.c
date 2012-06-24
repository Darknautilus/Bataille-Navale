/**
@mainpage Installation et Compilation

<h1>Installation</h1>

<h2>Windows</h2>

<p>Ce programme utilise les bibliothèques SDL 1.2.15, SDL_image et SDL_ttf.<br/>
Toutes les DLL nécessaires à Windows sont incluses. Et doivent être placées dans le même dossier que l'exécutable.</p>

<h2>MacOS X</h2>

<p>Le programme se présente sous la forme d'un fichier .app et du dossier des ressources. Les deux doivent être placés dans le même répertoire.</p>

<hr/>

<h1>Compilation</h1>

<h2>Windows</h2>

<p>Pour pouvoir compiler, vous devez télécharger des fichiers spécifiques.<br/>
Attention, procédure pour Code::Blocks sur Windows :<br/>

<ul>
	<li>
		SDL :
		<ol>
			<li><a href="http://www.libsdl.org/release/SDL-devel-1.2.15-mingw32.tar.gz">Télécharger SDL</a></li>
			<li>Extraire l'archive dans un dossier (SDL-1.2.15 par défaut)</li>
			<li>Déplacez les fichiers de SDL-1.2.15\\include\\SDL dans SDL-1.2.15\\include</li>
			<li>Déplacez le dossier SDL-1.2.15 dans le répertoire d'installation de Code::Blocks</li>
			<li>Créez un projet SDL dans Code::Blocks</li>
			<li>Une fois à la fenêtre "Global Variable Editor", dans le champ "base", chercher le dossier<répertoire installation Code::Blocks>\\SDL-1.2.15</li>
			<li>Ignorez les avertissements ou les fenêtres, continuer normalement.</li>
		</ol>
	</li>
	<li>
		SDL_image :
		<ol>
			<li><a href="http://www.libsdl.org/projects/SDL_image/release/SDL_image-devel-1.2.12-VC.zip">Télécharger SDL_image</a></li>
			<li>Dézippez tout</li>
			<li>SDL_image.h va dans <répertoire installation Code::Blocks>\\SDL-1.2.15\\include</li>
			<li>SDL_image.lib va dans <répertoire installation Code::Blocks>\\SDL-1.2.15\\lib</li>
			<li>Dans Code::Blocks allez dans les paramètres du linker</li>
			<li>Ajoutez le fichier SDL_image.lib</li>
		</ol>
	</li>
	<li>
		SDL_ttf :
		<ol>
			<li><a href="http://www.libsdl.org/projects/SDL_ttf/release/SDL_ttf-devel-2.0.11-VC.zip">Télécharger SDL_ttf</a></li>
			<li>SDL_ttf.h va dans <répertoire installation Code::Blocks>\\SDL-1.2.15\\include</li>
			<li>SDL_ttf.lib va dans <répertoire installation Code::Blocks>\\SDL-1.2.15\\lib</li>
			<li>Ajoutez le .lib aux paramètres du linker comme pour SDL_image</li>
		</ol>
	</li>
</ul>
</p>

<p>Le programme a besoin de toutes les DLL fournies avec ce code source, elles devront également être fournies avec l'exécutable.</p>

<h2>MacOS X</h2>

<p>Procédure pour XCode :<br/>

	À venir
</p>

<hr/>

<p>Si vous rencontrez des difficultés, écrivez-moi : aurelienbertron[AT]gmail[DOT]com</p>

*/