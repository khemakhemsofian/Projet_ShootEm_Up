#include "Game.h"

Game::Game(RenderWindow& win) : window(win) {}


void Game::run()
{
    while (window.isOpen())
    {
        Event _event;
        while (window.pollEvent(_event)) 
        {
            event(_event);
        }
        // update(); 
        rendu();
       
    }
}


void Game::event(Event& _event)
{
   
    
}

void Game::rendu()
{
    window.clear(); // Ajout de la fonction de nettoyage
  
    window.display(); // Affichage des changements
}

