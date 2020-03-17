/*
    File: Game.cpp
    Description: The source file for the main game, with all of the other objects inside of it
    Date: Monday, March 16th 2020 12:41 PM
*/

#include "../include/Game.h"

/*
    This is the function that gets executed when the game object is created (it actually doesn't do anything)
*/

Game::Game()
{
    /* ... */
}

/*
    This is the function that gets executed when the game object is destroyed (it also destroys the other pointer objets inside of it)
*/

Game::~Game()
{
    delete gameWindow;
    delete gameEventHandler;
    delete gamePlayer;
}

/* 
    This sets up all of the other objects
*/

void Game::init()
{
    nLehmer = time(NULL);
    gameWindow = new RenderWindow(VideoMode(800, 600), "Cube fight", Style::Titlebar | Style::Close);
    gameEventHandler = new Event();
    gameWindow->setFramerateLimit(60); /* The human eye can't really notice framerates higher than 60 frames per second, so let's just set the limit to that so the CPU can run more efficently */
    gamePlayer = new Player(350, 300, 20, 20, Color::Blue);
    gameOver = false;
}

/*
    This handles window events, such as the close button on the window being pressed 
*/

void Game::handleEvents(Event& targetEventHandler, RenderWindow& targetRenderWindow)
{
    while(targetRenderWindow.pollEvent(targetEventHandler))
    {
        if(targetEventHandler.type == Event::Closed)
        {
            targetRenderWindow.close();
            delete this;
            exit(0);
        }
    }
}

/*
    This handles input from the keyboard, if a certain key is pressed this function will tell the game to do something
*/

void Game::handleInput()
{
    if(Keyboard::isKeyPressed(Keyboard::Up))
    {
        gamePlayer->setDirection(1);
    }

    if(Keyboard::isKeyPressed(Keyboard::Down))
    {
        gamePlayer->setDirection(2);
    }

    if(Keyboard::isKeyPressed(Keyboard::Left))
    {
        gamePlayer->setDirection(3);
    }

    if(Keyboard::isKeyPressed(Keyboard::Right))
    {
        gamePlayer->setDirection(4);
    }

    else if(!Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::Down) && !Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Down))
    {
        gamePlayer->setDirection(5);
    }

    if(Keyboard::isKeyPressed(Keyboard::W))
    {
        gamePlayer->setFireDirection(1);
    }

    if(Keyboard::isKeyPressed(Keyboard::S))
    {
        gamePlayer->setFireDirection(2);
    }

    if(Keyboard::isKeyPressed(Keyboard::A))
    {
        gamePlayer->setFireDirection(3);
    }

    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        gamePlayer->setFireDirection(4);
    }

    else if(!Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::S) && !Keyboard::isKeyPressed(Keyboard::D))
    {
        gamePlayer->setFireDirection(5);
    }
}

/*
    This updates the games objects respectively, such as moving the player, moving the enemies and shooting a bullet
*/

void Game::updateObjects()
{
    gamePlayer->update();
}

/*
    This clears the screen and draws all of the objects onto the screen
*/

void Game::drawToScreen(RenderWindow& targetRenderWindow)
{
    targetRenderWindow.clear(Color::White);
    gamePlayer->drawTo(targetRenderWindow);
    targetRenderWindow.display();
}

/*
    This executes most of the functions above in a loop that doesn't end until the gameOver boolean gets set to true
*/

void Game::mainGameLoop()
{
    while(gameOver != true)
    {
        handleEvents(*gameEventHandler, *gameWindow);
        handleInput();
        drawToScreen(*gameWindow);
        updateObjects();
    }
}

/* 
    This is the function that starts the game, which gets executed in the main.cpp file 
*/

void Game::start()
{
    init();
    mainGameLoop();
}