#include <bits/stdc++.h>
using namespace std;

#include<Piece.hpp>
#include<Color.hpp>

class Cell{
    Piece *piece;
    string color;
    pair<int,int> pos;
    int isEmpty;
public:
    Cell(string color,pair<int,int> pos,int isEmpty){
        this->color = color;
        this->isEmpty = isEmpty;
        this->pos = pos;
    }
    Piece *getPieces(){
        return piece;
    }
    void setPieces(Piece *piece){
        this->piece = piece;
    }
    int getIsEmpty(){
        return isEmpty;
    }
    void setIsEmpty(int isEmpty){
        this->isEmpty = isEmpty;
    }
};