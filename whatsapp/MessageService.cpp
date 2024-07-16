#include <bits/stdc++.h>
using namespace std;

#include "MessageService.hpp"

MessageService *MessageService::instance = NULL;

void MessageService::addUser(User *user)
{
    reciverIdtoReciver[user->getUserId()] = user;
}

void MessageService::sendMessage(Message *message, string senderId, string reciverId)
{
    reciverIdtoReciver[reciverId]->notifyMessage(message);
}

MessageService *MessageService::getInstance()
{
    if (instance == NULL)
    {
        instance = new MessageService();
    }
    return instance;
}