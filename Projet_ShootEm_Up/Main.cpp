#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "Menu.h"
#include <iostream>
#include "GameScene.h"
#include "OptionScene.h"

using namespace sf;
using namespace std;
int main()
{
    // ertyuuyshgfgf
    //iiiiiiiiii hg
    RenderWindow _window; 
 
    _window.create(VideoMode::getDesktopMode(), "A knight journey ", Style::Fullscreen);
	_window.setFramerateLimit(60);
    Game _game(_window);
    GameScene _gameScene(_game, _window);


   


   
   
    OptionScene* _optionScene;

    bool _inMenu = true;
    bool _inOptions = false;
    bool _inGame= false;

    Texture _backGroundTexture;

    if (!_backGroundTexture.loadFromFile("Assets/Image/BackGround_image0.jpeg")) {
        return -1;
    }

    Sprite _backgroundSprite(_backGroundTexture);
    _backgroundSprite.setScale(
        static_cast<float>(_window.getSize().x) / _backGroundTexture.getSize().x,
        static_cast<float>(_window.getSize().y) / _backGroundTexture.getSize().y
    );

    Menu _menu(_window.getSize().x, _window.getSize().y);
    _optionScene = new OptionScene(_window.getSize().x, _window.getSize().y);
   
    // Boucle principale
    while (_window.isOpen()) {
        Event event;

        while (_window.pollEvent(event)) {
            if (event.type == Event::Closed)
                _window.close(); 
        }

        if (event.type == Event::MouseMoved)
        {
            Vector2f _mousePosition = _window.mapPixelToCoords(Vector2i(event.mouseMove.x, event.mouseMove.y));
            _menu.selectOption(_mousePosition);
        }
        if (_inMenu)
        {
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                Vector2f _mousePosition = _window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
                _menu.selectOption(_mousePosition);
                int _selected = _menu.getSelectedIndex();
                switch (_selected)
                {
                case 0:
                    cout << "Nouvelle Partie sélectionnée" << endl;
                    _inMenu = false;
                    _inGame = true;
                  
                    break;
                case 1:
                    cout << "Options sélectionnées" << endl;
                    _inMenu = false; 
                    _inOptions = true; 
                    _inGame = false; 
                    break;
                case 2:
                    cout << "Quitter le jeu" << endl;
                    _window.close();
                    break;
                }
            }
           
        }
        else if(_inOptions)
        {
            _optionScene->handleEvents(event, _window);
        }
        else 
        {
            
            _gameScene.run();
            
        }
      
     
        _window.clear();
        if (_inMenu)
        {
            
            _window.draw(_backgroundSprite);
             _menu.draw(_window);
            if (event.type == Event::MouseMoved) {
                Vector2f _mouseposition = _window.mapPixelToCoords(Vector2i(event.mouseMove.x, event.mouseMove.y));
                _menu.UpdateEffetSurvol(_mouseposition);
            }
            
            
            
   
        }
        else if(_inOptions)
        {
            _optionScene->draw(_window);
        }
        
        
  
        _window.display();
    }
    
    delete _optionScene;
    return 0;
}