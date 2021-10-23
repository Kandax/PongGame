#include "Game.h"



static constexpr float M_PI = 3.14159265359f;
static constexpr float ToDegrees = 180 / M_PI;


Game::Game()
	: mWindowWidth(800)
	, mWindowHeight(600)
	, mWindowName("Pong Game")
	, mWindow(sf::VideoMode(mWindowWidth, mWindowHeight), mWindowName)
	, mEvent()	
	, mGM2P(&mWindow, mWindowWidth,mWindowHeight)
{
	
	mGM2P.Init();

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

	mGM2P.input();

}

void Game::updatePhysics()
{
	
	mGM2P.updatePhysics(mETime.getTimeUsed());
}

void Game::update()
{
	
	mGM2P.update(mETime.getTimeUsed());
}

void Game::render()
{
	
	mWindow.clear();
	mGM2P.render();
	mWindow.display();
}
