#include <bits/stdc++.h>
using namespace std;

class Jumper
{
    int start;
    int end;
    int isSnake; // 1 snake 0 ladder
    pair<int, int> absStart, absEnd;

public:
    Jumper(int start, int end, int isSnake, pair<int, int> absStart, pair<int, int> absEnd) : start(start), end(end), isSnake(isSnake), absStart(absStart), absEnd(absEnd) {}

    pair<int, int> getAbsStart()
    {
        return absStart;
    }
    pair<int, int> getAbsEnd()
    {
        return absEnd;
    }
    int getEnd()
    {
        return end;
    }
    int getStart()
    {
        return start;
    }
    int getIsSnake()
    {
        return isSnake;
    }
};