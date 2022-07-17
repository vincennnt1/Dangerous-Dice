#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1260, 800), "Dangerous Dice", sf::Style::Close);
	this->window->setFramerateLimit(60);


	this->possibleCoords[0] = sf::Vector2f(1350, 1450); this->possibleCoords[1] = sf::Vector2f(200, 250); this->possibleCoords[2] = sf::Vector2f(1100, 450); 
	this->possibleCoords[3] = sf::Vector2f(50, 950); this->possibleCoords[4] = sf::Vector2f(900, 1450); this->possibleCoords[5] = sf::Vector2f(150, 1450);

	this->possibleCoords[6] = sf::Vector2f(200, 250); this->possibleCoords[7] = sf::Vector2f(200, 500); this->possibleCoords[8] = sf::Vector2f(250, 750);
	this->possibleCoords[9] = sf::Vector2f(500, 950); this->possibleCoords[10] = sf::Vector2f(50, 950); this->possibleCoords[11] = sf::Vector2f(50, 50);

	this->possibleCoords[12] = sf::Vector2f(1250, 200); this->possibleCoords[13] = sf::Vector2f(850, 500); this->possibleCoords[14] = sf::Vector2f(1350, 650);
	this->possibleCoords[15] = sf::Vector2f(1400, 950); this->possibleCoords[16] = sf::Vector2f(850, 1450); this->possibleCoords[17] = sf::Vector2f(1450, 1450);

	this->possibleCoords[18] = sf::Vector2f(700, 1450); this->possibleCoords[19] = sf::Vector2f(1300, 750); this->possibleCoords[20] = sf::Vector2f(50, 1450);
	this->possibleCoords[21] = sf::Vector2f(1450, 50); this->possibleCoords[22] = sf::Vector2f(750, 100); this->possibleCoords[23] = sf::Vector2f(850, 1050);

}

void Game::initTextures()
{
	// player texture
	this->textures["PLAYER1"] = new sf::Texture();
	this->textures["PLAYER1"]->loadFromFile("Textures/player1.png");

	this->textures["PLAYER2"] = new sf::Texture();
	this->textures["PLAYER2"]->loadFromFile("Textures/player2.png");

	this->lastTexture = this->textures["PLAYER1"];

	// Wall texture
	this->textures["WALL"] = new sf::Texture();
	this->textures["WALL"]->loadFromFile("Textures/wall.png");

	// dice *WILL ALSO USE FOR NUMBERS
	this->textures["DICE_1"] = new sf::Texture(); // DICE 1
	this->textures["DICE_1"]->loadFromFile("Textures/dice1.png");

	this->textures["DICE_2"] = new sf::Texture(); // DICE 2
	this->textures["DICE_2"]->loadFromFile("Textures/dice2.png");

	this->textures["DICE_3"] = new sf::Texture(); // DICE 3
	this->textures["DICE_3"]->loadFromFile("Textures/dice3.png");

	this->textures["DICE_4"] = new sf::Texture(); // DICE 4
	this->textures["DICE_4"]->loadFromFile("Textures/dice4.png");

	this->textures["DICE_5"] = new sf::Texture(); // DICE 5
	this->textures["DICE_5"]->loadFromFile("Textures/dice5.png");

	this->textures["DICE_6"] = new sf::Texture(); // DICE 6
	this->textures["DICE_6"]->loadFromFile("Textures/dice6.png");

	this->textures["UNKNOWN"] = new sf::Texture();
	this->textures["UNKNOWN"]->loadFromFile("Textures/unknowndice.png");

	// BACKGROUND
	this->textures["BACKGROUND"] = new sf::Texture();
	this->textures["BACKGROUND"]->loadFromFile("Textures/bkg.png");
}

void Game::initFont()
{
	this->font = new sf::Font();
	this->font->loadFromFile("Assets/pcsenior.ttf");
}

void Game::initPlayer()
{
	this->player = new Player(this->textures["PLAYER1"], this->textures["UNKNOWN"]);

	this->movementSpeed = 5.f;

	this->heldNumber = 7;

	this->points = 0;

	this->numbersFound = 0;

	this->neededNumberFound = false;
}

