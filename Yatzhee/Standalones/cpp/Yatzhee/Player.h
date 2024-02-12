#pragma once

#include <string>
#include "Rule.h"

using namespace std; 

class Player{
private:
    string name;
    Rule Rules[20];

public:
    Player();
    Player(string Name);
    void SetName(string name);
    void CompleteSet(int id);
};