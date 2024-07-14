#include "MessageStatus.hpp"

#include <bits/stdc++.h>
using namespace std;

const string MessageStatus::SENT = "SENT";
const string MessageStatus::RECEIVED = "RECEIVED";
const string MessageStatus::SEEN = "SEEN";

unordered_map<string, string> MessageStatus::messageStatusMap;

void MessageStatus::updateMessageStatus(const string &messageId, const string &status)
{
    messageStatusMap[messageId] = status;
}

string MessageStatus::getMessageStatus(const string &messageId)
{
    auto it = messageStatusMap.find(messageId);
    if (it != messageStatusMap.end())
    {
        return it->second;
    }
    return "UNKNOWN";
}

