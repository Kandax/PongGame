#include "Player.h"

Player::Player() 
	: mPositionX(0)
	, mPositionY(0)
	, mSpeed(10)
	, mWitdh(32)
	, mHeight(96)
	, mBoundingBox{ sf::Vector2f(mPositionX,mPositionY), sf::Vector2f(mPositionX + mWitdh,mPositionY + mHeight) }
	, mShape(sf::Vector2f(mWitdh, mHeight))
	, mCenterPosition{mPositionX + mWitdh/2, mPositionY + mHeight/2}
{
	mShape.setFillColor(sf::Color::Blue);
}

Player::Player(float posX, float posY, float width, float height) 
	: mPositionX(posX)
	, mPositionY(posY)
	, mSpeed(100)
	, mWitdh(width)
	, mHeight(height)
	, mBoundingBox{ sf::Vector2f(mPositionX,mPositionY), sf::Vector2f(mPositionX + mWitdh,mPositionY + mHeight) }
	, mShape(sf::Vector2f(mWitdh, mHeight))
	, mCenterPosition{ mPositionX + mWitdh / 2, mPositionY + mHeight / 2 }

{
	mShape.setFillColor(sf::Color::Blue);
}


void Player::draw(sf::RenderWindow* window)
{
	window->draw(mShape);
}

void Player::move(float x, float y)
{
	mPositionX += x;
	mPositionY += y;
}

void Player::update()
{
	mShape.setPosition(sf::Vector2f(mPositionX, mPositionY));
	mBoundingBox.lowerBound.x = mPositionX;
	mBoundingBox.lowerBound.y = mPositionY;
	mBoundingBox.upperBound.x = mPositionX + mWitdh;
	mBoundingBox.upperBound.y = mPositionY + mHeight;
	mCenterPosition.x = mPositionX + mWitdh / 2;
	mCenterPosition.y = mPositionY + mHeight / 2;
}

void Player::setPosition(float x, float y)
{
	mPositionX = x;
	mPositionY = y;
}

void Player::setSpeed(float speed)
{
	mSpeed = speed;
}

BoundingBox Player::getBoundingBox()
{
	return mBoundingBox;
}

float Player::getPositionX()
{
	return mPositionX;
}

float Player::getPositionY()
{
	return mPositionY;
}

float Player::getSpeed()
{
	return mSpeed;
}

sf::RectangleShape* Player::getShape()
{
	return &mShape;
}

float Player::getWitdh()
{
	return mWitdh;
}

float Player::getHeight()
{
	return mHeight;
}

sf::Vector2f Player::getCenterPosition()
{
	return mCenterPosition;
}
