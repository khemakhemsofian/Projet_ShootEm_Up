#include "Game.h"

Game::Game() : window(VideoMode::getDesktopMode(), "A knight journey Game", Style::Fullscreen) {}


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
        drawPlayer(window.getSize().x, window.getSize().y);
    }
}

void Game::drawPlayer(float width, float height)
{
    _player.setRadius(30.0f);
    _player.setFillColor(Color(47, 255, 126, 230));
    _player.setPosition(width / 2 - _player.getRadius(), height / 2 - _player.getRadius());
}

void Game::event(Event& _event)
{
   
        if (_event.type == Event::KeyPressed)
        {
            if (_event.key.code == Keyboard::Z)
            {
                _player.move(0, -10);
            }
            else if (_event.key.code == Keyboard::S)
            {
                _player.move(0, 10);
            }
            else if (_event.key.code == Keyboard::Q)
            {
                _player.move(-10, 0);
            }
            else if (_event.key.code == Keyboard::D)
            {
                _player.move(10, 0);
            }
        }
    
}

void Game::rendu()
{
    window.clear(); // Ajout de la fonction de nettoyage
    window.draw(_player); // Dessin du joueur
    window.display(); // Affichage des changements
}

