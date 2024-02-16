#include "game.h"

Game::Game(){
    this->InitializeGame();
    this->NextPlayer();
}

void Game::InitializeGame(){
    std::cout << "How many players are we expecting : ";
    std::cin >> this->m_playerCount;

    Player players[this->m_playerCount];

    for (int i = 0; i < m_playerCount; i++) {
        std::cout << "Enter a name for this player: ";
        string name;
        std::cin >> name;
        players[i].SetName(name);
        std::cout << "Well met " << players[i].GetName() << endl;
    }

    this->m_players = &players[0];
    this->PrintPlayerTurn();
};

void Game::NextPlayer(){
    this->m_activePlayer++;
    if (this->m_activePlayer >= this->m_playerCount){
        this->m_activePlayer = 0;
    }
    this->PrintPlayerTurn();
};

void Game::PrintPlayerTurn(){
    std::cout << "It's " << this->m_players[this->m_activePlayer].GetName() << "'s turn" << std::endl;
};