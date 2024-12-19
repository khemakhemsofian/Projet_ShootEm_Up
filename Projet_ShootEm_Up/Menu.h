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
	void ClickSound();
	void playMusic();
	void stopMusic();
protected:
	RectangleShape _backgroundMenu0;
	RectangleShape _backgroundMenu1;
	RectangleShape _backgroundMenu2;
	RectangleShape _backgroundMenu3;
	vector<Text> _selectTextMenu;
	int _selectedIndex;
	Font _MenuFront;
	Music _MenuMusic;
	SoundBuffer clickSoundBuffer;
	Sound clickSound;
	
};

#endif // !MENU_H

