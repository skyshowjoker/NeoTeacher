//
// Created by karl on 18-7-27.
//

#include <stdexcept>
#include "ClientList.h"

void ClientList::addClient(Client* client) {
    data.push_back(client);
}

void ClientList::deleteClient(Client *client) {
    for (auto it = data.begin(); it < data.end(); ++it) {
        if (*it == client) {
            free(client);
            data.erase(it);
        }
    }
}

void ClientList::newClient(int connectFileDescriptor, sockaddr_in clientAddress) {
    auto client = new Client(connectFileDescriptor, clientAddress);
    addClient(client);
}
