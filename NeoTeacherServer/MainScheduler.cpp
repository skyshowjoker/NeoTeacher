//
// Created by karl on 18-7-27.
//

#include <stdexcept>
#include <strings.h>
#include "MainScheduler.h"
#include "ClientManager.h"
//
//typedef struct {
//    ClientList *clientList;
//    TransmissionControlProtocolSerial *TCPSerial;
//} ConnectionInformation;
//
//void *handleNewConnection(void *args) {
//    auto clist = ((ConnectionInformation *) args)->clientList;
//    auto listenfd = ((ConnectionInformation *) args)->TCPSerial->getListenFileDescriptor();
//    sockaddr_in clientAddress;
//    socklen_t clientAddressSize = sizeof(clientAddress);
//    bzero(&clientAddress, clientAddressSize);
//    int connfd = accept(listenfd, (sockaddr *) &clientAddress, &clientAddressSize);
//    if (connfd <= 0) {
//        throw std::runtime_error(std::string("failed connecting to client"));
//    }
//    clist->newClient(connfd, clientAddress);
//    return nullptr;
//}

MainScheduler::MainScheduler(std::string filePath) {
    setting = new Setting(std::move(filePath));
    TCPSerial = new TransmissionControlProtocolSerial(setting);
    clientManager = new ClientManager();

//    pthread_t pid;
//    ConnectionInformation info;
//    info.TCPSerial = TCPSerial;
//    info.clientList = clientList;
//    pthread_create(&pid, nullptr, &handleNewConnection, (void *) &info);
//    pthread_join(pid, nullptr);
//    fprintf(stderr, "[STAT] function 'handleNewConnection' is processing..\n");
}

void MainScheduler::start() {
    clientManager->handleNewConnection(TCPSerial);
}