void Game::initWalls()
{
	// |||||||| BORDER TILES ||||||||||
	for (int i = 0; i < 4; i++)
	{
		if (i == 0) {
			for (int a = 0; a < 1500; a += 50) // top border
			{
				this->walls.push_back(new Wall(this->textures["WALL"], a, 0));
			}
		}

		if (i == 1) {
			for (int a = 0; a < 1500; a += 50) // bottom border
			{
				this->walls.push_back(new Wall(this->textures["WALL"], a , 1500));
			}
		}

		if (i == 2) {
			for (int a = 0; a < 1500; a += 50) // right border
			{
				this->walls.push_back(new Wall(this->textures["WALL"], 1500, a ));
			}
		}
		
		if (i == 3) {
			for (int a = 0; a < 1500; a += 50) // right border
			{
				this->walls.push_back(new Wall(this->textures["WALL"], 0, a));
			}
		}

	}
	this->walls.push_back(new Wall(this->textures["WALL"], 1500, 1500));


	// ||||||||| WORLD TILES |||||||||

	for (int i = 0; i < 500; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 500, i));
	}

	for (int i = 0; i < 300; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], i, 300));
	}

	for (int i = 200; i < 550; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 300, i));
	}

	for (int i = 150; i < 600; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 800, i));
	}

	for (int i = 500; i < 700; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], i, 350));
	}

	for (int i = 800; i < 1300; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], i, 250));
	}

	for (int i = 800; i < 1500; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], i, 1000));
	}

	for (int i = 700; i < 1000; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 1200 , i));
	}

	for (int i = 1200; i < 1400; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], i, 700));
	}

	for (int i = 700; i < 900; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 1350, i));
	}

	for (int i = 800; i < 1150; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], i, 550));
	}

	for (int i = 400; i < 600; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 1150, i));
	}

	for (int i = 650; i < 800; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], i, 150));
	}

	for (int i = 0; i < 150; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 1100, i));
	}

	for (int i = 550; i < 850; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 950, i));
	}
	for (int i = 150; i < 350; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], i, 550));
	}

	for (int i = 0; i < 350; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], i, 800));
	}

	for (int i = 700; i < 800; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 300, i));
	}

	for (int i = 300; i < 800; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], i, 700));
	}
	for (int i = 700; i < 1000; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 550, i));
	}

	for (int i = 350; i < 600; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], i, 1000));
	}

	for (int i = 0; i < 600; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], i, 1200));
	}

	for (int i = 1200; i < 1400; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 350, i));
	}

	for (int i = 1400; i < 1500; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 200, i));
	}
	
	for (int i = 0; i < 200; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], i, 1000));
	}

	for (int i = 950; i < 1050; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 200, i));
	}

	for (int i = 1000; i < 1200; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 800, i));
	}

	for (int i = 1300; i < 1500; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 800, i));
	}

	for (int i = 1350; i < 1500; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 1300, i));
	}

	for (int i = 1300; i < 1400; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], i, 1350));
	}

	for (int i = 800; i < 1100; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], i, 1300));
	}

	for (int i = 1200; i < 1350; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 1100, i));
	}

	for (int i = 1000; i < 1250; i += 50)
	{
		this->walls.push_back(new Wall(this->textures["WALL"], 1350, i));
	}
}

void Game::initNumPlatform()
{
	this->numPlatform = new sf::RectangleShape();
	this->numPlatform->setFillColor(sf::Color(129, 98, 113));
	this->numPlatform->setOutlineColor(sf::Color(32, 57, 79));
	this->numPlatform->setOutlineThickness(5.f);
	this->numPlatform->setSize(sf::Vector2f(200, 130));
	this->numPlatform->setOrigin(sf::Vector2f(this->numPlatform->getSize().x / 2, this->numPlatform->getSize().x / 2));

	this->numPlatform->setPosition(sf::Vector2f(750, 900));
}

