#include <bits/stdc++.h>
using namespace std;

#include "Color.hpp"

class Player
{
    string name;
    Color color;

public:
    Player(string name, Color color)
    {
        this->color = color;
        this->name = name;
    }

    string getName() {return name;}
    Color getColor() {return color;}
};