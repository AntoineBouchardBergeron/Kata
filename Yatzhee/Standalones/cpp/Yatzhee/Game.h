#pragma once

#include "Die.h"
#include "Player.h"
#include <iostream>
#include <string>

class Game{
private:
    Player * m_players;
    int m_playerCount;
    int m_activePlayer;
    
    Die m_dices[5];
    uint8_t m_rollCount;

public:
    Game();
    void NextPlayer();
private:
    void InitializeGame();
    void PrintPlayerTurn();
    

};