void Game::initNumbers()
{

	srand(time(NULL));

	this->numbers.push_back(new Number(this->textures["DICE_1"], 1, this->possibleCoords[rand() % 23])); // NUMBER 1

	this->numbers.push_back(new Number(this->textures["DICE_2"], 2, this->possibleCoords[rand() % 23])); // NUMBER 2

	this->numbers.push_back(new Number(this->textures["DICE_3"], 3, this->possibleCoords[rand() % 23])); // NUMBER 3

	this->numbers.push_back(new Number(this->textures["DICE_4"], 4, this->possibleCoords[rand() % 23])); // NUMBER 4

	this->numbers.push_back(new Number(this->textures["DICE_5"], 5, this->possibleCoords[rand() % 23])); // NUMBER 5

	this->numbers.push_back(new Number(this->textures["DICE_6"], 6, this->possibleCoords[rand() % 23])); // NUMBER 6

	for (int i = 0; i < this->numbers.size(); i++)
	{
		for (int j = 0; j < this->numbers.size(); j++)
		{
			if (this->numbers[j] != this->numbers[i]) 
			{
				if (this->numbers[i]->getGlobalBounds().intersects(this->numbers[j]->getGlobalBounds()))
				{
					while (this->numbers[i]->getGlobalBounds().intersects(this->numbers[j]->getGlobalBounds()))
					{
						this->numbers.erase(this->numbers.begin() + i );
						switch (i)
						{
						case 0:
							this->numbers.insert(this->numbers.begin() + i, new Number(this->textures["DICE_1"], 1, this->possibleCoords[rand() % 23])); // NUMBER 1
							break;
						case 1:
							this->numbers.insert(this->numbers.begin() + i, new Number(this->textures["DICE_2"], 2, this->possibleCoords[rand() % 23])); // NUMBER 2
							break;
						case 2:
							this->numbers.insert(this->numbers.begin() + i, new Number(this->textures["DICE_3"], 3, this->possibleCoords[rand() % 23])); // NUMBER 3
							break;
						case 3:
							this->numbers.insert(this->numbers.begin() + i, new Number(this->textures["DICE_4"], 4, this->possibleCoords[rand() % 23])); // NUMBER 4
							break;
						case 4:
							this->numbers.insert(this->numbers.begin() + i, new Number(this->textures["DICE_5"], 5, this->possibleCoords[rand() % 23])); // NUMBER 5
							break;
						case 5:
							this->numbers.insert(this->numbers.begin() + i, new Number(this->textures["DICE_6"], 6, this->possibleCoords[rand() % 23])); // NUMBER 6
							break;
						}
					}
				}
			}
		}
	}


	// diceHeads
	this->diceHeads.push_back(new sf::Texture()); // NUMBER 1
	this->diceHeads[0]->loadFromFile("Textures/dice1.png");

	this->diceHeads.push_back(new sf::Texture()); // NUMBER 2
	this->diceHeads[1]->loadFromFile("Textures/dice2.png");

	this->diceHeads.push_back(new sf::Texture()); // NUMBER 3
	this->diceHeads[2]->loadFromFile("Textures/dice3.png");

	this->diceHeads.push_back(new sf::Texture()); // NUMBER 4
	this->diceHeads[3]->loadFromFile("Textures/dice4.png");

	this->diceHeads.push_back(new sf::Texture()); // NUMBER 5
	this->diceHeads[4]->loadFromFile("Textures/dice5.png");

	this->diceHeads.push_back(new sf::Texture()); // NUMBER 6
	this->diceHeads[5]->loadFromFile("Textures/dice6.png");

	this->diceHeads.push_back(new sf::Texture()); // UNKNOWN
	this->diceHeads[6]->loadFromFile("Textures/unknowndice.png");


}

