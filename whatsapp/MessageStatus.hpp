#ifndef MESSAGESTATUS_H
#define MESSAGESTATUS_H

#include <bits/stdc++.h>
using namespace std;

class MessageStatus
{
public:
    static const string SENT;
    static const string RECEIVED;
    static const string SEEN;

private:
    static unordered_map<string, string> messageStatusMap;

public:
    static void updateMessageStatus(const string &messageId, const string &status);
    static string getMessageStatus(const string &messageId);

    friend ostream &operator<<(ostream &os, const MessageStatus &status);
};

#endif // MESSAGESTATUS_H
