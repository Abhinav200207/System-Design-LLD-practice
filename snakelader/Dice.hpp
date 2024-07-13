#ifndef DICE_HPP
#define DICE_HPP

#include <bits/stdc++.h>
using namespace std;

class Dice
{
public:
    Dice() {}
    int getDiceNum()
    {
        vector<int> random_vector;
        for (unsigned int i = 1; i <= 6; ++i)
            random_vector.push_back(i);

        random_shuffle(random_vector.begin(), random_vector.end());
        return random_vector[0];
    }
};

#endif // DICE_HPP