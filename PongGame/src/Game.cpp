#include "Game.h"



static constexpr float M_PI = 3.14159265359f;
static constexpr float ToDegrees = 180 / M_PI;


Game::Game()
	:mWindowWidth(800)
	, mWindowHeight(600)
	, mWindowName("Rainbow7Flag")
	, mWindow(sf::VideoMode(mWindowWidth, mWindowHeight), mWindowName)
	, mEvent()
	, mPlayerLeft()
	, mPlayerRight(mWindowWidth - 32, 0)
	, mBBLeft{sf::Vector2f(-10,0), sf::Vector2f(0,mWindowHeight)}
	, mBBRight{ sf::Vector2f(mWindowWidth,0), sf::Vector2f(mWindowWidth + 10,mWindowHeight) }
	, mBBTop{ sf::Vector2f(0,-10), sf::Vector2f(mWindowWidth,0) }
	, mBBBottom{ sf::Vector2f(0,mWindowHeight), sf::Vector2f(mWindowWidth,mWindowHeight + 10) }
{
	
	mPlayerRight.getShape()->setFillColor(sf::Color::Red);

	
	srand(time(NULL));
	
	restart();

	std::cout << "ball dir H: " << mBall.getHorizontalDir() << " V: " << mBall.getVerticalDir() << std::endl;
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		mWindow.close();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		restart();
	}



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		mPlayerLeft.move(0,-mPlayerLeft.getSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		mPlayerLeft.move(0,mPlayerLeft.getSpeed() );
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
		mPlayerRight.move(0, -mPlayerLeft.getSpeed() );
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
		mPlayerRight.move(0, mPlayerLeft.getSpeed() );
	}

	




}

void Game::updatePhysics()
{

		if (isColliding(mBall.getBoundingBox(), mBBTop) || isColliding(mBall.getBoundingBox(), mBBBottom)) {
			mBall.setDirection(mBall.getHorizontalDir(), -mBall.getVerticalDir());
			std::cout << "ball dir H: " << mBall.getHorizontalDir() << " V: " << mBall.getVerticalDir() << std::endl;
			
		}
		
	


}

void Game::update()
{
	mBall.move(mBall.getHorizontalDir() * mBall.getSpeed() , mBall.getVerticalDir() * mBall.getSpeed() );


	mBall.update();
	mPlayerLeft.update();
	mPlayerRight.update();
}

void Game::render()
{

	//std::cout <<"Time used: "<<mETime.getTimeUsed()<< " Elapsed Time" << mETime.getElapsedTime() << std::endl;
	//std::cout << "rand: " << mStartHorizontalDirectionBall << std::endl;
	//std::cout << "rand: " << mStartVerticalDirectionBall << std::endl;
	//std::cout << "ball pos X: " << mBall.getPositionX() << " pos Y: " << mBall.getPositionY() << std::endl;
	mWindow.clear();
	mBall.draw(&mWindow);
	mPlayerLeft.draw(&mWindow);
	mPlayerRight.draw(&mWindow);
	mWindow.display();



}

bool Game::isColliding(const BoundingBox& firstBoundingBox, const BoundingBox& secondBoundingBox)
{
	if (firstBoundingBox.lowerBound.x < secondBoundingBox.upperBound.x && firstBoundingBox.upperBound.x  > secondBoundingBox.lowerBound.x
		&& firstBoundingBox.lowerBound.y < secondBoundingBox.upperBound.y && firstBoundingBox.upperBound.y  > secondBoundingBox.lowerBound.y) {
		return true;
	}
	else {
		return false;
	}


}

void Game::restart()
{
	mPlayerLeft.setPosition(0, mWindowHeight / 2 - mPlayerLeft.getHeight() / 2);
	mPlayerRight.setPosition(mWindowWidth - mPlayerRight.getWitdh(), mWindowHeight  / 2 - mPlayerRight.getHeight() /2);
	mBall.setPosition(mWindowWidth / 2 - mBall.getSize() /2, mWindowHeight / 2 - mBall.getSize() / 2);
	mBall.setDirection(0, 0);

	mStartHorizontalDirectionBall = bool(rand() % 2);

	mStartVerticalDirectionBall = (rand() % 200 - 100) * 0.01;
	if (mStartHorizontalDirectionBall == 0)
		mBall.setDirection(-1, mStartVerticalDirectionBall);
	else
		mBall.setDirection(1, mStartVerticalDirectionBall);
	std::cout << "RESTARTED" << std::endl;

}
