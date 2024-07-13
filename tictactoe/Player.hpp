#include <bits/stdc++.h>
using namespace std;

class Player
{
    string choosedMark;
    string name;

public:
    Player(string choosedMark, string name) : choosedMark(choosedMark), name(name) {}

    string getName()
    {
        return name;
    }
    string getChoosedMark()
    {
        return choosedMark;
    }
};