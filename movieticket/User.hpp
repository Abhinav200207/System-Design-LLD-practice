#ifndef User_HPP
#define User_HPP

#include <bits/stdc++.h>
using namespace std;

#include "Zone.hpp"

class User
{
    vector<Zone *> zones;
    string name;
    string userId;

public:
    User(string name,string userId) : name(name), userId(userId) {}

    string getName() const { return name; }
    string getUserId() const { return userId; }

    void addZone(Zone *zone){
        zones.push_back(zone);
    }
};

#endif