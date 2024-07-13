#include <bits/stdc++.h>
using namespace std;

#include "Piece.hpp"

class Cell
{
    pair<int, int> absPos;
    int pos;
    set<Piece *> pieces;
    Jumper *jumper;
    bool isAnythingPresent; // true present false not present for snake and ladder

public:
    Cell(pair<int, int> absPos, int pos) : absPos(absPos), pos(pos), isAnythingPresent(false) {}

    pair<int, int> getAbsPos()
    {
        return absPos;
    }
    int getPos()
    {
        return pos;
    }
    void setJumper(Jumper *jumper)
    {
        this->jumper = jumper;
    }
    Jumper *getJumper()
    {
        return this->jumper;
    }
    bool getIsAnythingPresent()
    {
        return this->isAnythingPresent;
    }
    void setIsAnythingPresent(bool isAnything)
    {
        this->isAnythingPresent = isAnything;
    }
    void addPiece(Piece *piece)
    {
        pieces.insert(piece);
    }
    void removePiece(Piece *piece)
    {
        pieces.erase(piece);
    }
};