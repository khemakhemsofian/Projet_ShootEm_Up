#include "Game.h"

Game::Game(RenderWindow& win ) : window(win) {}


void Game::run()
{
    while (window.isOpen())
    {
        Event _event;
       
        while (window.pollEvent(_event)) 
        {
            event(_event);
        }
        rendu();
        loadResources();
         update(); 
       
    }
}


void Game::event(Event& _event)
{
   
    
}

void Game::update()
{
    const float speeds[4] = { 100.0f, 150.0f, 200.0f, 250.0f };
    float deltaTime = clock.restart().asSeconds();

    for (int i = 0; i < 4; ++i) {
        // Mettre à jour l'offset de fond en fonction de la vitesse
        backgroundOffsets[i] += speeds[i] * deltaTime;

        // Calcul de l'échelle
        float scaleX = static_cast<float>(window.getSize().x) / static_cast<float>(backgroundTextures[i].getSize().x);
        float scaleY = static_cast<float>(window.getSize().y) / static_cast<float>(backgroundTextures[i].getSize().y);
        float scale = min(scaleX, scaleY);

        // Appliquer l'échelle à la texture
        backgroundSprites[i].setScale(scale, scale);

        // Positionner le premier fond à gauche
        backgroundSprites[i].setPosition(
            (window.getSize().x - backgroundTextures[i].getSize().x * scale) / 2.f - backgroundOffsets[i],
            (window.getSize().y - backgroundTextures[i].getSize().y * scale) / 2.f
        );

        // Positionner le second fond à droite
        backgroundSprites[i + 4].setScale(scale, scale); // Assurez-vous que vous avez un tableau de sprites avec 2 instances pour chaque fond.
        backgroundSprites[i + 4].setPosition(
            (window.getSize().x - backgroundTextures[i].getSize().x * scale) / 2.f - backgroundOffsets[i] + backgroundTextures[i].getSize().x * scale,
            (window.getSize().y - backgroundTextures[i].getSize().y * scale) / 2.f
        );

        // Réinitialiser l'offset si un fond dépasse
        if (backgroundOffsets[i] >= backgroundTextures[i].getSize().x * scale) {
            backgroundOffsets[i] = 0.0f;
        }
    }
}




void Game::loadResources()
{
    
    const string filenames[4] = {
        "Assets/Image/Jungle/1.Backround.png",
     
        "Assets/Image/Jungle/2.Trees_back.png",
      
        "Assets/Image/Jungle/3.Trees_front.png",
       
        "Assets/Image/Jungle/4.Ground.png"
       
    };

    for (int i = 0; i < 4; ++i) {
        if (!backgroundTextures[i].loadFromFile(filenames[i])) {
            throw runtime_error("Erreur de chargement de " + filenames[i]);
            
        }
        backgroundSprites[i].setTexture(backgroundTextures[i]);
        backgroundTextures[i].setRepeated(true);
     
     
    }
 
}

void Game::rendu()
{
    window.clear(); // Ajout de la fonction de nettoyage
  
    for (int i = 0; i < 4; ++i) {
        window.draw(backgroundSprites[i]);

        backgroundSprites[i].setPosition(backgroundSprites[i].getGlobalBounds().width - backgroundOffsets[i], 0);
        window.draw(backgroundSprites[i]);
    }
  
    window.display(); // Affichage des changements
}

