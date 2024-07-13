#include <bits/stdc++.h>
using namespace std;

#include "Player.hpp"
#include "Board.hpp"
#include "Dice.hpp"
#include "Piece.hpp"

class Game
{
    vector<Player *> player;
    int turn = 0;
    int totPlayer;
    Board *board;
    Dice *dice;
    string winner = "";

public:
    Game(vector<string> name, int totPlayer)
    {
        board = new Board(5, 5);
        dice = new Dice();

        this->totPlayer = totPlayer;

        for (int i = 0; i < name.size(); i++)
        {
            Player *p = new Player(name[i]);
            Piece *piece = new Piece({0, 0}, 0);
            p->setPiece(piece);
            board->getCell(0)->addPiece(piece);
            player.push_back(p);
        }
    }
    void startGame()
    {
        while (winner == "")
        {
            Player *p = player[turn];

            cout << "Your turn player: " << p->getName() << "\n";

            int diceNum = dice->getDiceNum();

            cout << "Dice number is: " << diceNum << endl;

            int nextCell = p->getPiece()->getPos() + diceNum;

            if (nextCell >= 100)
            {
                cout << "Turn Wasted, try to get lower\n";
                turn = (turn + 1) % totPlayer;
                continue;
            }


            if (nextCell == 99)
            {
                cout << "You won player: " << p->getName() << "\n";
                winner = p->getName();
                break;
            }

            Cell *prevcell = board->getCell(p->getPiece()->getPos());
            Cell *nxtcell = board->getCell(nextCell);

            if (nxtcell->getIsAnythingPresent() == false)
            {
                prevcell->removePiece(p->getPiece());

                nxtcell->addPiece(p->getPiece());
                p->getPiece()->setPos(nextCell);

                turn = (turn + 1) % totPlayer;
                continue;
            }

            Jumper *jumper = nxtcell->getJumper();

            if (jumper->getIsSnake() == 1)
            {
                cout << "Bitten by snake moved to " << jumper->getEnd() << endl;
            }
            else
            {
                cout << "Got the ladder to " << jumper->getEnd() << endl;
            }

            Cell *nxtnxtcell = board->getCell(jumper->getEnd());
            prevcell->removePiece(p->getPiece());

            nxtnxtcell->addPiece(p->getPiece());

            turn = (turn + 1) % totPlayer;
        }
    }
};