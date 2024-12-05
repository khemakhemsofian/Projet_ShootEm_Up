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
Arme principale : Arc qui tire une flêche imense générant une aoe lorsqu'elle touche le sol.
Pattern : Boucle d’attaques à zone large nécessitant des esquives précises.

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

5.2. Rythme
Les niveaux alternent entre moments d’action intense et phases de récupération pour maintenir l'intérêt du joueur.
Équilibrage entre l’introduction de nouveaux ennemis et des mécaniques innovantes.
7. Direction Artistique
6.1. Style Visuel
Pixel art rétro combiné avec des effets modernes (glow, particules).
Palette de couleurs évoluant selon les niveaux :
Niveau 1 : Tons froids (bleu, gris).
Niveau 2 : Couleurs vives et métalliques (orange, argent).
Niveau 3 : Palette sombre avec accents néon (vert, violet).
6.2. Interface utilisateur
HUD :
Score en haut à gauche.
Barre de vie du joueur en bas à gauche.
Indicateurs de power-ups et bombes en bas à droite.
8. Direction Audio
7.1. Musique
Rythmes électroniques rapides pour les phases d’action.
Musique plus lourde et dramatique pour les combats de boss.
7.2. Effets sonores
Sons distincts pour les tirs, les explosions, et les power-ups.
Signal audio pour les attaques spéciales des boss ou les situations dangereuses.
9. Systèmes et Outils
8.1. Moteur de Jeu
SFML
8.2. Logiciels Recommandés
Pixel art : Aseprite pour les sprites et animations.
Audio : Bfxr pour les effets sonores, Ableton Live pour la musique.
10. Monétisation
Modèle principal : Jeu premium avec achat unique.
Contenu additionnel (DLC) :
Niveaux supplémentaires avec de nouveaux ennemis et boss.
Packs de skins pour le vaisseau.
11. Inspirations
Ikaruga : Patterns de tir complexes et gameplay stratégique.
Jamestown : Style rétro et modes multijoueurs.
Galaga : Simplicité et focus sur le scoring.
