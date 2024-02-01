# ifndef PLAYER_H
# define PLAYER_H

#include <iostream>
#include <string.h>
#include "points.h"

using namespace std;

class Player {

    private: 
    Point m_gameScore;
    int m_setScores;
    string m_name;
    Player* p_opponent;

    public:
    Player();
    Player(string name);

    int getGameScore() { return m_gameScore.getScore(); };
    int getSetScore() {return m_setScores; };

    void selectOpponnent( Player* opponent);
    void setName(string name);

    void winExchange();
    void loseExchange();
    void winGame();
    void loseGame();
    // To do, add sets for complete match
    // void winSet();
    // void loseSet(); 

    void printGameScore() {cout << "Player " << m_name << " has a score of " << m_gameScore.toString()<< std::endl;  };

};

# endif // PLAYER_H