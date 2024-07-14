#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>
using namespace std;

#include "Group.hpp"
#include "Message.hpp"
#include "MessageStatus.hpp"

class Group;

class User
{
private:
    string userId;
    string username;
    string lastOnline;
    vector<User *> contacts;
    vector<Group *> groups;
    vector<Message *> messagesV;

public:
    User(const string &userId, const string &username);

    string getUserId() const;
    string getUsername() const;
    string getLastOnline() const;
    void updateLastOnline(string time);

    void addContact(User *user);
    void addGroup(Group *group);

    string sendMessage(User *receiver, const string &content);
    void sendGroupMessage(Group *group, const string &content);
    void receiveMessage(Message *message);
    void readMessage();

    friend ostream &operator<<(ostream &os, const User &user);
};

#endif // USER_H
