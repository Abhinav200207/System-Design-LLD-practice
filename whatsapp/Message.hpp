#ifndef MESSAGE_H
#define MESSAGE_H

#include <bits/stdc++.h>
using namespace std;

class Message
{
private:
    string messageId;
    string senderId;
    string receiverId;
    string content;
    string senderName;
    bool isGroupMessage;
    string timestamp;

    string generateUUID();

public:
    Message(const string &senderName, const string &senderId, const string &receiverId, const string &content);
    Message(const string &senderName, const string &senderId, const string &groupId, const string &content, bool isGroupMessage);

    string getMessageId() const;
    string getSenderId() const;
    string getSenderName() const;
    string getReceiverId() const;
    string getContent() const;
    bool getIsGroupMessage() const;
    string getTimestamp() const;

    friend ostream &operator<<(ostream &os, const Message &message);
};

#endif // MESSAGE_H
