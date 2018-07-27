//
// Created by karl on 18-7-27.
//

#ifndef NEOTEACHERCLIENT_USERLIST_H
#define NEOTEACHERCLIENT_USERLIST_H

#include "User.h"
#include <vector>

class ClientList {
private:
    std::vector<Client *> data;
public:
    ClientList() = default;

    void addClient(Client *client);

    void deleteClient(Client *client);

    void newClient(int connectFileDescriptor, sockaddr_in clientAddress);
};


#endif //NEOTEACHERCLIENT_USERLIST_H
