#ifndef Zone_HPP
#define Zone_HPP

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Theater.hpp"

class Zone
{
    vector<Theater *> theaters;
    vector<User *> users;

public:
    Zone() {}

    void addTheater(Theater *theater)
    {
        theaters.push_back(theater);
    }
    void addUser(User *user)
    {
        users.push_back(user);
    }
};

#endif