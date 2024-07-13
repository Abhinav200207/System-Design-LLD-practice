#include <bits/stdc++.h>
using namespace std;

#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"

class Game
{
    Board *board;
    vector<Player *> players;
    string winner = "";
    int idx = 0;

public:
    Game()
    {
        initilizeGamePlayersandBoard();
    }
    void initilizeGamePlayersandBoard()
    {
        board = new Board(8);
        Player *p1 = new Player("Abhinav", "BLACK");
        Player *p2 = new Player("Maurya", "WHITE");
        players.push_back(p1);
        players.push_back(p2);
    }

    void startGame()
    {
        while (winner == "")
        {
            Player *p = players[idx];

            cout << "player: " << p->getName() << "your move\n";
            cout << "choose the piece you want to move from where to where\n";

            int x, y;
            cin >> x >> y;
            int nx, ny;
            cin >> nx >> ny;

            Cell *curr = board->getCell(x, y);
            Cell *nxt = board->getCell(nx, ny);

            if (curr->getIsEmpty() == true)
            {
                cout << "no piece is present\n";
                continue;
            }

            if (idx == 0)
            {
                if (curr->getPieces()->getColor() == "BLACK")
                {
                    if (nxt->getIsEmpty() == true)
                    {
                        Piece *piece = curr->getPieces();
                        if (piece->movePiece({x, y}, {nx, ny}))
                        {
                            curr->setIsEmpty(true);
                            curr->setPieces(NULL);
                            nxt->setPieces(piece);
                            nxt->setIsEmpty(false);
                        }
                        else
                        {
                            cout << "Invalid move\n";
                        }
                    }
                    else
                    {
                        if (nxt->getPieces()->getColor() == "BLACK")
                        {
                            cout << "You cannot kill yourself\n";
                        }
                        else
                        {
                            Piece *piece = curr->getPieces();
                            Piece *piecenxt = nxt->getPieces();
                            if (piece->movePiece({x, y}, {nx, ny}))
                            {
                                curr->setIsEmpty(true);
                                curr->setPieces(NULL);
                                delete piecenxt;
                                nxt->setPieces(piece);
                                nxt->setIsEmpty(false);
                            }
                            else
                            {
                                cout << "Invalid move\n";
                            }
                        }
                    }
                }
                else
                {
                    cout << "this is not you piece you should choose BLACK";
                }
            }
            if (idx == 1)
            {
                if (curr->getPieces()->getColor() == "WHITE")
                {
                    if (nxt->getIsEmpty() == true)
                    {
                        Piece *piece = curr->getPieces();
                        if (piece->movePiece({x, y}, {nx, ny}))
                        {
                            curr->setIsEmpty(true);
                            curr->setPieces(NULL);
                            nxt->setPieces(piece);
                            nxt->setIsEmpty(false);
                        }
                        else
                        {
                            cout << "Invalid move\n";
                        }
                    }
                    else
                    {
                        if (nxt->getPieces()->getColor() == "WHITE")
                        {
                            cout << "You cannot kill yourself\n";
                        }
                        else
                        {
                            Piece *piece = curr->getPieces();
                            Piece *piecenxt = nxt->getPieces();
                            if (piece->movePiece({x, y}, {nx, ny}))
                            {
                                curr->setIsEmpty(true);
                                curr->setPieces(NULL);
                                delete piecenxt;
                                nxt->setPieces(piece);
                                nxt->setIsEmpty(false);
                            }
                            else
                            {
                                cout << "Invalid move\n";
                            }
                        }
                    }
                }
                else
                {
                    cout << "this is not you piece you should choose WHITE";
                }
            }

            winner = checkIfAnyoneWon();
            idx = 1 - idx;
            board->displayBoard();
        }
    }

    string checkIfAnyoneWon()
    {
        // to do
        return "";
    }
};