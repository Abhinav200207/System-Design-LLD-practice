#ifndef PIECE_HPP
#define PIECE_HPP

#include <bits/stdc++.h>
using namespace std;

class Piece
{
    pair<int, int> absPos;
    int pos;

public:
    Piece(pair<int, int> absPos, int pos) : absPos(absPos), pos(pos) {}

    pair<int, int> getAbsPos()
    {
        return absPos;
    }
    int getPos()
    {
        return pos;
    }
    void setPos(int pos)
    {
        this->pos = pos;
    }
};


#endif // PIECE_HPP