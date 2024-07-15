#include <bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Group.hpp"
#include "Message.hpp"
#include "MessageStatus.hpp"

// g++ -o my_program User.cpp Group.cpp Message.cpp MessageStatus.cpp WhatsApp.cpp
// ./my_program

int main()
{
    // Create users
    User *user1 = new User("1", "Alice");
    User *user2 = new User("2", "Bob");
    User *user3 = new User("3", "Charlie");

    // Add contacts
    user1->addContact(user2);
    user2->addContact(user1);
    user2->addContact(user3);

    // Create a group
    Group *group = new Group("1", "Friends");
    group->addMember(user1);
    group->addMember(user2);
    group->addMember(user3);

    // Send a message from user1 to user2
    string messageId = user1->sendMessage(user2, "Hello Bob!");

    // Check message status
    cout << "Message Status: " << MessageStatus::getMessageStatus(messageId) << endl;

    user2->readMessage();

    cout << "Message Status: " << MessageStatus::getMessageStatus(messageId) << endl;

    // Send a group message from user1
    user2->sendGroupMessage(group, "Hello everyone!");

    user3->readMessage();

    // Update and check last online status
    user1->updateLastOnline("12:11 AM");
    cout << user1->getUsername() << " last online: " << user1->getLastOnline() << endl;

    return 0;
}
