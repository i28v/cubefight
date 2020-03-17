/*
    File: Enemy.h
    Description: The header file for the enemy object which will attack the player
    Date: Tuesday, March 17th 2020 10:26 AM
*/

#ifndef ENEMY_INCLUDED
#define ENEMY_INCLUDED

#include "data.h"
#include "Bullet.h"
#include "Player.h"

class Enemy 
{
public:
    Enemy(float positionX, float positionY, float sizeX, float sizeY, Color color);
    virtual ~Enemy();
    void drawTo(RenderWindow& targetWindow);
    void update(float* playerPosX, float* playerPosY);
    void move(float x, float y);
    FloatRect getHitbox();
    float getPositionX();
    float getPositionY();
private:
    RectangleShape* rect;
};

#endif /* ENEMY_INCLUDED */
