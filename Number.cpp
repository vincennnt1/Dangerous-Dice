#include "Number.h"

Number::Number(sf::Texture* text, int type, sf::Vector2f pos)
{
	this->sizeX = 50.f;
	this->sizeY = 50.f;

	this->numType = type;
	
	text->setSmooth(false);
	this->number.setTexture(*text);

	this->number.setScale(sf::Vector2f(sizeX / text->getSize().x, sizeY / text->getSize().y));

	this->number.setOrigin(sf::Vector2f(12.5, 12.5));

	this->number.setPosition(pos);

	this->draw = true;
}

Number::~Number()
{

}

const sf::FloatRect Number::getGlobalBounds() const
{
	return this->number.getGlobalBounds();
}

const sf::Vector2f Number::getPosition() const
{
	return this->number.getPosition();
}

void Number::render(sf::RenderTarget& target)
{
	if (draw) {
		target.draw(this->number);
	}
}