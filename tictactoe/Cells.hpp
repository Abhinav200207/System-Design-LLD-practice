#include <bits/stdc++.h>
using namespace std;

#include "Mark.hpp"

class Cell
{
    pair<int, int> pos;
    int isEmpty;
    Mark *mark;

public:
    Cell(pair<int, int> pos, int isEmpty)
    {
        this->pos = pos;
        this->isEmpty = isEmpty;
    }

    pair<int, int> getPos()
    {
        return pos;
    }
    int getIsEmpty()
    {
        return isEmpty;
    }
    Mark *getMark()
    {
        return mark;
    }
    void setMark(Mark *mark)
    {
        this->mark = mark;
    }
    void setIsEmpty(bool isEmpty)
    {
        this->isEmpty = isEmpty;
    }
};