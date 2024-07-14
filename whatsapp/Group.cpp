#include <bits/stdc++.h>
using namespace std;

#include "Group.hpp"


Group::Group(const string &groupId, const string &groupName)
    : groupId(groupId), groupName(groupName) {}

string Group::getGroupId() const
{
    return groupId;
}

string Group::getGroupName() const
{
    return groupName;
}

void Group::addMember(User *user)
{
    members.push_back(user);
}

void Group::removeMember(User *user)
{
    members.erase(remove(members.begin(), members.end(), user), members.end());
}

vector<User *> Group::getMembers() const
{
    return members;
}

void Group::broadcastMessage(Message *message)
{
    for (User *member : members)
    {
        if (member->getUserId() != message->getSenderId())
        {
            member->receiveMessage(message);
        }
    }
}

ostream &operator<<(ostream &os, const Group &group)
{
    os << "Group{" << "groupId='" << group.groupId << "', groupName='" << group.groupName << "', members=[";
    for (const auto &member : group.members)
    {
        os << member->getUsername() << ", ";
    }
    os << "]}";
    return os;
}
