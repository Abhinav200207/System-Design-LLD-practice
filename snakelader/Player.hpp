#include <bits/stdc++.h>
using namespace std;

#include "Piece.hpp"

class Player
{
    string name;
    Piece *piece;

public:
    Player(string name) : name(name) {}

    string getName() { return name; }
    void setName(string name) { this->name = name; }
    void setPiece(Piece *piece) { this->piece = piece; }
    Piece *getPiece() { return this->piece; }
};