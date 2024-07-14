#ifndef Theater_HPP
#define Theater_HPP

#include <bits/stdc++.h>
using namespace std;

#include "Movie.hpp"
#include "Hall.hpp"

class Theater
{
    string name;
    vector<Movie *> movies;
    vector<Hall *> halls;

};

#endif