Document de Game Design : A knight journey 
1. Informations Générales
Titre : A knight journey 
Genre : Shoot'em Up (Shmup)
Style Visuel : Pixel Art thème médieval.
Plateforme(s) : PC.
Public cible : Amateurs de jeux d’arcade et de défis rapides, âgés de 12 ans et plus.
Résumé :
Dans un monde ravagé par les ténèbres, vous incarnez un valeureux chevalier, dernier défenseur du royaume, chargé de restaurer la paix en affrontant des hordes de créatures maléfiques  qui dévastent les terres et menacent l'humanité. Armé de votre épée légendaire, de  vôtre arc de légende et du bouclier mystique, combattez dans des batailles frénétiques aux multiples decord.

3. Concept de Base
Gameplay principal : Le joueur contrôle un chevalier, détruit des vagues d’ennemis et évite des projectiles pour progresser dans les niveaux.
Objectifs :
Court terme : Survivre et accumuler des points en détruisant les ennemis.
Long terme : Compléter les niveaux, vaincre les boss et sauver le royaume.
Déroulement : Le jeu est divisé en plusieurs niveaux avec une difficulté croissante, chacun se terminant par un combat de boss unique.
Style de progression : Défilement verticale automatique, avec des phases de répit pour acheter des power-ups et réorganiser ses stratégies.

4. Méchaniques de Jeu
3.1. Contrôle du joueur
Déplacement : Mouvement en 8 directions à l’aide des touches directionnelles (clavier/souris).
Tir principal : Clic gauche de la souris
Tir secondaire : Maintenir clique droit pour une attaque chargée
Esquive/dash : Timer de recharge de 15 seconde et 40 seconde avec bombe
shield: permet de parer x attaque des mobs et une attaque de boss tous les x temps

3.2. Système de Scoring
Systéme de gold: tous les 3 enemis porcentage de drop du gold
Systéme de suivi du nb d'énemeis éliminée

3.3. Power-ups
Systéme de marchand a chaque fin de vague
Dash :
-laisse une bombe après un dash, augmente le cooldown de 40sec
-cooldow réduit
Arme :
arme de glaçe :
ralentit les enemies
arme de feu:
brule les enemies, dot de x degât
arme electrique :
stun les enemis
Boosts défensifs :
bouclier:
cooldown reduit
cape de vitalité :
soigne x de vie tout les x temps

3.4. Difficulté
Modes de jeu :
Adaptation dynamique : Plus le joueur avance dans les vague plus le jeu devient difficile.
Hardcore : Plus de mob qui sont plus tanki, erreurs non pardonnées. pour les joueur plus expérimenté

5. Conception des Ennemis
4.1. Types d’ennemis
Niveau 1
Gobelin:
Faible santé, attaque au corp, plutot rapide.

Niveau 2:
squellette :
encaisse plus les dégats tire a distance

Niveau 3:
orc : 
tank, enfliche plus de dégat, lent mais peut charger le joueur à partir d'une certainne distance

Niveau 4:
demon mage:
tire a distance et invoque des attaques sur le joueur dirrectement

demon de base:
tank, peut esquiver les attaques en dash cooldown de 10 sec

demon volant:
tres rapide tuable a l'arc uniquement

4.2. Boss
Chaque niveau se termine par un boss avec des mécaniques uniques :

Niveau 1 : Roi des gobelins
Arme principale : Marteau attaque en spirale finit sur une aoe cooldown de 10 sec
Pattern : Lent, créer des degat de zonne autour de son sprite, saute sur le joueur 3 fois après deux attaque échouée au marteau
Niveau 2 : Roi maudit
Arme principale : Arc qui tire une flêche imense dans la direction du joueur, cooldown de 5sec.
Pattern : Tir rapide mais ne bouge pas, après avoir perdu la moitié de sa vie il fait pleuvoir des flêches sur une zonne donné.
Niveau 3 : Seigneur Mordok
Arme principal : Hache de guerre orc plus bouclier, enchaine un combot de 3 attaque lorsque sur le joueur
Pattern: active un mode rage qui lui permet de dash 3 fois d'affiler sur le joueur, s'active toutes les 20 secondes, il faut d'abord faire tomber la vie de son shield pour qu'il soit stun, pendant 5 sec, et lui faire des dégats. Il récupére ensuite la vie de son shield et rebelotte.
Niveau 4: Seigneur démoniaque
Arme principal : Magie, copie les attaque des anciens boss
PAttern : poséde 4 phases, les 3 premières correspondent aux 3 boss d'avant. Sa dernière phase il se tp sur le joueur, invoque des boules de feu a tete chercheuse et genere des rayons de lave autour de lui qu'il fait tourner dans le sens qu'il veut


5. Progression et Structure
5.1. Niveaux
Niveau 1 : Plainne
Thème : valon, prairie a la fin camp de gobelin.
Introduction aux ennemis simples.
Niveau 2 : Vallée des mort.
Thème : bois mort, marrais et cimetiere a la fin.
Nouveaux ennemis : squellete tire a distance.
Niveau 3 : Forterresse orc.
Thème : Bbliotéque, salle de banquet, salle du trône.
Ajout de mob plus tanki.
Niveau 4 : Les enfer
thème : les enfers, forterrese infernal
ajout de mobs volant

5.2. Rythme
Les niveaux alternent entre moments d’action intense et phases de récupération pour maintenir l'intérêt du joueur.
Équilibrage entre l’introduction de nouveaux ennemis et des mécaniques innovantes.
7. Direction Artistique
6.1. Style Visuel
Pixel art médieval fantasy.

6.2. Interface utilisateur
HUD :
Score et gold en haut à droite
Barre de vie du joueur en haut à gauche.
Cooldown du dash en bas a gauche
Compétence en bat a gauche
Arme en main en haut a gauche

8. Direction Audio
7.1. Musique
Theme medieval posé pour les menus du jeu.
musique plus entrainante pour les combats
Musique a théme pour chaque boss.
7.2. Effets sonores
Sons distincts pour les tirs, le dash, les explosions, bruit a l'achat, bruit pour selection d'un menu.
Signal audio pour les attaques spéciales des boss.

10. Systèmes et Outils
8.1. Moteur de Jeu
SFML

8.2. Logiciels Recommandés
Pixel art : Pixel et itch.io.
Audio : IA suno.

12. Monétisation
Modèle principal : Jeu premium avec achat unique.
Contenu additionnel (DLC) :
Niveaux supplémentaires avec de nouveaux ennemis et boss.

14. Inspirations
Le royaume d'Eryndor (livre n'ont officiel, écrit par Duncan Melloul et ses collaborateurs)
