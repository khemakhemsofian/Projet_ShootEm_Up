#include "Menu.h"

Menu::Menu(float _width, float _height)
{
	if (!_MenuFront.loadFromFile("Assets/Font/MedievalMystery.ttf"))
	{
		cerr << "Erreur de chargement de la police" << endl;
	}
	_backgroundMenu.setSize(Vector2f(_width/2,_height/2));
	_backgroundMenu.setFillColor(Color(153,76,0,153));
	vector<string> _MenuContainer = {"Faire festin de jeu" , "Les besognes de choix", "Abandonner la joute"};
	_selectedIndex = 0;
	for (size_t i = 0; i < _MenuContainer.size(); i++)
	{
		Text _TextMenu;

		_TextMenu.setFont(_MenuFront);
		_TextMenu.setString(_MenuContainer[i]);
		_TextMenu.setCharacterSize(24);
		_TextMenu.setPosition(_width/2 - _TextMenu.getGlobalBounds().width/ 2 , _height / (_MenuContainer.size() + 1)* (i + 1 ));
		_selectTextMenu.push_back(_TextMenu);
	}
}

void Menu::draw(RenderWindow& _window)
{
	for (const auto& _drawMenu : _selectTextMenu)
	{
		_window.draw(_drawMenu);
	}
}

void Menu::moveUp()
{
	if (_selectedIndex - 1 >= 0 )
	{
		_selectedIndex--;
	}
}void Menu::moveDown()
{
	if (_selectedIndex + 1 < _selectTextMenu.size())
	{
		_selectedIndex++;
	}
}

int Menu::getSelectedIndex()
{
	return _selectedIndex;
}

void Menu::selectOption(Vector2f mousePosition)
{
	for (size_t i = 0; i < _selectTextMenu.size(); i++)
	{
		if(_selectTextMenu[i].getGlobalBounds().contains(mousePosition))
		{
			_selectedIndex = i;
			break;
		}
	}
}

void Menu::UpdateEffetSurvol(Vector2f mousePosition)
{
	for (size_t i = 0; i < _selectTextMenu.size(); i++)
	{
		if(_selectTextMenu[i].getGlobalBounds().contains(mousePosition))
		{
			_selectTextMenu[i].setFillColor(Color(255, 51, 10, 230));
			_selectTextMenu[i].setScale(1.2f,1.2f);
		}
		else
		{
			_selectTextMenu[i].setFillColor(Color(0, 0, 0, 230));
			_selectTextMenu[i].setScale(1.0f, 1.0f);
		}
	}
}