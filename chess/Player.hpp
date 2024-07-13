#include <bits/stdc++.h>
using namespace std;

class Player
{
    string name;
    string color;

public:
    Player(string name, string color)
    {
        this->color = color;
        this->name = name;
    }

    string getName() {return name;}
    string getColor() {return color;}
};