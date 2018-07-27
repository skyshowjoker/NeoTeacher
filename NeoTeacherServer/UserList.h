//
// Created by karl on 18-7-27.
//

#ifndef NEOTEACHERCLIENT_USERLIST_H
#define NEOTEACHERCLIENT_USERLIST_H

#include "User.h"
#include <vector>

class UserList {
private:
    std::vector<User*> data;
public:
    UserList() = default;
    void addUser(User* user);
    void deleteUser(User* user);
};


#endif //NEOTEACHERCLIENT_USERLIST_H
