/*
    File: Player.h
    Description: The source file for the Player object
    Date: Monday, March 16th 2020 12:48 PM
*/

#include "../include/Player.h"


Player::Player(float positionX, float positionY, float sizeX, float sizeY, Color color)
{
    rect = new RectangleShape();
    rect->setPosition(positionX, positionY);
    rect->setSize({sizeX, sizeY});
    rect->setFillColor(color);
    fireBulletsClock.restart();
}

Player::~Player()
{
    printf("Player deleted \n");
    delete rect;
}

void Player::drawTo(RenderWindow& targetWindow)
{
    targetWindow.draw(*rect);
    if(numberOfBulletsBeingFired > 0)
    {
        for(int i = 0; i < numberOfBulletsBeingFired; i++)
        {
            playerBullets[i]->drawTo(targetWindow);
        }
    }
}

void Player::update()
{
    fireBulletsTime = fireBulletsClock.getElapsedTime();
    switch(getDirection())
    {
        case 1: /* Up  */
            if(getPositionY() > 0)
            {
                move(0.0f, -3.0f);
            }
            break;
        case 2: /* Down */
            if(getPositionY() < (600 - 20)) 
            {
                move(0.0f, 3.0f);
            }
            break;
        case 3: /* Left */
            if(getPositionX() > 0)
            {
                move(-3.0f, 0.0f);
            }
            break;
        case 4: /* Right */
            if(getPositionX() < 780)
            {
                move(3.0f, 0.0f);
            }
            break;
        case 5: /* Still (not moving) */
            break;
        default:
            break;
    }
    if(fireBulletsTime.asMilliseconds() > 300)
    {
        fireBulletsClock.restart();
        if(getFireDirection() != 5)
        {
            switch(getFireDirection())
            {
                case 1:
                    fire(1);
                    break;
                case 2:
                    fire(2);
                    break;
                case 3:
                    fire(3);
                    break;
                case 4:
                    fire(4);
                    break;
                default: 
                    break;
            }
            setFireDirection(5);
        }
    }

    if(numberOfBulletsBeingFired > 0)
    {
        for(int i = 0; i < playerBullets.size(); i++)
        {
            if(playerBullets[i]->getPositionX() < 0 || playerBullets[i]->getPositionX() > 800 || playerBullets[i]->getPositionY() < 0 || playerBullets[i]->getPositionY() > 600)
            {
                std::cout << numberOfBulletsBeingFired << std::endl;
                numberOfBulletsBeingFired--;
                Bullet* tmp = playerBullets[i];
                playerBullets.erase(playerBullets.begin() + i);
                delete(tmp);
            }
            playerBullets[i]->update();
        }
    }
}

void Player::move(float x, float y)
{
    rect->move(x, y);
}

void Player::fire(uint8_t direction)
{
    switch(direction)
    {
       case 1:  
            playerBullets.push_back(new Bullet(getPositionX() + 7, getPositionY() - 7, 5, 10, Color::Yellow));
            playerBullets[numberOfBulletsBeingFired]->setDirection(1);
            numberOfBulletsBeingFired++;
            break;
       case 2:
            playerBullets.push_back(new Bullet(getPositionX() + 7, getPositionY() + 7, 5, 10, Color::Yellow));
            playerBullets[numberOfBulletsBeingFired]->setDirection(2);
            numberOfBulletsBeingFired++;
            break;  
       case 3:
            playerBullets.push_back(new Bullet(getPositionX() - 7, getPositionY() + 7, 10, 5, Color::Yellow));
            playerBullets[numberOfBulletsBeingFired]->setDirection(3);
            numberOfBulletsBeingFired++;
            break;
       case 4:
            playerBullets.push_back(new Bullet(getPositionX() + 7, getPositionY() + 7, 10, 5, Color::Yellow));
            playerBullets[numberOfBulletsBeingFired]->setDirection(4);
            numberOfBulletsBeingFired++;
            break;
       case 5:
            break;
       default:
            break; 
    }
}

void Player::checkCollision(Enemy& targetEnemy, bool& targetBool)
{
    if(getHitbox().intersects(targetEnemy.getHitbox()))
    {
        targetBool = true;
    }
}

void Player::setHealth(int8_t value)
{
    health = value;
}

void Player::addHealth(int8_t value)
{
    health += value;
}

void Player::subHealth(int8_t value)
{
    health -= value;
}

void Player::mulHealth(int8_t value)
{
    health *= value;
}

void Player::divHealth(int8_t value)
{
    health /= value;
}

void Player::setDirection(uint8_t value)
{
    direction = value;
}

void Player::setFireDirection(uint8_t value)
{
    fireDirection = value;
}

int8_t Player::getHealth()
{
    return health;
}

uint8_t Player::getDirection()
{
    return direction;
}

uint8_t Player::getFireDirection()
{
    return fireDirection;
}

FloatRect Player::getHitbox()
{
    return rect->getGlobalBounds();
}

float Player::getPositionX()
{
    return rect->getPosition().x;
}

float Player::getPositionY()
{
    return rect->getPosition().y;
}