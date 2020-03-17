/* 
    File: Game.h
    Description: The header file for the main game, with all of the other objects inside of it
    Date: Monday, March 16th 2020 12:33 PM
*/

#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "data.h"
#include "Player.h"
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
    void init();
    void cleanUp();
    void mainGameLoop();
    void handleEvents(Event& targetEventHandler, RenderWindow& targetRenderWindow);
    void handleInput();
    void updateObjects();
    void drawToScreen(RenderWindow& targetRenderWindow);
    bool gameOver;
    bool gamePaused;

};

#endif /* GAME_INCLUDED */