#include "Game.h"



static constexpr float M_PI = 3.14159265359f;
static constexpr float ToDegrees = 180 / M_PI;


Game::Game()
	: mWindowWidth(800)
	, mWindowHeight(600)
	, mWindowName("Pong Game")
	, mWindow(sf::VideoMode(mWindowWidth, mWindowHeight), mWindowName)
	, mEvent()
	, mMenuChoice(0)
	, mButton1(mWindowWidth / 2 - 100, 100, 200, 50, "Play")
	, mButton2(mWindowWidth/2 - 100, 200,200,50,"Bots")
	, mGM2P(&mWindow, mWindowWidth,mWindowHeight)
	, mGMPB(&mWindow, mWindowWidth,mWindowHeight)

{
	mFont.loadFromFile("fonts\\Roboto-Thin.ttf");
	mText.setFont(mFont);
	mText.setString(mButton1.text);
	mText.setPosition(mButton1.posX + 70, mButton1.posY + 5);
	mButton1.shape.setFillColor(sf::Color::Color(100, 100, 100));
	mButton2.shape.setFillColor(sf::Color::Color(100, 100, 100));
	mGM2P.Init();
	mGMPB.Init();

}

Game::~Game()
{
	
}

void Game::run()
{
	while (mWindow.isOpen()) {
		events();
		input();
		updatePhysics();
		update();
		render();
		mETime.run();
		
	}

}

void Game::events()
{
	while (mWindow.pollEvent(mEvent)) {
		switch (mEvent.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}


}

void Game::input()
{

	switch (mMenuChoice)
	{
	case 0:
		//input menu
		if (isColliding(mButton1.boundingBox, sf::Mouse::getPosition(mWindow).x, sf::Mouse::getPosition(mWindow).y) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			std::cout << "button1" << std::endl;
			mMenuChoice = 1;
		}
		if (isColliding(mButton2.boundingBox, sf::Mouse::getPosition(mWindow).x, sf::Mouse::getPosition(mWindow).y) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			std::cout << "button1" << std::endl;
			mMenuChoice = 2;
		}
		break;
	case 1:
		mGM2P.input();
		break;
	case 2:
		mGMPB.input();
		break;

	default:
		std::cout << "mMenuChoice out of bounds" << std::endl;
		break;
	}



}

void Game::updatePhysics()
{
	switch (mMenuChoice)
	{
	case 0:
		//update physics menu
		//nothing gonna will be there
		break;
	case 1:
		mGM2P.updatePhysics(mETime.getTimeUsed());
		break;
	case 2:
		mGMPB.updatePhysics(mETime.getTimeUsed());
		break;
	default:
		break;
	}


}

void Game::update()
{
	switch (mMenuChoice)
	{
	case 0:
		//update  menu
		break;
	case 1:
		mGM2P.update(mETime.getTimeUsed());
		break;
	case 2:
		mGMPB.update(mETime.getElapsedTime());
		break;
	default:
		break;
	}
}

void Game::render()
{
	
	mWindow.clear();

	switch (mMenuChoice)
	{
	case 0:
		//render menu
		mWindow.draw(mButton1.shape);
		mText.setString(mButton1.text);
		mText.setPosition(mButton1.posX + 70, mButton1.posY + 5);
		mWindow.draw(mText);


		mWindow.draw(mButton2.shape);
		mText.setString(mButton2.text);
		mText.setPosition(mButton2.posX + 70, mButton2.posY + 5);
		mWindow.draw(mText);
		
		break;
	case 1:
		mGM2P.render();
		break;
	case 2:
		mGMPB.render();
		break;
	default:
		break;
	}
	
	mWindow.display();
}

bool Game::isColliding(const BoundingBox& boundingBox, float pointX, float pointY)
{
	if (pointX > boundingBox.lowerBound.x && pointX < boundingBox.upperBound.x
		&& pointY > boundingBox.lowerBound.y && pointY < boundingBox.upperBound.y) {
		return true;
	}
	else {
		return false;
	}
		
}

Game::Button::Button(float posX, float posY, uint16_t boxWidth, uint16_t boxHeight, std::string text)
{
	this->posX = posX;
	this->posY = posY;
	this->boxWidth = boxWidth;
	this->boxHeight = boxHeight;
	this->boundingBox.lowerBound.x = this->posX;
	this->boundingBox.lowerBound.y = this->posY;
	this->boundingBox.upperBound.x = this->posX + this->boxWidth;
	this->boundingBox.upperBound.y = this->posY + this->boxHeight;
	this->shape.setSize(sf::Vector2f(boxWidth, boxHeight));
	this->shape.setPosition(sf::Vector2f(posX, posY));
	this->text = text;
}
