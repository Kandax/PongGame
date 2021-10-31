#include "GamemodePlayerBot.h"

GamemodePlayerBot::GamemodePlayerBot()
	: mWindowWidth(800)
	, mWindowHeight(600)
	, mPlayerLeft()
	, mPlayerRight(mWindowWidth - 32, 0)
	, mBBLeft{ sf::Vector2f(-10,0), sf::Vector2f(0,mWindowHeight) }
	, mBBRight{ sf::Vector2f(mWindowWidth,0), sf::Vector2f(mWindowWidth + 10,mWindowHeight) }
	, mBBTop{ sf::Vector2f(0,-10), sf::Vector2f(mWindowWidth,0) }
	, mBBBottom{ sf::Vector2f(0,mWindowHeight), sf::Vector2f(mWindowWidth,mWindowHeight + 10) }
	, mFont()
	, mScoreTextBlue()
	, mScoreTextRed()
	, mPointsBlue(0)
	, mPointsRed(0)
{
}

GamemodePlayerBot::GamemodePlayerBot(sf::RenderWindow* window, unsigned int windowWidth, unsigned int windowHeight)
	: mWindowWidth(windowWidth)
	, mWindowHeight(windowHeight)
	, mWindow(window)
	, mPlayerLeft()
	, mPlayerRight(mWindowWidth - 32, 0)
	, mBBLeft{ sf::Vector2f(-10,0), sf::Vector2f(0,mWindowHeight) }
	, mBBRight{ sf::Vector2f(mWindowWidth,0), sf::Vector2f(mWindowWidth + 10,mWindowHeight) }
	, mBBTop{ sf::Vector2f(0,-10), sf::Vector2f(mWindowWidth,0) }
	, mBBBottom{ sf::Vector2f(0,mWindowHeight), sf::Vector2f(mWindowWidth,mWindowHeight + 10) }
	, mFont()
	, mScoreTextBlue()
	, mScoreTextRed()
	, mPointsBlue(0)
	, mPointsRed(0)
{
}

void GamemodePlayerBot::Init()
{
	mPlayerRight.getShape()->setFillColor(sf::Color::Red);


	srand(time(NULL));

	restart();

	//std::cout << "ball dir H: " << mBall.getHorizontalDir() << " V: " << mBall.getVerticalDir() << std::endl;

	mFont.loadFromFile("fonts\\Roboto-Thin.ttf");

	mScoreTextBlue.setFont(mFont);
	mScoreTextBlue.setString("00");
	mScoreTextBlue.setCharacterSize(72);
	mScoreTextBlue.setPosition(sf::Vector2f(mWindowWidth / 2 - 100, 0));

	mScoreTextRed.setFont(mFont);
	mScoreTextRed.setString("00");
	mScoreTextRed.setCharacterSize(72);
	mScoreTextRed.setPosition(sf::Vector2f(mWindowWidth / 2 + 20, 0));



	mBall.update();
	mPlayerLeft.update();
	mPlayerRight.update();	
}