void Game::initDice()
{

	this->diceDistance = 35.f;

	// DICE 1
	this->dice.push_back(new Dice(this->textures["DICE_1"], 1, sf::Vector2f(this->camera->getCenter().x - (this->camera->getSize().x / 2) + 25.f, this->camera->getCenter().y - (this->camera->getSize().y / 2) + 25.f)));
	// DICE 2
	this->dice.push_back(new Dice(this->textures["DICE_2"], 2, sf::Vector2f(this->camera->getCenter().x - (this->camera->getSize().x / 2) + 50.f, this->camera->getCenter().y - (this->camera->getSize().y / 2) + 25.f)));
	// DICE 3
	this->dice.push_back(new Dice(this->textures["DICE_3"], 3, sf::Vector2f(this->camera->getCenter().x - (this->camera->getSize().x / 2) + 75.f, this->camera->getCenter().y - (this->camera->getSize().y / 2) + 25.f)));
	// DICE 4
	this->dice.push_back(new Dice(this->textures["DICE_4"], 4, sf::Vector2f(this->camera->getCenter().x - (this->camera->getSize().x / 2) + 100.f, this->camera->getCenter().y - (this->camera->getSize().y / 2) + 25.f)));
	// DICE 5
	this->dice.push_back(new Dice(this->textures["DICE_5"], 5, sf::Vector2f(this->camera->getCenter().x - (this->camera->getSize().x / 2) + 125.f, this->camera->getCenter().y - (this->camera->getSize().y / 2) + 25.f)));
	// DICE 6
	this->dice.push_back(new Dice(this->textures["DICE_6"], 6, sf::Vector2f(this->camera->getCenter().x - (this->camera->getSize().x / 2) + 150.f, this->camera->getCenter().y - (this->camera->getSize().y / 2) + 25.f)));


}

void Game::initCamera()
{
	this->camera = new sf::View;
	this->camera->setSize(1260.f, 800.f);
	//this->camera->setViewport(sf::FloatRect(0.25f, 0.25, 0.5f, 0.5f));


}

void Game::initTimer()
{
	// IN GAME TIMER FOR COLLECTION
	this->clock = new sf::Clock();

	this->timer = new sf::Text();
	this->timer->setFont(*this->font);
	this->timer->setCharacterSize(14);

	this->timer->setFillColor(sf::Color(78, 73, 95));
	this->timer->setOutlineColor(sf::Color(15, 42, 63));
	this->timer->setOutlineThickness(2);

	
	// ANIMATION TIMER
	this->animationTimer = new sf::Clock();
	this->maxTime = sf::milliseconds(500);


}

void Game::initPoints()
{
	this->pointsText = new sf::Text();
	this->pointsText->setFont(*this->font);
	this->pointsText->setCharacterSize(25);

	this->pointsText->setFillColor(sf::Color(78, 73, 95));
	this->pointsText->setOutlineColor(sf::Color(15, 42, 63));
	this->pointsText->setOutlineThickness(2);
}

void Game::initAudio()
{
	// COLLECT SOUND
	this->soundCollect = new sf::SoundBuffer();
	this->soundCollect->loadFromFile("Assets/collect.wav");

	this->Collect = new sf::Sound();
	this->Collect->setBuffer(*this->soundCollect);

	// PLATFORM SOUND
	this->soundPlatform = new sf::SoundBuffer();
	this->soundPlatform->loadFromFile("Assets/platform.wav");

	this->Platform = new sf::Sound();
	this->Platform->setBuffer(*this->soundPlatform);

}

void Game::startTitle()
{
	this->title = new TitleScreen(this->textures["BACKGROUND"], *this->window, this->camera);
	this->title->run();

	delete this->title;
}



