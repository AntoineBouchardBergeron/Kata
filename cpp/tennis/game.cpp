// game.cpp
// Created by Antoine Bouchard-Bergeron
// learning again cpp

#include "game.h"

int Game::main()
{
    std::cout << "Starting the tennis match!\n";
    GameManager gm = GameManager();
    gm.StartGame(1);

    return 0;
};