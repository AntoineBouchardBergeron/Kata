// game.cpp
// Created by Antoine Bouchard-Bergeron
// learning again cpp

#include "gameManager.h"

int main(int argc, char ** argv)
{
    std::cout << "Starting the tennis match!\n"<< std::endl;
    GameManager gm = GameManager();
    gm.StartGame(1);
 
    return 0;
};