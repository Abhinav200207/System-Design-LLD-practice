#include <bits/stdc++.h>
using namespace std;

#include "GroupService.hpp"

GroupService *GroupService::groupService = NULL;

GroupService *GroupService::getInstance()
{
    if (groupService == NULL)
    {
        groupService = new GroupService();
    }
    return groupService;
}

void GroupService::addGroup(Group *group)
{
    groupIdtoGroup[group->getGroupId()] = group;
}

void GroupService::broadcastMessage(string groupId, Message *message)
{
    Group *group = groupIdtoGroup[groupId];
    group->notifyAll(message);
}