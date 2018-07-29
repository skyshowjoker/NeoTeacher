//
// Created by karl on 18-7-28.
//

#include <stdexcept>
#include <strings.h>
#include "ClientManager.h"

void requestHandler(Request * request);

void ClientManager::newClient(int connectFileDescriptor, sockaddr_in clientAddr, pthread_t pid) {
    clientList.push_back(new Client(connectFileDescriptor, clientAddr, pid));
}

typedef struct {
    TransmissionControlProtocolSerial * TCPSerial;
    int connfd;
    // DEBUG
    pthread_t pid;
} connectionListenLoopArg;

void *connectionListenLoop(void *args) {
    auto connfd = ((connectionListenLoopArg *) args)->connfd;
    auto TCPSerial = ((connectionListenLoopArg *) args)->TCPSerial;
    auto pid = ((connectionListenLoopArg *) args)->pid;
    fprintf(stderr, "[STAT] start listening msg in thread [%u]..\n", pid);
    while(true) {
        auto request = new Request();
        TCPSerial->receiveRequest(connfd, &request);
        requestHandler(request);
    }
    return nullptr;
}

typedef struct {
    TransmissionControlProtocolSerial *TCPSerial;
    ClientManager *clientManager;
} handleNewConnectionLoopArg;

void *handleNewConnectionLoop(void *args) {
    auto listenfd = ((handleNewConnectionLoopArg *) args)->TCPSerial->getListenFileDescriptor();
    auto manager = ((handleNewConnectionLoopArg *) args)->clientManager;
    while (true) {
        sockaddr_in clientAddr;
        socklen_t clientSize = sizeof(clientAddr);
        int connfd = accept(listenfd, (sockaddr *) &clientAddr, &clientSize);
        if (connfd < 0) {
            throw std::runtime_error(std::string("failed accepting connection"));
        }
        fprintf(stderr, "[STAT] connected with client '%d'..\n", clientAddr.sin_addr.s_addr);
        send(connfd, "Welcome and fuck you.\r\n", 24, 0);
        connectionListenLoopArg arg;
        arg.connfd = connfd;
        pthread_create(&arg.pid, nullptr, &connectionListenLoop, &arg);
        manager->newClient(connfd, clientAddr, arg.pid);
    }
}

void ClientManager::handleNewConnection(TransmissionControlProtocolSerial *TCPSerail) {
    int listenfd = TCPSerail->getListenFileDescriptor();
    handleNewConnectionLoopArg arg;
    arg.clientManager = this;
    arg.TCPSerial = TCPSerail;
    pthread_create(&newConnectionHandlerPid, nullptr, &handleNewConnectionLoop, &arg);
    pthread_join(newConnectionHandlerPid, nullptr);
}

extern void requestHandler(Request * request) {
    switch (request->getRequestType()) {
        case 1:
        case Request::RTYPE_OK:
            char * serialized;
            request->serialize(&serialized);
            printf ("%s\n", serialized);
            break;
        default:
            throw std::runtime_error(std::string("invalid request type"));
    }
}