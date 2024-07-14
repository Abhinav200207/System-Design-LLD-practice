#include "User.hpp"

#include <bits/stdc++.h>
using namespace std;

User::User(const string &userId, const string &username)
    : userId(userId), username(username), lastOnline("") {}

string User::getUserId() const
{
    return userId;
}

string User::getUsername() const
{
    return username;
}

string User::getLastOnline() const
{
    return lastOnline;
}

void User::updateLastOnline(string time)
{
    this->lastOnline = time;
}

void User::addContact(User *user)
{
    contacts.push_back(user);
}

void User::addGroup(Group *group)
{
    groups.push_back(group);
}

string User::sendMessage(User *receiver, const string &content)
{
    Message *message = new Message(userId, receiver->getUserId(), content);
    MessageStatus::updateMessageStatus(message->getMessageId(), MessageStatus::SENT);
    cout << "Message Status: " << MessageStatus::getMessageStatus(message->getMessageId()) << "\n";
    receiver->receiveMessage(message);
    return message->getMessageId();
}

void User::sendGroupMessage(Group *group, const string &content)
{
    Message *message = new Message(userId, group->getGroupId(), content, true);
    group->broadcastMessage(message);
}

void User::receiveMessage(Message *message)
{
    cout << "Message notification for " << username << endl;
    cout << "Message received from " << message->getSenderId() << endl;
    MessageStatus::updateMessageStatus(message->getMessageId(), MessageStatus::RECEIVED);
    messagesV.push_back(message);
}

void User::readMessage()
{
    for (auto x : messagesV)
    {
        cout << "message is: " << x->getContent() << endl;
        MessageStatus::updateMessageStatus(x->getMessageId(), MessageStatus::SEEN);
    }
}

ostream &operator<<(ostream &os, const User &user)
{
    os << "User{" << "userId='" << user.userId << "', username='" << user.username << "', lastOnline=" << user.lastOnline << "}";
    return os;
}