void Game::randomDice()
{
	srand(time(NULL));

	this->neededNumber = rand() % this->dice.size() + 1;

	switch (neededNumber)
	{
	case 1:
		this->neededNum = new Dice(this->textures["DICE_1"], 1,  sf::Vector2f( this->camera->getCenter().x + (this->camera->getSize().x / 2) - 25.f, this->camera->getCenter().y - (this->camera->getSize().y / 2) + 25.f));
		break;
	case 2:
		this->neededNum = new Dice(this->textures["DICE_2"], 2, sf::Vector2f(this->camera->getCenter().x + (this->camera->getSize().x / 2) - 25.f, this->camera->getCenter().y - (this->camera->getSize().y / 2) + 25.f));
		break;
	case 3:
		this->neededNum = new Dice(this->textures["DICE_3"], 3, sf::Vector2f(this->camera->getCenter().x + (this->camera->getSize().x / 2) - 25.f, this->camera->getCenter().y - (this->camera->getSize().y / 2) + 25.f));
		break;
	case 4:
		this->neededNum = new Dice(this->textures["DICE_4"], 4, sf::Vector2f(this->camera->getCenter().x + (this->camera->getSize().x / 2) - 25.f, this->camera->getCenter().y - (this->camera->getSize().y / 2) + 25.f));
		break;
	case 5:
		this->neededNum = new Dice(this->textures["DICE_5"], 5, sf::Vector2f(this->camera->getCenter().x + (this->camera->getSize().x / 2) - 25.f, this->camera->getCenter().y - (this->camera->getSize().y / 2) + 25.f));
		break;
	case 6:
		this->neededNum = new Dice(this->textures["DICE_6"], 6, sf::Vector2f(this->camera->getCenter().x + (this->camera->getSize().x / 2) - 25.f, this->camera->getCenter().y - (this->camera->getSize().y / 2) + 25.f));
	}
}


Game::Game()
{
	this->initWindow();

	this->initCamera();

	this->initTextures();

	this->startTitle();

	this->initPlayer();

	this->initWalls();

	this->initNumPlatform();

	this->initNumbers();

	this->initDice();

	this->randomDice();

	this->initFont();

	this->initTimer();

	this->initPoints();

	this->initAudio();


}

Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->soundCollect;
	delete this->Collect;
	delete this->soundPlatform;
	delete this->Platform;

	// deleting textures
	for (auto& i : this->textures) 
	{
		delete i.second;
	}

	// deleting walls
	for (auto* i : this->walls)
	{
		delete i;
	}

	// deleting numbers
	for (auto* i : this->numbers)
	{
		delete i;
	}

	// deleting dice
	for (auto* i : this->dice)
	{
		delete i;
	}

}

void Game::updatePollEvents()
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
}

void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // UP
		this->velocity.y = -1 * this->movementSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // DOWN
		this->velocity.y = 1 * this->movementSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // LEFT
	{ 
		this->velocity.x = -1 * this->movementSpeed;
		this->player->updateDir('A');
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // RIGHT
	{
		this->velocity.x = 1 * this->movementSpeed;
		this->player->updateDir('D');
	}

}

void Game::updateCollision()
{

	for (auto& wall : this->walls)
	{
		this->playerBounds = this->player->getGlobalBounds();
		this->wallBounds = wall->getGlobalBounds();

		this->nextPos = this->playerBounds;
		this->nextPos.left += velocity.x;
		this->nextPos.top += velocity.y;

		if (this->wallBounds.intersects(this->nextPos))
		{

			// BOTTOM COLLISION
			if (this->playerBounds.top < this->wallBounds.top
				&& this->playerBounds.top + playerBounds.height < this->wallBounds.top + this->wallBounds.height
				&& this->playerBounds.left < this->wallBounds.left + this->wallBounds.width
				&& this->playerBounds.left + this->playerBounds.width > this->wallBounds.left)
			{
				velocity.y = 0.f;
				this->player->setPosition(sf::Vector2f(this->player->getPosition().x, this->player->getPosition().y + (this->wallBounds.top - (this->playerBounds.top + this->playerBounds.height))));
			}

			// TOP COLLISION
			else if (this->playerBounds.top > this->wallBounds.top
				&& this->playerBounds.top + playerBounds.height > this->wallBounds.top + this->wallBounds.height
				&& this->playerBounds.left < this->wallBounds.left + this->wallBounds.width
				&& this->playerBounds.left + this->playerBounds.width > this->wallBounds.left)
			{
				velocity.y = 0.f;
				this->player->setPosition(sf::Vector2f(this->player->getPosition().x, this->player->getPosition().y - (this->playerBounds.top - (this->wallBounds.top + this->wallBounds.height))));
			}

			// RIGHT COLLISION
			if (this->playerBounds.left < this->wallBounds.left
				&& this->playerBounds.left + playerBounds.width < this->wallBounds.left + this->wallBounds.width
				&& this->playerBounds.top < this->wallBounds.top + this->wallBounds.height
				&& this->playerBounds.top + this->playerBounds.height > this->wallBounds.top)
			{
				velocity.x = 0.f;
				this->player->setPosition(sf::Vector2f(this->player->getPosition().x + (this->wallBounds.left - (this->playerBounds.left + this->playerBounds.width)), this->player->getPosition().y));
			}

			// LEFT COLLISION
			else if (this->playerBounds.left > this->wallBounds.left
				&& this->playerBounds.left + playerBounds.width > this->wallBounds.left + this->wallBounds.width
				&& this->playerBounds.top < this->wallBounds.top + this->wallBounds.height
				&& this->playerBounds.top + this->playerBounds.height > this->wallBounds.top)
			{
				velocity.x = 0.f;
				this->player->setPosition(sf::Vector2f(this->player->getPosition().x - (this->playerBounds.left - (this->wallBounds.left + this->wallBounds.width)), this->player->getPosition().y));
			}



		}

	}
}

