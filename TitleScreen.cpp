#include "TitleScreen.h"



TitleScreen::TitleScreen(sf::Texture* text, sf::RenderWindow &window, sf::View* cam)
{
	sf::Vector2f camPos = cam->getCenter();

	this->bkg = new sf::Sprite();

	text->setSmooth(false);
	this->bkg->setTexture(*text);
	
	this->bkg->setOrigin(sf::Vector2f(text->getSize().x / 2, text->getSize().y / 2));
	this->bkg->setPosition(sf::Vector2f(camPos.x + 130.f, camPos.y - 100.f));

	this->font = new sf::Font();
	this->font->loadFromFile("Assets/pcsenior.ttf");

	this->text = new sf::Text();

	this->text->setFont(*this->font);
	this->text->setPosition(sf::Vector2f(camPos.x, camPos.y + 100.f));
	this->text->setCharacterSize(30);
	this->text->setFillColor(sf::Color(78, 73, 95));
	this->text->setOutlineColor(sf::Color(15, 42, 63));
	this->text->setOutlineThickness(2);

	this->text->setString("Click To Play!");

	this->title = new sf::Text();

	this->title->setFont(*this->font);
	this->title->setPosition(sf::Vector2f(camPos.x - 250.f, camPos.y - 400.f ));
	this->title->setCharacterSize(55);
	this->title->setFillColor(sf::Color(78, 73, 95));
	this->title->setOutlineColor(sf::Color(15, 42, 63));
	this->title->setOutlineThickness(2);

	this->title->setString("Dangerous Dice");

	this->window = &window;

}

TitleScreen::~TitleScreen()
{

}

void TitleScreen::run()
{
	while (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Event ev;
		while (this->window->pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				this->window->close();

			if (ev.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					this->window->close();
			}
		}

		this->window->clear();

		this->window->draw(*this->bkg);
		this->window->draw(*this->text);
		this->window->draw(*this->title);

		window->display();
	}

	this->text->move(sf::Vector2f(-400.f, -220.f));
	this->text->setCharacterSize(14);
	this->text->setFillColor(sf::Color::Black);
	this->text->setString("You will be given a random die. \n\nYou must find and bring all of the dice to the center other than that one \n\nsince as the name suggests, it is dangerous. \n\nIf you do not return all other dice, you will still \n\nget a random chance to obtain the reward which is +10 points \n\nand 2x the points for numbers found! \n\nIf you collect the dangerous die, you will lose 10 points, but you will \n\nalways get points for the numbers found. \n\n\n *There is also a small chance that you will get \n\n2 of your numbers in the same place, so be careful!* \n\n\n *Points are calculated at the end of the timer*");

	this->tempTime = new sf::Clock();
	
	sf::Time elapsed;
	elapsed = this->tempTime->getElapsedTime();

	while (elapsed < sf::milliseconds(200))
	{
		elapsed = this->tempTime->getElapsedTime();
	}

	while (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Event ev;
		while (this->window->pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				this->window->close();

			if (ev.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					this->window->close();
			}
		}

		this->window->clear();

		this->window->draw(*this->bkg);

		this->window->draw(*this->title);

		this->window->draw(*this->text);

		window->display();
	}

}
