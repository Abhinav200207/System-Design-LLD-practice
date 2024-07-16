#ifndef GROUPSERVICE_H
#define GROUPSERVICE_H

#include "User.hpp"
#include "Message.hpp"
#include "Group.hpp"

class User;
class Group;

class GroupService
{
    unordered_map<string, Group *> groupIdtoGroup;
    static GroupService *groupService;
    GroupService() {}

public:
    static GroupService *getInstance();
    void addGroup(Group *group);
    void broadcastMessage(string groupId, Message *message);
};

#endif
