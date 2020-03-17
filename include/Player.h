/*
    File: Player.h
    Description: The header file for the Player object
    Date: Monday, March 16th 2020 12:31 PM
*/

#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include "data.h"
#include "Bullet.h"
#include "Enemy.h"

class Enemy;

class Player
{
public:
    Player(float positionX, float positionY, float sizeX, float sizeY, Color color);
    virtual ~Player();
    void drawTo(RenderWindow& targetWindow);
    void update();
    void move(float x, float y);
    void fire(uint8_t direction);
    void checkCollision(Enemy& targetEnemy, bool& targetBool);
    void setHealth(int8_t value);
    void addHealth(int8_t value);
    void subHealth(int8_t value);
    void mulHealth(int8_t value);
    void divHealth(int8_t value);
    void setDirection(uint8_t value);
    void setFireDirection(uint8_t value);
    Clock fireBulletsClock;
    Time fireBulletsTime;
    FloatRect getHitbox();
    int8_t getHealth();
    uint8_t getDirection();
    uint8_t getFireDirection();
    uint16_t numberOfBulletsBeingFired;
    float getPositionX();
    float getPositionY();
    std::vector<Bullet*> playerBullets;
private:
    RectangleShape* rect;
    int8_t health;
    uint8_t direction;
    uint8_t fireDirection;
};


#endif /* PLAYER_INCLUDED */
