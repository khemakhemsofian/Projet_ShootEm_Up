#ifndef MENU_H
#define MENU_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

class Menu
{
public:
	Menu(float _width,float _height);
	void draw(RenderWindow& _window);
	void moveUp();
	void moveDown();
	int getSelectedIndex();
	void selectOption(Vector2f mousePosition);
	void UpdateEffetSurvol(Vector2f mousePosition);
protected:
	RectangleShape _backgroundMenu;
	vector<Text> _selectTextMenu;
	int _selectedIndex;
	Font _MenuFront;
};

#endif // !MENU_H

