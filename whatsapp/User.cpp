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

string User::sendMessage(string receiverid, const string &content)
{
    Message *message = new Message(username, userId, receiverid, content);
    MessageService *messageService = MessageService::getInstance();
    MessageStatus::updateMessageStatus(message->getMessageId(), MessageStatus::SENT);
    cout << "Message Status: 1 " << MessageStatus::getMessageStatus(message->getMessageId()) << "\n";
    messageService->sendMessage(message, userId, receiverid);
    return message->getMessageId();
}

void User::sendGroupMessage(string groupId, const string &content)
{
    Message *message = new Message(username, userId, groupId, content, true);
    GroupService *groupService = GroupService::getInstance();
    groupService->broadcastMessage(groupId, message);
}

void User::notifyMessage(Message *message)
{
    cout << "Message notification for " << username << endl;
    cout << "Message received from " << message->getSenderName() << endl;
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
