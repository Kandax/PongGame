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
	float getPositionX();
	float getPositionY();
	float getSpeed();
	float getVerticalDir();
	float getHorizontalDir();
	float getSize();
private:
	float mPositionX;
	float mPositionY;
	float mSpeed;
	float mDirVertical;
	float mDirHorizontal;
	float mRadius;
	float mBoxSize;




	BoundingBox mBoundingBox;

	//sf::CircleShape mShape;
	sf::RectangleShape mShape;


};

