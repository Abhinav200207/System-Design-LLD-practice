#include <bits/stdc++.h>
using namespace std;

#include "Cells.hpp"

class Board
{
    vector<vector<Cell *>> Cells;
    int sz;

public:
    Board(int sz)
    {
        this->sz = sz;
        for (int i = 0; i < sz; i++)
        {
            vector<Cell *> temp;
            for (int j = 0; j < sz; j++)
            {
                temp.push_back(new Cell({i, j}, true));
            }
            Cells.push_back(temp);
        }
    }

    Cell *getCell(int x, int y)
    {
        return Cells[x][y];
    }

    void markCell(int x, int y, Mark *mark)
    {
        Cells[x][y]->setMark(mark);
        Cells[x][y]->setIsEmpty(false);
    }

    bool isAnyCellLeft()
    {
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                if (Cells[i][j]->getIsEmpty() == true)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool checkIfWin(string choosedMark, int x, int y)
    {
        bool a = true, b = true, c = true, d = true;
        for (int i = 0; i < sz; i++)
        {
            if (Cells[i][y]->getIsEmpty() == true || Cells[i][y]->getMark()->getSign() != choosedMark)
            {
                a = false;
            }
        }
        for (int j = 0; j < sz; j++)
        {
            if (Cells[x][j]->getIsEmpty() == true || Cells[x][j]->getMark()->getSign() != choosedMark)
            {
                b = false;
            }
        }
        for (int i = 0; i < sz; i++)
        {
            if (Cells[i][i]->getIsEmpty() == true || Cells[i][i]->getMark()->getSign() != choosedMark)
            {
                c = false;
            }
        }
        for (int i = 0; i < sz; i++)
        {
            if (Cells[i][sz - i - 1]->getIsEmpty() == true || Cells[i][sz - i - 1]->getMark()->getSign() != choosedMark)
            {
                d = false;
            }
        }
        return a | b | c | d;
    }

    void printBoard()
    {
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                if (Cells[i][j]->getIsEmpty() == true)
                {
                    cout << "|  |";
                }
                else
                {
                    cout << "|" << Cells[i][j]->getMark()->getSign() << " |";
                }
            }
            cout << endl;
        }
    }
};