

#include "player.h"

Player::Player(){};

Player::Player(string name)
    {
        this->m_name = name;
    };

void Player::selectOpponnent (Player* opponent){
    this->p_opponent = opponent;
    opponent->selectOpponnent(this);
};

void Player::winExchange() {
    std::cout << this->m_name << " won the exchange"<< std::endl;
    switch (this->m_gameScore.getScore()){
        case 0: // Love
            this->m_gameScore.increaseScore();
            break;

        case 1: // Fifteen
            this->m_gameScore.increaseScore();
            break;

        case 2: // Thirty
            this->m_gameScore.increaseScore();
            break;

        case 3: // Forty
            if (this->p_opponent->getGameScore() == 3){
                this->p_opponent->m_gameScore.increaseScore();
                m_gameScore.increaseScore();
            }
            else
            {
                winGame();
            }
            break;

        case 4: // Deuce
            if(this->p_opponent->getGameScore() == 5){
                this->p_opponent->loseExchange();
            } else {
                this->m_gameScore.increaseScore();
            }

        case 5: // Advantage
            winGame();
            break;
    }
    this->printGameScore();
}

void Player::loseExchange() {
    this->m_gameScore.decreaseScore();
}

void Player::winGame() {
    this->m_setScores++;
    this->m_gameScore.resetScore();
    this->p_opponent->loseGame();
}

void Player::loseGame() {
    this->m_gameScore.resetScore();
}

