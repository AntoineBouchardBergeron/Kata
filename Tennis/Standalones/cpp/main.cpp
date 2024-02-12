// game.cpp
// Created by Antoine Bouchard-Bergeron
// learning again cpp

#include "gameManager.h"

int main()
{
    std::cout << "Starting the tennis match!"<< std::endl;

    GameManager gm = GameManager();

    std::cout << "Game is about to start!" << std::endl;

    gm.StartGame(1);
 
    return 0;
};