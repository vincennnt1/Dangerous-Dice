#pragma once

#include <SFML/Graphics.hpp>

class Number
{
private:
	sf::Sprite number;

	float sizeX;
	float sizeY;

public:
	int numType;
	bool draw;

	Number(sf::Texture* text, int type, sf::Vector2f pos);
	virtual ~Number();

	// accessors 
	const sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f getPosition() const;

	// functions
	void render(sf::RenderTarget& target);

};

