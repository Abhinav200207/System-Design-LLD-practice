#include <bits/stdc++.h>
using namespace std;

#include <Color.hpp>

class Piece
{
    Color color;
    string name;
    pair<int,int> currpos;

public:
    Piece(Color color,string name,pair<int,int> currpos)
    {
        this->color = color;
        this->name = name;
        this->currpos = currpos;
    }

    virtual bool movePiece(pair<int,int> curr,pair<int,int> end);

    Color getColor(){
        return color;
    }
};

class Pawn : public Piece {
public:
    Pawn(Color color,pair<int,int> currPos) : Piece(color,"Pawn",currPos){}

    bool movePiece(pair<int,int> curr,pair<int,int> end){}
};

class Rook : public Piece {
public:
    Rook(Color color,pair<int,int> currPos) : Piece(color,"Rook",currPos){}

    bool movePiece(pair<int,int> curr,pair<int,int> end){}
};

class King : public Piece {
public:
    King(Color color,pair<int,int> currPos) : Piece(color,"King",currPos){}

    bool movePiece(pair<int,int> curr,pair<int,int> end){}
};

class Queen : public Piece {
public:
    Queen(Color color,pair<int,int> currPos) : Piece(color,"Queen",currPos){}

    bool movePiece(pair<int,int> curr,pair<int,int> end){}
};

class Knight : public Piece {
public:
    Knight(Color color,pair<int,int> currPos) : Piece(color,"Knight",currPos){}

    bool movePiece(pair<int,int> curr,pair<int,int> end){}
};

class Bishop : public Piece {
public:
    Bishop(Color color,pair<int,int> currPos) : Piece(color,"Bishop",currPos){}

    bool movePiece(pair<int,int> curr,pair<int,int> end){}
};