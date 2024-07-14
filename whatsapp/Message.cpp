#include <bits/stdc++.h>
using namespace std;

#include "Message.hpp"

Message::Message(const string &senderId, const string &receiverId, const string &content)
    : senderId(senderId), receiverId(receiverId), content(content), isGroupMessage(false), timestamp("")
{
    messageId = generateUUID();
}

Message::Message(const string &senderId, const string &groupId, const string &content, bool isGroupMessage)
    : senderId(senderId), receiverId(groupId), content(content), isGroupMessage(isGroupMessage), timestamp("")
{
    messageId = generateUUID();
}

string Message::generateUUID()
{
    vector<int> v;
    for (int i = 0; i <= 9; i++)
        v.push_back(i);
    random_shuffle(v.begin(), v.end());
    string s = "";
    for (auto x : v)
        s += to_string(x);
    return s;
}

string Message::getMessageId() const
{
    return messageId;
}

string Message::getSenderId() const
{
    return senderId;
}

string Message::getReceiverId() const
{
    return receiverId;
}

string Message::getContent() const
{
    return content;
}

bool Message::getIsGroupMessage() const
{
    return isGroupMessage;
}

string Message::getTimestamp() const
{
    return timestamp;
}

ostream &operator<<(ostream &os, const Message &message)
{
    os << "Message{" << "messageId='" << message.messageId << "', senderId='" << message.senderId << "', receiverId='" << message.receiverId << "', content='" << message.content << "', isGroupMessage=" << message.isGroupMessage << ", timestamp=" << message.timestamp << "}";
    return os;
}
