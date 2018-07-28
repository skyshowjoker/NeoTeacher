//
// Created by karl on 18-7-28.
//

#include <stdexcept>
#include <strings.h>
#include "ClientManager.h"

void ClientManager::newClient(int connectFileDescriptor, sockaddr_in clientAddr, pthread_t pid) {
    clientList.push_back(new Client(connectFileDescriptor, clientAddr, pid));
}

typedef struct {
    int connfd;

    // DEBUG
    pthread_t pid;
} connectionListenLoopArg;

void * connectionListenLoop(void * args) {
    auto connfd = ((connectionListenLoopArg*)args)->connfd;
    auto pid = ((connectionListenLoopArg*)args)->pid;
    fprintf (stderr, "[STAT] start listening msg in thread [%d]..\n", pid);
    // debug
    char buff[1024] = {0};
    while (recv(connfd, buff, 1024, 0) != -1) {
        fprintf (stderr, "DEBUG>>%s", buff);
        bzero(buff, 1024);
    }
    fprintf (stderr, "\n[STAT] connect exited..\n");
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
        fprintf (stderr, "[STAT] connected with client '%d'..\n", clientAddr.sin_addr.s_addr);
        send(connfd, "Welcome and fuck you.\r\n", 24, 0);
        pthread_t newClientListenLoopPid;
        connectionListenLoopArg arg;
        arg.connfd = connfd;
        pthread_create(&newClientListenLoopPid, nullptr, &connectionListenLoop, &arg);
        manager->newClient(connfd, clientAddr, newClientListenLoopPid);
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
