#include <bits/stdc++.h>
using namespace std;

#include <Cell.hpp>
#include <Color.hpp>
#include <Piece.hpp>

class Board
{
    int size;
    vector<vector<Cell *>> Cells;

public:
    Board(int size)
    {
        this->size = size;
        for (int i = 0; i < size; i++)
        {
            vector<Cell *> temp;
            int flag = 0;
            for (int j = 0; j < size; j++)
            {
                if (flag == 0)
                {
                    temp.push_back(new Cell("WHITE", {i, j},true));
                    flag = !flag;
                }
                else
                {
                    temp.push_back(new Cell("BLACK", {i, j},true));
                    flag = !flag;
                }
            }
            Cells.push_back(temp);
        }

        // initlize the pieces like
        Cells[0][0]->setPieces(new Rook("BLACK",{0,0}));
        Cells[0][1]->setPieces(new Knight("BLACK",{0,1}));
        Cells[0][2]->setPieces(new Wajeer("BLACK",{0,2}));
        Cells[0][3]->setPieces(new King("BLACK",{0,3}));
        Cells[0][4]->setPieces(new Queen("BLACK",{0,4}));
        Cells[0][5]->setPieces(new Wajeer("BLACK",{0,5}));
        Cells[0][6]->setPieces(new Knight("BLACK",{0,6}));
        Cells[0][7]->setPieces(new Rook("BLACK",{0,7}));

        Cells[1][0]->setPieces(new Pawn("BLACK",{1,0}));
        Cells[1][1]->setPieces(new Pawn("BLACK",{1,1}));
        Cells[1][2]->setPieces(new Pawn("BLACK",{1,2}));
        Cells[1][3]->setPieces(new Pawn("BLACK",{1,3}));
        Cells[1][4]->setPieces(new Pawn("BLACK",{1,4}));
        Cells[1][5]->setPieces(new Pawn("BLACK",{1,5}));
        Cells[1][6]->setPieces(new Pawn("BLACK",{1,6}));
        Cells[1][7]->setPieces(new Pawn("BLACK",{1,7}));

        
        Cells[7][0]->setPieces(new Rook("WHITE",{7,0}));
        Cells[7][1]->setPieces(new Knight("WHITE",{7,1}));
        Cells[7][2]->setPieces(new Wajeer("WHITE",{7,2}));
        Cells[7][3]->setPieces(new King("WHITE",{7,3}));
        Cells[7][4]->setPieces(new Queen("WHITE",{7,4}));
        Cells[7][5]->setPieces(new Wajeer("WHITE",{7,5}));
        Cells[7][6]->setPieces(new Knight("WHITE",{7,6}));
        Cells[7][7]->setPieces(new Rook("WHITE",{7,7}));

        Cells[6][0]->setPieces(new Pawn("WHITE",{6,0}));
        Cells[6][1]->setPieces(new Pawn("WHITE",{6,1}));
        Cells[6][2]->setPieces(new Pawn("WHITE",{6,2}));
        Cells[6][3]->setPieces(new Pawn("WHITE",{6,3}));
        Cells[6][4]->setPieces(new Pawn("WHITE",{6,4}));
        Cells[6][5]->setPieces(new Pawn("WHITE",{6,5}));
        Cells[6][6]->setPieces(new Pawn("WHITE",{6,6}));
        Cells[6][7]->setPieces(new Pawn("WHITE",{6,7}));
    }

    Cell* getCell(int x,int y){
        return Cells[x][y];
    }

    void displayBoard(){}
};