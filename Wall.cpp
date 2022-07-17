#include "Wall.h"

Wall::Wall(sf::Texture* text, int posX, int posY) // each wall grid will be 50x50
{
	text->setSmooth(false);
	this->wall.setTexture(*text);

	this->wall.setOrigin(25.f, 25.f);

	this->wall.setPosition(sf::Vector2f(posX, posY));
}

Wall::~Wall()
{

}

void Wall::render(sf::RenderTarget& target)
{
	target.draw(this->wall);
}

const sf::FloatRect Wall::getGlobalBounds() const
{
	return this->wall.getGlobalBounds();
}

