#include <bits/stdc++.h>
using namespace std;

#include "Game.hpp"

int main()
{
    Game *game = new Game("Abhinav", "Maurya", "X", "O");
    game->startGame();
    return 0;
}

// class Player
// {
//     string choosedMark;
//     string name;

// public:
//     Player(string choosedMark, string name) : choosedMark(choosedMark), name(name) {}

//     string getName()
//     {
//         return name;
//     }
//     string getChoosedMark()
//     {
//         return choosedMark;
//     }
// };

// class Mark
// {
//     string sign;

// public:
//     Mark(string sign)
//     {
//         this->sign = sign;
//     }
//     string getSign()
//     {
//         return sign;
//     }
// };

// class MarkX : public Mark
// {
// public:
//     MarkX() : Mark("X") {}
// };

// class MarkO : public Mark
// {
// public:
//     MarkO() : Mark("O") {}
// };

// class Cell
// {
//     pair<int, int> pos;
//     int isEmpty;
//     Mark *mark;

// public:
//     Cell(pair<int, int> pos, int isEmpty)
//     {
//         this->pos = pos;
//         this->isEmpty = isEmpty;
//     }

//     pair<int, int> getPos()
//     {
//         return pos;
//     }
//     int getIsEmpty()
//     {
//         return isEmpty;
//     }
//     Mark *getMark()
//     {
//         return mark;
//     }
//     void setMark(Mark *mark)
//     {
//         this->mark = mark;
//     }
//     void setIsEmpty(bool isEmpty)
//     {
//         this->isEmpty = isEmpty;
//     }
// };

// class Board
// {
//     vector<vector<Cell *>> Cells;
//     int sz;

// public:
//     Board(int sz)
//     {
//         this->sz = sz;
//         for (int i = 0; i < sz; i++)
//         {
//             vector<Cell *> temp;
//             for (int j = 0; j < sz; j++)
//             {
//                 temp.push_back(new Cell({i, j}, true));
//             }
//             Cells.push_back(temp);
//         }
//     }

//     Cell *getCell(int x, int y)
//     {
//         return Cells[x][y];
//     }

//     void markCell(int x, int y, Mark *mark)
//     {
//         Cells[x][y]->setMark(mark);
//         Cells[x][y]->setIsEmpty(false);
//     }

//     bool isAnyCellLeft()
//     {
//         for (int i = 0; i < sz; i++)
//         {
//             for (int j = 0; j < sz; j++)
//             {
//                 if (Cells[i][j]->getIsEmpty() == true)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

//     bool checkIfWin(string choosedMark, int x, int y)
//     {
//         bool a = true, b = true, c = true, d = true;
//         for (int i = 0; i < sz; i++)
//         {
//             if (Cells[i][y]->getIsEmpty() == true || Cells[i][y]->getMark()->getSign() != choosedMark)
//             {
//                 a = false;
//             }
//         }
//         for (int j = 0; j < sz; j++)
//         {
//             if (Cells[x][j]->getIsEmpty() == true || Cells[x][j]->getMark()->getSign() != choosedMark)
//             {
//                 b = false;
//             }
//         }
//         for (int i = 0; i < sz; i++)
//         {
//             if (Cells[i][i]->getIsEmpty() == true || Cells[i][i]->getMark()->getSign() != choosedMark)
//             {
//                 c = false;
//             }
//         }
//         for (int i = 0; i < sz; i++)
//         {
//             if (Cells[i][sz - i - 1]->getIsEmpty() == true || Cells[i][sz - i - 1]->getMark()->getSign() != choosedMark)
//             {
//                 d = false;
//             }
//         }
//         return a | b | c | d;
//     }

//     void printBoard()
//     {
//         for (int i = 0; i < sz; i++)
//         {
//             for (int j = 0; j < sz; j++)
//             {
//                 if (Cells[i][j]->getIsEmpty() == true)
//                 {
//                     cout << "|  |";
//                 }
//                 else
//                 {
//                     cout << "|" << Cells[i][j]->getMark()->getSign() << " |";
//                 }
//             }
//             cout << endl;
//         }
//     }
// };

// class Game
// {
//     vector<Player *> players;
//     int turn = 0;
//     Board *board;
//     int sz = 3;
//     string winner = "";

// public:
//     Game(string n1, string n2, string choose1, string choose2)
//     {
//         board = new Board(sz);
//         Player *p1 = new Player(choose1, n1);
//         Player *p2 = new Player(choose2, n2);

//         players.push_back(p1);
//         players.push_back(p2);
//     }

//     void startGame()
//     {
//         while (winner == "")
//         {
//             if (board->isAnyCellLeft() == false)
//             {
//                 winner = "Draw";
//                 cout << "draw!!\n";
//                 break;
//             }

//             Player *p = players[turn];

//             cout << "Turn of " << p->getName() << "\n";
//             cout << "Choose the cell indexes row and collumn\n";

//             int x, y;
//             cin >> x >> y;

//             Cell *cell = board->getCell(x, y);

//             if (cell->getIsEmpty() == false)
//             {
//                 cout << "Choose another cell, its alread filled\n";
//                 continue;
//             }
//             if (p->getChoosedMark() == "X")
//             {
//                 board->markCell(x, y, new MarkX());
//             }
//             else
//             {
//                 board->markCell(x, y, new MarkO());
//             }

//             board->printBoard();
//             if (board->checkIfWin(p->getChoosedMark(), x, y))
//             {
//                 winner = p->getName();
//                 break;
//             }
//             turn = 1 - turn;
//         }
//         cout << "Winner is " << winner;
//     }
// };
