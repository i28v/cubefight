/*
    File: Bullet.cpp
    Description: The source file for the bullet object which will be used by the player
    Date: Monday, March 16th 2020 7:13 PM
*/

#include "../include/Bullet.h"

Bullet::Bullet(float positionX, float positionY, float sizeX, float sizeY, Color color)
{
    rect = new RectangleShape();
    rect->setPosition(positionX, positionY);
    rect->setSize({sizeX, sizeY});
    rect->setFillColor(color);
    speed = 15;
}

Bullet::~Bullet()
{
    delete rect;
}

void Bullet::drawTo(RenderWindow& targetWindow)
{
    targetWindow.draw(*rect);
}

void Bullet::update()
{
    switch(getDirection())
    {
        case 1:
            move(0.0f, -speed);
            break;
        case 2:
            move(0.0f, speed);
            break;
        case 3:
            move(-speed, 0.0f);
            break;
        case 4:
            move(speed, 0.0f);
            break;
        case 5:
            break;
        default:
            break;
    }
}

void Bullet::move(float x, float y)
{
    rect->move(x, y);
}

void Bullet::setPosition(float x, float y)
{
    rect->setPosition(x, y);
}

void Bullet::setRotation(float value)
{
    rect->setRotation(value);
}

void Bullet::setDirection(uint8_t value)
{
    direction = value;
}

float Bullet::getPositionX()
{
    return rect->getPosition().x;
}

float Bullet::getPositionY()
{
    return rect->getPosition().y;
}

uint8_t Bullet::getDirection()
{
    return direction;
}

FloatRect Bullet::getHitbox()
{
    return rect->getGlobalBounds();
}
