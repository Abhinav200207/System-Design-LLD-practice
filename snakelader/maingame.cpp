#include <bits/stdc++.h>
using namespace std;

#include "Game.hpp"
#include "Dice.hpp"

int main()
{
    Game *game = new Game({"Abhinav", "Kumar", "Maurya"},3);
    game->startGame();
    // Dice *dice = new Dice();
    // vector<int> v(7,0);
    // for (int i = 0; i < 1000; i++){
    //     v[dice->getDiceNum()]++;
    // }

    // for (int i = 1; i <= 6; i++){
    //     cout << i << " : " << v[i] << endl;
    // }
    return 0;
}