#ifndef Hall_HPP
#define Hall_HPP

#include <bits/stdc++.h>
using namespace std;

class Hall
{
    set<Seat *> seats;
    string name;
    string hallId;

public:
    Hall(string name, string hallId) : name(name), hallId(hallId) {}
};

#endif