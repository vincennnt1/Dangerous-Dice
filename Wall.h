#pragma once

#include <SFML/Graphics.hpp>

class Wall
{
private:
	sf::Sprite wall;


public:

	Wall(sf::Texture* text, int posX, int posY);
	virtual ~Wall();

	// FUNCTIONS

	void render(sf::RenderTarget& target);

	// accessors
	const sf::FloatRect getGlobalBounds() const;

};

