#include <bits/stdc++.h>
using namespace std;

#include "Jumper.hpp"
#include "Cell.hpp"

class Board
{
    vector<Jumper *> jumpers;
    vector<vector<Cell *>> cells;

public:
    Board(int numSnakes, int numLadder)
    {
        for (int i = 0; i < 10; i++)
        {
            vector<Cell *> temp;
            for (int j = 0; j < 10; j++)
            {
                temp.push_back(new Cell({i, j}, calcPos(i, j)));
            }
            cells.push_back(temp);
        }

        for (int i = 0; i < numSnakes; i++)
        {
            int head = generateRandom(0, 99);
            int tail = generateRandom(0, head);
            pair<int, int> abshead = calcAbsPos(head);
            Jumper *jumper = new Jumper(head, tail, 1, abshead, calcAbsPos(tail));
            cells[abshead.first][abshead.second]->setJumper(jumper);
            cells[abshead.first][abshead.second]->setIsAnythingPresent(true);
        }
        for (int i = 0; i < numLadder; i++)
        {
            int head = generateRandom(0, 99);
            int tail = generateRandom(0, head);
            pair<int, int> abstail = calcAbsPos(tail);
            Jumper *jumper = new Jumper(tail, head, 0, abstail, calcAbsPos(head));
            cells[abstail.first][abstail.second]->setJumper(jumper);
            cells[abstail.first][abstail.second]->setIsAnythingPresent(true);
        }
    }

    int calcPos(int i, int j)
    {
        if (i % 2 == 0)
            return i * 10 + j;
        return i * 10 + (10 - j - 1); // {1,8} ---> 11 ===> 1*10 + (10 - 8  - 1)
    }
    pair<int, int> calcAbsPos(int x)
    {
        if ((x / 10) % 2 == 0)
        {
            return {x / 10, x % 10};
        }
        return {x / 10, 10 - (x % 10) - 1}; // 10 - 3 - 1 = 6
    }
    Cell *getCell(int x)
    {
        pair<int, int> p = calcAbsPos(x);
        return cells[p.first][p.second];
    }
    int generateRandom(int upperBound, int lowerBound)
    {
        vector<int> random_vector;
        for (unsigned int i = upperBound; i <= lowerBound; ++i)
            random_vector.push_back(i);

        random_shuffle(random_vector.begin(), random_vector.end());
        return random_vector[0];
    }
};