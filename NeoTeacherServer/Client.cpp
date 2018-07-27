//
// Created by karl on 18-7-27.
//

#include "Client.h"

Client::Client(int connfd, sockaddr_in clientAddress) {
    connectSocketFileDescriptor = connfd;
    this->clientAddress = clientAddress;
}

int Client::getConnectSocketFileDescriptor() {
    return connectSocketFileDescriptor;
}

sockaddr_in Client::getClientAddress() {
    return clientAddress;
}
