/*
    File: Enemy.h
    Description: The source file for the enemy object which will attack the player
    Date: Tuesday, March 17th 2020 10:26 AM
*/

#include "../include/Enemy.h"

Enemy::Enemy(float positionX, float positionY, float sizeX, float sizeY, Color color)
{
    rect = new RectangleShape();
    rect->setPosition(positionX, positionY);
    rect->setSize({sizeX, sizeY});
    rect->setFillColor(color);
}

Enemy::~Enemy()
{
    delete rect;
}

void Enemy::drawTo(RenderWindow& targetWindow)
{
    targetWindow.draw(*rect);
}

void Enemy::update(float* playerPosX, float* playerPosY)
{
    if(*playerPosX > getPositionX())
    {
        move(1.5f, 0.0f);
    }
    if(*playerPosX < getPositionX())
    {
       move(-1.5f, 0.0f);
    }
    if(*playerPosY > getPositionY())
    {
       move(0.0f, 1.5f);
    }
    if(*playerPosY < getPositionY())
    {
       move(0.0f, -1.5f);
    }
}

void Enemy::move(float x, float y)
{
    rect->move(x, y);
}

float Enemy::getPositionX()
{
    return rect->getPosition().x;
}

float Enemy::getPositionY()
{
    return rect->getPosition().y;
}

FloatRect Enemy::getHitbox()
{
    return rect->getGlobalBounds();
}