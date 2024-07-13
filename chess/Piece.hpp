#include <bits/stdc++.h>
using namespace std;

#include <Color.hpp>

class Piece
{
    string color;
    string name;
    pair<int,int> currpos;

public:
    Piece(string color,string name,pair<int,int> currpos)
    {
        this->color = color;
        this->name = name;
        this->currpos = currpos;
    }

    virtual bool movePiece(pair<int,int> curr,pair<int,int> end);

    string getColor(){
        return color;
    }
};

class Pawn : public Piece {
public:
    Pawn(string color,pair<int,int> currPos) : Piece(color,"Pawn",currPos){}

    bool movePiece(pair<int,int> curr,pair<int,int> end){}
};

class Rook : public Piece {
public:
    Rook(string color,pair<int,int> currPos) : Piece(color,"Rook",currPos){}

    bool movePiece(pair<int,int> curr,pair<int,int> end){}
};

class King : public Piece {
public:
    King(string color,pair<int,int> currPos) : Piece(color,"King",currPos){}

    bool movePiece(pair<int,int> curr,pair<int,int> end){}
};

class Queen : public Piece {
public:
    Queen(string color,pair<int,int> currPos) : Piece(color,"Queen",currPos){}

    bool movePiece(pair<int,int> curr,pair<int,int> end){}
};

class Knight : public Piece {
public:
    Knight(string color,pair<int,int> currPos) : Piece(color,"Knight",currPos){}

    bool movePiece(pair<int,int> curr,pair<int,int> end){}
};

class Wajeer : public Piece {
public:
    Wajeer(string color,pair<int,int> currPos) : Piece(color,"Wajeer",currPos){}

    bool movePiece(pair<int,int> curr,pair<int,int> end){}
};