void GamemodePlayerBot::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		mWindow->close();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		restart();
	}


	//Players movement

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
	//	mPlayerLeft.move(0, -mPlayerLeft.getSpeed());
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
	//	mPlayerLeft.move(0, mPlayerLeft.getSpeed());
	//}



	//Bot movement
	// 
	// red bot
	//if ball isnt in the boundries of the right pallete
	if (!(mPlayerRight.getBoundingBox().lowerBound.y < mBall.getBoundingBox().lowerBound.y && mPlayerRight.getBoundingBox().upperBound.y > mBall.getBoundingBox().upperBound.y)) {
		
		//if ball is above the pallete
		if (mPlayerRight.getBoundingBox().lowerBound.y >= mBall.getBoundingBox().upperBound.y) {
			mBotDir = -1;
		}//if ball is below the pallete
		else if (mPlayerRight.getBoundingBox().upperBound.y < mBall.getBoundingBox().lowerBound.y) {
			mBotDir = 1;
		}//bot does nothing
		else {
			mBotDir = 0;
		}
	}

	//blue bot
	//if ball isnt in the boundries of the left pallete
	if (!(mPlayerLeft.getBoundingBox().lowerBound.y < mBall.getBoundingBox().lowerBound.y && mPlayerLeft.getBoundingBox().upperBound.y > mBall.getBoundingBox().upperBound.y)) {
		//if ball is above the pallete
		if (mPlayerLeft.getBoundingBox().lowerBound.y >= mBall.getBoundingBox().upperBound.y) {
			mBotDir2 = -1;
		}//if ball is below the pallete
		else if (mPlayerLeft.getBoundingBox().upperBound.y < mBall.getBoundingBox().lowerBound.y) {
			mBotDir2 = 1;
		}//bot does nothing
		else {
			mBotDir2 = 0;
		}
	}


	//if (mBall.getPositionY() >= mPlayerLeft.getPositionY()) {
	//	//mPlayerRight.move(0, mPlayerRight.getSpeed());
	//	mBotDir2 = 1;
	//}
	//else if (mBall.getPositionY() < mPlayerLeft.getPositionY()) {
	//	//mPlayerRight.move(0, -mPlayerRight.getSpeed());
	//	mBotDir2 = -1;
	//}
	//else {
	//	mBotDir2 = 0;
	//}
}

