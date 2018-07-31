//
// Created by karl on 18-7-28.
//

#include <stdexcept>
#include <strings.h>
#include "ClientManager.h"
#include "Request/LoginRequest.h"

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
//        send(connfd, "Welcome and fuck you.\r\n", 24, 0);
        connectionListenLoopArg arg;
        arg.connfd = connfd;
        pthread_create(&arg.pid, nullptr, &connectionListenLoop, &arg);
        manager->newClient(connfd, clientAddr, arg.pid);
    }
}

void ClientManager::handleNewConnection(TransmissionControlProtocolSerial *TCPSerial) {
    int listenfd = TCPSerial->getListenFileDescriptor();
    handleNewConnectionLoopArg arg;
    arg.clientManager = this;
    arg.TCPSerial = TCPSerial;
    pthread_create(&newConnectionHandlerPid, nullptr, &handleNewConnectionLoop, &arg);
    pthread_join(newConnectionHandlerPid, nullptr);
}

extern void requestHandler(Request * request) {
    switch (request->getRequestType()) {
        case Request::RTYPE_LOGIN:
            auto loginRequest = (LoginRequest*) request;
            std::string username;
            std::vector<uint8_t> summary;
            loginRequest->depackData(&username, &summary);
            fprintf (stderr, "got a login request from user: %s");
        default:
            throw std::runtime_error(std::string("invalid request type"));
    }
}