/* 
    File: Game.h
    Description: The header file for the main game, with all of the other objects inside of it
    Date: Monday, March 16th 2020 12:33 PM
*/

#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "data.h"
#include "Player.h"
#include "Enemy.h"
#include "Lehmer.h"

class Game 
{
public:
    Game();
    virtual ~Game();
    void start();
private:
    RenderWindow* gameWindow;
    Event* gameEventHandler;
    Player* gamePlayer;
    std::vector<Enemy*> gameEnemies;
    Clock spawnEnemiesClock;
    Time spawnEnemiesTime;
    void init();
    void cleanUp();
    void mainGameLoop();
    void handleEvents(Event& targetEventHandler, RenderWindow& targetRenderWindow);
    void handleInput();
    void updateObjects();
    void drawToScreen(RenderWindow& targetRenderWindow);
    void spawnEnemy(float positionX, float positionY);
    uint16_t spawnRate;
    uint16_t numberOfEnemies;
    bool gameOver;
    bool gamePaused;
};

#endif /* GAME_INCLUDED */