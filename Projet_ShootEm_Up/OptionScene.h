#ifndef OPTIONSCENE_H
#define OPTIONSCENE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class OptionScene
{
public:
    OptionScene(float width, float height);
    void handleEvents(sf::Event& event, sf::RenderWindow& window);
   // void update(float deltaTime);
    void draw(sf::RenderWindow& window);
	

private:

};


#endif // !OPTIONSCENE_H

