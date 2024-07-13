#ifndef MARK_HPP
#define MARK_HPP

#include <bits/stdc++.h>
using namespace std;

class Mark
{
    string sign;

public:
    Mark(string sign)
    {
        this->sign = sign;
    }
    string getSign()
    {
        return sign;
    }
};

class MarkX : public Mark
{
public:
    MarkX() : Mark("X") {}
};

class MarkO : public Mark
{
public:
    MarkO() : Mark("O") {}
};


#endif // MARK_HPP