#pragma once

#include <string>
#include "Rule.h"

using namespace std;

class Player
{
private:
    string _name;
    Rule *_Rules;

public:
    Player();
    Player(string Name);
    void SetName(string name)
    {
        this->_name = name;
    };
    void CompleteSet(int id);
    string GetName() { return this->_name; };
};