void GamemodePlayerBot::updatePhysics(float dt)
{
	//if ball touch top or bottom wall, reverse his vertical direction 
	if (isColliding(mBall.getBoundingBox(), mBBTop) || isColliding(mBall.getBoundingBox(), mBBBottom)) {
		mBall.setDirection(mBall.getHorizontalDir(), -mBall.getVerticalDir());
		mBall.setSpeed(mBall.getSpeed() + mBall.getAcceleration());
		//std::cout << "ball dir H: " << mBall.getHorizontalDir() << " V: " << mBall.getVerticalDir() << std::endl;

	}
	//if ball touch left wall add point to the red player and restart game
	if (isColliding(mBall.getBoundingBox(), mBBLeft)) {
		mPointsRed++;

		std::cout << "red points: " << (int)mPointsRed << std::endl;

		if (mPointsRed < 10) {
			mScoreTextRed.setString("0" + std::to_string(mPointsRed));
		}
		else {
			mScoreTextRed.setString(std::to_string(mPointsRed));
		}

		restart();
	}


	//if ball touch left wall add point to the blue player and restart game
	if (isColliding(mBall.getBoundingBox(), mBBRight)) {
		mPointsBlue++;

		std::cout << "blue points: " << (int)mPointsBlue << std::endl;

		if (mPointsBlue < 10) {
			mScoreTextBlue.setString("0" + std::to_string(mPointsBlue));
		}
		else {
			mScoreTextBlue.setString(std::to_string(mPointsBlue));
		}

		restart();
	}


	



	float disBallAndPlayerR = std::sqrt(std::pow(mBall.getCenterPosition().y - mPlayerRight.getCenterPosition().y, 2));

	//std::cout << "dis ball and player R: " << disBallAndPlayerR << std::endl;
	float percOfDisR = (disBallAndPlayerR) / (mPlayerRight.getHeight() / 2);
	//std::cout << "perc of dis R: " << percOfDisR << std::endl;

	float disBallAndPlayerL = std::sqrt(std::pow(mBall.getCenterPosition().y - mPlayerLeft.getCenterPosition().y, 2));

	//std::cout << "dis ball and player L: " << disBallAndPlayerL << std::endl;

	float percOfDisL = (disBallAndPlayerL) / (mPlayerLeft.getHeight() / 2);
	//std::cout << "perc of dis L: " << percOfDisL << std::endl;





	//if ball collide with right player change direction
	if (isColliding(mBall.getBoundingBox(), mPlayerRight.getBoundingBox())) {
		std::cout << "red" << std::endl;

		//checking if ball is below of the center of paddle
		if (mBall.getCenterPosition().y > mPlayerRight.getCenterPosition().y) {//below center of paddle

			//ball will teleport in front of the right paddle
			mBall.setPosition(mWindowWidth - 2 * (mPlayerRight.getShape()->getSize().x), mBall.getPositionY());

			if (mBall.getVerticalDir() > 0) {//direction down
				mBall.setDirection(-mBall.getHorizontalDir(), percOfDisR);// dir right down
				mBall.setSpeed(mBall.getSpeed() + mBall.getAcceleration());

			}
			else {//direction up
				mBall.setDirection(-mBall.getHorizontalDir(), percOfDisR);//dir right down
				mBall.setSpeed(mBall.getSpeed() + mBall.getAcceleration());
			}
		}
		else {// on top center of paddle

			//ball will teleport in front ofthe  right paddle
			mBall.setPosition(mWindowWidth - 2 * (mPlayerRight.getShape()->getSize().x), mBall.getPositionY());

			if (mBall.getVerticalDir() > 0) {//direction down
				mBall.setDirection(-mBall.getHorizontalDir(), -percOfDisR);
				mBall.setSpeed(mBall.getSpeed() + mBall.getAcceleration());
			}
			else {//direction up
				mBall.setDirection(-mBall.getHorizontalDir(), -percOfDisR);
				mBall.setSpeed(mBall.getSpeed() + mBall.getAcceleration());
			}
		}
	}


	//if ball collide with left player change direction
	if (isColliding(mBall.getBoundingBox(), mPlayerLeft.getBoundingBox())) {
		std::cout << "blue" << std::endl;
		//ball will teleport in front of the left paddle
		mBall.setPosition(mPlayerLeft.getShape()->getSize().x, mBall.getPositionY());


		if (mBall.getCenterPosition().y > mPlayerLeft.getCenterPosition().y) {//below center of paddle
			if (mBall.getVerticalDir() > 0)//direction down
			{
				mBall.setDirection(-mBall.getHorizontalDir(), percOfDisL);// dir right down
				mBall.setSpeed(mBall.getSpeed() + mBall.getAcceleration());

			}
			else //direction up
			{
				mBall.setDirection(-mBall.getHorizontalDir(), percOfDisL);//dir right down
				mBall.setSpeed(mBall.getSpeed() + mBall.getAcceleration());
			}
		}
		else {// on top center of paddle
			if (mBall.getVerticalDir() > 0)//direction down
			{
				mBall.setDirection(-mBall.getHorizontalDir(), -percOfDisL);
				mBall.setSpeed(mBall.getSpeed() + mBall.getAcceleration());
			}
			else//direction up
			{
				mBall.setDirection(-mBall.getHorizontalDir(), -percOfDisL);
				mBall.setSpeed(mBall.getSpeed() + mBall.getAcceleration());
			}
		}
	}


	//checking if ball leave a boundries
	if (mBall.getPositionY() < 0)
		mBall.setPosition(mBall.getPositionX(), 1);

	if (mBall.getPositionY() + mBall.getSize() > mWindowHeight)
		mBall.setPosition(mBall.getPositionX(), mWindowHeight - mBall.getSize());

}

