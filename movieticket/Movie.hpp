#ifndef Movie_HPP
#define Movie_HPP

#include <bits/stdc++.h>
using namespace std;

class Movie
{
    string name;
    string movieId;
    int stTime;
    int endTime;

    Movie(string name, string id, int startTime, int endTime) : name(name), movieId(id), stTime(startTime), endTime(endTime) {}

    string getName() const { return name; }
    string getId() const { return movieId; }
    int getStTime() const { return stTime; }
    int getEndTime() const { return endTime; }
};

#endif