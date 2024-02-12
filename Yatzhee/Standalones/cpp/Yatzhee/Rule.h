#pragma once

#include "Die.h"

class Rule
{
    public:
    virtual bool IsCompletable(Die Dice[]){return false;}; 
    Rule();
    ~Rule();

    protected: 
    int id = 0;
    int points = 0;
    bool isCompleted = false;

    int Complete(Die Dice[]) {
        this->isCompleted = true;
        if (this->IsCompletable(Dice)){
            return points;
        }
        else {
            return 0;
        }
    }; 
};