void GamemodePlayerBot::update(float dt)
{
	mBall.move(mBall.getHorizontalDir() * mBall.getSpeed(), mBall.getVerticalDir() * mBall.getSpeed());

	if (mBotDir > 0) {
		mPlayerRight.move(0, 20);
	}
	else if (mBotDir < 0) {
		mPlayerRight.move(0, -20);

	}
	else {

		mPlayerRight.move(0, 0);
	}

	if (mBotDir2 > 0) {
		mPlayerLeft.move(0, mPlayerLeft.getSpeed());
	}
	else if (mBotDir2 < 0) {
		mPlayerLeft.move(0, -mPlayerLeft.getSpeed());

	}
	else {

		mPlayerLeft.move(0, 0);
	}




	//checking if players leaves a boundries
	if (mPlayerLeft.getPositionY() < 0)
		mPlayerLeft.setPosition(mPlayerLeft.getPositionX(), 0);
	if (mPlayerLeft.getPositionY() > mWindowHeight - mPlayerLeft.getHeight())
		mPlayerLeft.setPosition(mPlayerLeft.getPositionX(), mWindowHeight - mPlayerLeft.getHeight());

	if (mPlayerRight.getPositionY() < 0)
		mPlayerRight.setPosition(mPlayerRight.getPositionX(), 0);
	if (mPlayerRight.getPositionY() > mWindowHeight - mPlayerRight.getHeight())
		mPlayerRight.setPosition(mPlayerRight.getPositionX(), mWindowHeight - mPlayerRight.getHeight());




	mBall.update();
	mPlayerLeft.update();
	mPlayerRight.update();

}

void GamemodePlayerBot::render()
{
	//std::cout <<"Time used: "<<mETime.getTimeUsed()<< " Elapsed Time" << mETime.getElapsedTime() << std::endl;
	//std::cout << "rand: " << mStartHorizontalDirectionBall << std::endl;
	//std::cout << "rand: " << mStartVerticalDirectionBall << std::endl;
	//std::cout << "ball pos X: " << mBall.getPositionX() << " pos Y: " << mBall.getPositionY() << std::endl;
	//std::cout << "ball acc: " << mBall.getAcceleration() << std::endl;
	sf::RectangleShape lRectLine = sf::RectangleShape(sf::Vector2f(10, 30));
	lRectLine.setPosition(sf::Vector2f(mWindowWidth / 2, 0));
	lRectLine.setOrigin(sf::Vector2f(5, 0));

	//mWindow->clear();
	for (int i = 0; i < 13; i++) {
		mWindow->draw(lRectLine);
		lRectLine.setPosition(sf::Vector2f(mWindowWidth / 2, i * 50));
	}


	mBall.draw(mWindow);
	mPlayerLeft.draw(mWindow);
	mPlayerRight.draw(mWindow);

	mWindow->draw(mScoreTextBlue);
	mWindow->draw(mScoreTextRed);
	//mWindow->display();
}

bool GamemodePlayerBot::isColliding(const BoundingBox& firstBoundingBox, const BoundingBox& secondBoundingBox)
{
	if (firstBoundingBox.lowerBound.x < secondBoundingBox.upperBound.x && firstBoundingBox.upperBound.x  > secondBoundingBox.lowerBound.x
		&& firstBoundingBox.lowerBound.y < secondBoundingBox.upperBound.y && firstBoundingBox.upperBound.y  > secondBoundingBox.lowerBound.y) {
		return true;
	}
	else {
		return false;
	}
}

void GamemodePlayerBot::restart()
{
	mPlayerLeft.setPosition(0, mWindowHeight / 2 - mPlayerLeft.getHeight() / 2);
	mPlayerRight.setPosition(mWindowWidth - mPlayerRight.getWitdh(), mWindowHeight / 2 - mPlayerRight.getHeight() / 2);
	mBall.setPosition(mWindowWidth / 2 - mBall.getSize() / 2, mWindowHeight / 2 - mBall.getSize() / 2);
	mBall.setDirection(0, 0);
	mBall.resetAcceleration();
	mStartHorizontalDirectionBall = bool(rand() % 2);

	mStartVerticalDirectionBall = (rand() % 200 - 100) * 0.01;
	//mStartHorizontalDirectionBall = 0;
	//mStartVerticalDirectionBall = 0;

	if (mStartHorizontalDirectionBall == 0)
		mBall.setDirection(-1, mStartVerticalDirectionBall);
	else
		mBall.setDirection(1, mStartVerticalDirectionBall);


	mBall.setSpeed(2);
	std::cout << "RESTARTED GamemodePlayerBot" << std::endl;
}
