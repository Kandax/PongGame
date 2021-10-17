#include "PowerUp.h"

PowerUp::PowerUp()
	:mPositionX(0)
	,mPositionY(0)
	,mBoxSize(48)
	,mTexturesDirectory("textures")
	,mActualPowerUp(powerUps::none)

{
	
	temp.loadFromFile("textures\\powerUP0.png");
	mShape.setTexture(temp);
	mShape.setScale(sf::Vector2f(1.5f, 1.5f));
}

void PowerUp::draw(sf::RenderWindow* window)
{
	window->draw(mShape);
}

void PowerUp::update()
{
	mShape.setPosition(sf::Vector2f(mPositionX, mPositionY));
	mBoundingBox.lowerBound.x = mPositionX;
	mBoundingBox.lowerBound.y = mPositionY;
	mBoundingBox.upperBound.x = mPositionX + mBoxSize;
	mBoundingBox.upperBound.y = mPositionY + mBoxSize;
	mShape.setTexture(mTextures.at(mActualPowerUp));
}

void PowerUp::powerUpSpeedUpBall(Ball& ball)
{
	ball.setAcceleration(ball.getAcceleration() + 0.5f);
}

void PowerUp::randomPosition(uint16_t minX, uint16_t maxX, uint16_t minY, uint16_t maxY)
{
	assert(!(maxX <= minX), "maxX is less than or equal to minX");
	int16_t rangeX = maxX - minX;
	assert(!(maxY <= minY), "maxY is less than or equal to minY");
	int16_t rangeY = maxY - minY;

	int16_t randX = (rand() % rangeX) + minX;
	int16_t randY = (rand() % rangeY) + minY;

	setPosition(randX, randY);

}

void PowerUp::setPosition(float x, float y)
{
	mPositionX = x;
	mPositionY = y;
}

BoundingBox PowerUp::getBoundingBox()
{
	return mBoundingBox;
}

float PowerUp::getPositionX() const
{

	return mPositionX;
}

float PowerUp::getPositionY() const
{
	return mPositionY;
}

bool PowerUp::setTexture(std::string textureName, powerUps powerUp)
{
	if (!mTextures[powerUp].loadFromFile(mTexturesDirectory +"\\" + textureName)) {
		std::cout << "couldnt load a file: " << textureName << std::endl;
		return false;
	}
	else {
		return true;
	}
}

void PowerUp::setTexturesDirectory(const std::string& directory)
{
	mTexturesDirectory = directory;
}

void PowerUp::setActualPowerUp(powerUps powerUp)
{
	mActualPowerUp = powerUp;
}

int PowerUp::getActualPowerUp() const
{
	return mActualPowerUp;
}

int PowerUp::getBoxSize() const
{
	return mBoxSize;
}
