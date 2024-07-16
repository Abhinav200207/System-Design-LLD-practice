#ifndef MESSAGESERVICE_H
#define MESSAGESERVICE_H

#include <bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Message.hpp"

class User;
class Message;

class MessageService
{
    static MessageService *instance;
    unordered_map<string, User *> reciverIdtoReciver;
    MessageService() {}

public:
    void addUser(User *user);
    void sendMessage(Message *message, string senderId, string reciverId);
    static MessageService *getInstance();
};

#endif