void Game::updateMovement()
{
	this->player->move(this->velocity);
}

void Game::updateDice()
{

	// HOLDING NUMBER
	for (int i = 0; i < this->dice.size(); i++) {
		if (this->player->getGlobalBounds().intersects(this->numbers[i]->getGlobalBounds())) {

			if (heldNumber <= 6) {

				if (this->numbers[i]->draw)
				{
					this->Collect->play();
				}

				this->numbers[heldNumber]->draw = true; // old number
				this->heldNumber = i;
				this->numbers[i]->draw = false; // new number

				// switching heads
				this->player->changeHead(this->diceHeads[this->dice[i]->diceType - 1]);
			}
			else {

				if (this->numbers[i]->draw)
				{
					this->Collect->play();
				}

				this->numbers[i]->draw = false;
				this->heldNumber = i;
			}
		}
	}

	// ||||||| DICE GUI |||||||
	for (float i = 0; i < this->dice.size() * this->diceDistance; i += this->diceDistance) {
		this->dice[ i / this->diceDistance ]->setPosition(sf::Vector2f(this->camera->getCenter().x - (this->camera->getSize().x / 2) + (this->dice[i/this->diceDistance]->getGlobalBounds().width / 2) + i, this->camera->getCenter().y - (this->camera->getSize().y / 2) + 25.f));
	}

	this->neededNum->setPosition(sf::Vector2f(this->camera->getCenter().x + (this->camera->getSize().x / 2) - (this->neededNum->getGlobalBounds().width / 2) - 5.f, this->camera->getCenter().y - (this->camera->getSize().y / 2) + 25.f));


	// BACK TO THE PLATFORM
	if (this->player->getGlobalBounds().intersects(this->numPlatform->getGlobalBounds()) && heldNumber <= 6)
	{
		this->Platform->play();
		numbersFound++;
		this->dice.erase(this->dice.begin() + heldNumber);
		this->numbers.erase(this->numbers.begin() + heldNumber);
		this->heldNumber = 7;

		// switching head
		this->player->changeHead(this->diceHeads[6]);
	}

	// COLLECTED ALL EXCEPT FOR NEEDED DICE
	if (this->dice.size() == 1 && this->dice[0]->diceType == this->neededNumber) {

			this->points += 10;
			this->points += this->numbersFound * 2;


		this->dice.erase(this->dice.begin());
		this->numbers.erase(this->numbers.begin());
		this->initNumbers();
		this->initDice();
		this->randomDice();

		this->numbersFound = 0;
		this->heldNumber = 7;
		this->clock->restart();
	}


	// TIMER STUFF

	sf::Time elapsed;
	elapsed = this->clock->getElapsedTime();

	if (elapsed.asSeconds() > 30.f)
	{
		bool found = false;
		for (int i = 0; i < this->dice.size(); i++)
		{
			if (this->dice[i]->diceType == neededNum->diceType)
			{
				found = true;
				break;
			}
		}

		if (!found) {
			this->points -= 10;
		}

		points += this->numbersFound;
		if (this->dice.size() > 0) {
			if (rand() % this->dice.size() == neededNumber)
			{
				this->points += 10;
				this->points += 2 * this->numbersFound;
			}
		}

 


		this->numbers.clear();
		this->dice.clear();

		this->initNumbers();
		this->initDice();
		this->randomDice();
		this->clock->restart();

		this->numbersFound = 0;
		this->heldNumber = 7;

		// switching head
		this->player->changeHead(this->diceHeads[6]);
	}


}

