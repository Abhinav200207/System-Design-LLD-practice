#ifndef GROUP_H
#define GROUP_H

#include <bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Message.hpp"

class User;

class Group
{
private:
    string groupId;
    string groupName;
    vector<User *> members;

public:
    Group(const string &groupId, const string &groupName);

    string getGroupId() const;
    string getGroupName() const;

    void addMember(User *user);
    void removeMember(User *user);
    vector<User *> getMembers() const;

    void broadcastMessage(Message *message);

    friend ostream &operator<<(ostream &os, const Group &group);
};

#endif // GROUP_H
