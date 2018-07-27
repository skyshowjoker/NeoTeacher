//
// Created by karl on 18-7-27.
//

#include <stdexcept>
#include "UserList.h"

void UserList::addUser(User *user) {
    data.push_back(user);
}

void UserList::deleteUser(User *user) {
    for (auto it = data.begin(); it < data.end(); ++it) {
        if (*it == user) {
            data.erase(it);
            return;
        }
    }
    throw std::runtime_error(std::string("selected user not found"));
}