void Game::updateVariables()
{

}

void Game::updateCamera()
{
	this->camera->setCenter(this->player->getPosition().x, this->player->getPosition().y);
	this->window->setView(*this->camera);
}

void Game::updateTimer()
{
	sf::Time elapsed = this->clock->getElapsedTime();
	std::stringstream ss;
	ss << elapsed.asSeconds();

	this->timer->setString(ss.str());

	this->timer->setPosition(sf::Vector2f(this->camera->getCenter().x + (this->camera->getSize().x / 2) - 150.f , this->camera->getCenter().y - (this->camera->getSize().y / 2) + 17.f));

	// animation timer

	sf::Time tempElapsed;
	tempElapsed = this->animationTimer->getElapsedTime();

	if (tempElapsed >= this->maxTime)
	{

		if (this->lastTexture == this->textures["PLAYER1"])
		{

			this->player->changeLegs(this->textures["PLAYER2"]);
			this->lastTexture = this->textures["PLAYER2"];
		}
		else if (this->lastTexture == this->textures["PLAYER2"])
		{

			this->player->changeLegs(this->textures["PLAYER1"]);
			this->lastTexture = this->textures["PLAYER1"];
		}

		this->animationTimer->restart();
	}

}

void Game::updatePoints()
{
	std::stringstream ss;
	ss << this->points;

	this->pointsText->setString(ss.str());

	this->pointsText->setPosition(sf::Vector2f(this->camera->getCenter().x - (this->camera->getSize().x / 2) + 10.f, this->camera->getCenter().y - (this->camera->getSize().y / 2) + 50.f));
}

void Game::update()
{
	//this->updateVariables();
	this->updatePollEvents();
	this->updateInput();
	this->updateCollision();
	this->updateMovement();
	this->updateCamera();
	this->updateDice();
	this->updateTimer();
	this->updatePoints();

	this->velocity = sf::Vector2f(0, 0);

}

void Game::render()
{
	this->window->clear(sf::Color(8, 20, 30));


	for (int i = 0; i < walls.size(); i++) {

		if (this->walls[i]->getGlobalBounds().left + 50.f >= this->camera->getCenter().x - this->camera->getSize().x / 2.f // left side
			&& this->walls[i]->getGlobalBounds().left + this->walls[i]->getGlobalBounds().width - 50.f <= this->camera->getCenter().x + this->camera->getSize().x / 2.f // right side
			&& this->walls[i]->getGlobalBounds().top + 50.f >= this->camera->getCenter().y - (this->camera->getSize().y / 2.f) // top side
			&& this->walls[i]->getGlobalBounds().top + this->walls[i]->getGlobalBounds().height - 50.f <= this->camera->getCenter().y + (this->camera->getSize().y / 2.f)) // bottom side
		{
			this->walls[i]->render(*this->window);

		}

		
	}

	this->window->draw(*this->numPlatform);

	this->player->render(*this->window);

	for (int i = 0; i < this->numbers.size(); i++)
	{
		this->numbers[i]->render(*this->window);
	}
	
	// |||||||||||| GUI ||||||||||||

	// DICE
	for (int i = 0; i < this->dice.size(); i++)
	{
		this->dice[i]->render(*this->window);
	}
	this->neededNum->render(*this->window);

	// TIMER
	this->window->draw(*this->timer);

	// POINTS
	this->window->draw(*this->pointsText);

	this->window->display();

}

void Game::run()
{
	while (this->window->isOpen()) {

		this->update();

		this->render();
	}
}

