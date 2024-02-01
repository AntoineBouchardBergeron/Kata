# ifndef GAMEMANAGER_H
# define GAMEMANAGER_H

#include <iostream>
#include <string.h>
#include "player.h"

class GameManager{
    private:
    int m_numberOfSets;
    Player m_one;
    Player m_two;

    void InitializePlayers() {
        string one_name;
        string two_name;
        std::cout << "Type in first player's name"<< std::endl;
        std::cin >> one_name;
        std::cout << "Type in opponent's name"<< std::endl;
        std::cin >> two_name;

        this->m_one.setName(one_name);
        this->m_two.setName(two_name);
        this->m_one.selectOpponnent(&m_two);
    };

    void PlaySet(){
    while (
        this->m_one.getSetScore() < 5 && this->m_two.getSetScore() < 5 ||
        abs(this->m_one.getSetScore() - this->m_two.getSetScore()) < 2
        )
    {
        if (std::rand() % 2 == 1)
        {
            this->m_one.winExchange();
        }
        else
        {
            this->m_two.winExchange();
        }
    }
    }

    public: 
    GameManager();
    
    void StartGame(int sets);

};

# endif // GAMEMANAGER_H