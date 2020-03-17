/*
    File: main.cpp
    Description: The source file for the main program, most of the code is in Game.cpp though, this just gets everything started.
    Date: Monday, March 16th 2020 12:39 PM
*/

#include "../include/Game.h"

int main(int argc, char* argv[])
{
    Game* mainGame = new Game();
    mainGame->start();
    return 0;
}