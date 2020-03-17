/*
    File: Bullet.h
    Description: The header file for the bullet object which will be used by the player
    Date: Monday, March 16th 2020 7:06 PM
*/

#ifndef BULLET_INCLUDED
#define BULLET_INCLUDED

#include "data.h"


class Bullet
{
public:
    Bullet(float positionX, float positionY, float sizeX, float sizeY, Color color);
    virtual ~Bullet();
    void drawTo(RenderWindow& targetWindow);
    void update();
    void move(float x, float y);
    void setPosition(float x, float y);
    void setRotation(float value);
    void setDirection(uint8_t value);
    float getPositionX();
    float getPositionY();
    float speed;
    uint8_t getDirection();
    FloatRect getHitbox();
private:
    RectangleShape* rect;
    uint8_t direction;
};

#endif /* BULLET_INCLUDED */