#pragma once
#include "SFML/Graphics.hpp"
#include "BoundingBox.h"


class Ball
{
public:
	Ball();
	Ball(float posX, float posY, float radius);
	void draw(sf::RenderWindow* window);
	
	void move(float x, float y);
	void setDirection(float horizontal,float vertical);
	void update();

	void setPosition(float x, float y);



	BoundingBox getBoundingBox();
	float getPositionX() const;
	float getPositionY() const;
	float getSpeed() const;
	float getVerticalDir() const;
	float getHorizontalDir() const;
	float getSize() const;
	sf::Vector2f getCenterPosition() const;

private:
	float mPositionX;
	float mPositionY;
	float mSpeed;
	float mDirVertical;
	float mDirHorizontal;
	float mRadius;
	float mBoxSize;
	sf::Vector2f mCenterPosition;



	BoundingBox mBoundingBox;

	//sf::CircleShape mShape;
	sf::RectangleShape mShape;


};

