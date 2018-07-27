//
// Created by karl on 18-7-27.
//

#ifndef NEOTEACHERSERVER_CLIENT_H
#define NEOTEACHERSERVER_CLIENT_H


#include <netinet/in.h>

class Client {
private:
    int connectSocketFileDescriptor;
    sockaddr_in clientAddress;

public:
    Client(int connfd, sockaddr_in clientAddress);

    int getConnectSocketFileDescriptor();

    sockaddr_in getClientAddress();
};


#endif //NEOTEACHERSERVER_CLIENT_H
