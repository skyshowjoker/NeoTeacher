//
// Created by karl on 18-7-27.
//

#include "Client.h"

Client::Client(int connfd, sockaddr_in clientAddress, pthread_t pid) {
    connectSocketFileDescriptor = connfd;
    this->clientAddress = clientAddress;
    this->pid = pid;
}

int Client::getConnectSocketFileDescriptor() {
    return connectSocketFileDescriptor;
}

sockaddr_in Client::getClientAddress() {
    return clientAddress;
}
