#include "gameManager.h"

GameManager::GameManager() {
    this->InitializePlayers();
};

void GameManager::StartGame(int sets) {
    this->m_numberOfSets = sets;

    std::cout << "Number of sets not yet implemented, playing only one.\n"<< std::endl;
    this->PlaySet();
};