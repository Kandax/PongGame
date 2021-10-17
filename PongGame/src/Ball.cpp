#include "Ball.h"

Ball::Ball()
	: cAcceleration(0.5)
	, mPositionX(0)
	, mPositionY(0)
	, mSpeed(5)
	, mDirVertical(0)
	, mDirHorizontal(0)
	, mBoxSize(32)
	, mAcceleration(cAcceleration)
	, mBoundingBox{ sf::Vector2f(mPositionX,mPositionY), sf::Vector2f(mPositionX + mBoxSize,mPositionY + mBoxSize) }
	, mShape(sf::Vector2f(mBoxSize, mBoxSize))
{
	mShape.setFillColor(sf::Color::Magenta);
}

Ball::Ball(float posX, float posY)
	: cAcceleration(0.5)
	, mPositionX(posX)
	, mPositionY(posY)
	, mSpeed(20)
	, mDirVertical(0)
	, mDirHorizontal(0)
	, mBoxSize(32)
	, mAcceleration(cAcceleration)
	, mBoundingBox{ sf::Vector2f(mPositionX,mPositionY), sf::Vector2f(mPositionX + 2 * mBoxSize,mPositionY + 2 * mBoxSize) }
{
}

void Ball::draw(sf::RenderWindow* window)
{
	window->draw(mShape);
}



void Ball::move(float x, float y)
{
	mPositionX += x;
	mPositionY += y;
}

void Ball::setDirection(float horizontal, float vertical)
{
	mDirHorizontal = horizontal;
	mDirVertical = vertical;
}

void Ball::update()
{
	mShape.setPosition(sf::Vector2f(mPositionX, mPositionY));
	mBoundingBox.lowerBound.x = mPositionX;
	mBoundingBox.lowerBound.y = mPositionY;
	mBoundingBox.upperBound.x = mPositionX + mBoxSize;
	mBoundingBox.upperBound.y = mPositionY + mBoxSize;

	mCenterPosition.x = mPositionX + mBoxSize / 2;
	mCenterPosition.y = mPositionY + mBoxSize / 2;
}

void Ball::resetAcceleration()
{
	mAcceleration = cAcceleration;
}

void Ball::setPosition(float x, float y)
{
	mPositionX = x;
	mPositionY = y;
}

void Ball::setSpeed(float speed)
{
	mSpeed = speed;
}

void Ball::setAcceleration(float acceleration)
{
	mAcceleration = acceleration;
}

BoundingBox Ball::getBoundingBox() 
{
	return mBoundingBox;
}

float Ball::getPositionX() const
{
	return mPositionX;
}

float Ball::getPositionY() const
{
	return mPositionY;
}

float Ball::getSpeed() const
{
	return mSpeed;
}

float Ball::getVerticalDir() const
{
	return mDirVertical;
}

float Ball::getHorizontalDir() const
{
	return mDirHorizontal;
}

float Ball::getSize() const
{
	return mBoxSize;
}

sf::Vector2f Ball::getCenterPosition() const
{
	return mCenterPosition;
}

float Ball::getAcceleration() const
{
	return mAcceleration;
}
