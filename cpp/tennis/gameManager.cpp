#include "gameManager.h"

GameManager::GameManager() {
    this->InitializePlayers();
};

void GameManager::StartGame(int sets) {
    m_numberOfSets = sets;

    std::cout << "Number of sets not yet implemented, playing only one.\n";
    this->PlaySet();
};