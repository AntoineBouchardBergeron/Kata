# ifndef POINTS_H
# define POINTS_H

#include <iostream>
#include <string.h>

using namespace std;

class Point{

    private: 
    int m_score;

    public:
    Point();
    ~Point(){};

    string toString() const {
        switch (m_score) {
            case 0:
                return "Love";

            case 1: 
                return "Fifteen";

            case 2: 
                return "Thrity";

            case 3: 
                return "Forty";

            case 4: 
                return "Advantage";

            case 5: 
                return "Deuce";

        }
        return "This should not happen";
    };

    int  getScore() { return this->m_score; };
    void increaseScore() { this->m_score++; };
    void decreaseScore() { this->m_score--; };
    void resetScore()    { this->m_score = 0; };

};

# endif