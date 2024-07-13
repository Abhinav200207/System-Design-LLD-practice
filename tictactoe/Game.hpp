#include <bits/stdc++.h>
using namespace std;

#include "Player.hpp"
#include "Board.hpp"
#include "Mark.hpp"

class Game
{
    vector<Player *> players;
    int turn = 0;
    Board *board;
    int sz = 3;
    string winner = "";

public:
    Game(string n1, string n2, string choose1, string choose2)
    {
        board = new Board(sz);
        Player *p1 = new Player(choose1, n1);
        Player *p2 = new Player(choose2, n2);

        players.push_back(p1);
        players.push_back(p2);
    }

    void startGame()
    {
        while (winner == "")
        {
            if (board->isAnyCellLeft() == false)
            {
                winner = "Draw";
                cout << "draw!!\n";
                break;
            }

            Player *p = players[turn];

            cout << "Turn of " << p->getName() << "\n";
            cout << "Choose the cell indexes row and collumn\n";

            int x, y;
            cin >> x >> y;

            Cell *cell = board->getCell(x, y);

            if (cell->getIsEmpty() == false)
            {
                cout << "Choose another cell, its alread filled\n";
                continue;
            }
            if (p->getChoosedMark() == "X")
            {
                board->markCell(x, y, new MarkX());
            }
            else
            {
                board->markCell(x, y, new MarkO());
            }

            board->printBoard();
            if (board->checkIfWin(p->getChoosedMark(), x, y))
            {
                winner = p->getName();
                break;
            }
            turn = 1 - turn;
        }
        cout << "Winner is " << winner;
    }
};