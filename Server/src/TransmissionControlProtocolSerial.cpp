//
// Created by karl on 18-7-27.
//

#include <sys/socket.h>
#include <stdexcept>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include <zconf.h>
#include <fcntl.h>
#include "TransmissionControlProtocolSerial.h"

using namespace std;

TransmissionControlProtocolSerial::TransmissionControlProtocolSerial(Setting *setting) {
    auto port = setting->getPort();
    auto maxUser = setting->getMaxUser();

    listenFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (listenFileDescriptor < 0) {
        throw runtime_error(string("failed creating listening socket"));
    }

    sockaddr_in serverAddress;
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);

    if (bind(listenFileDescriptor, (sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        throw runtime_error(string("failed binding with socket"));
    }

    if (listen(listenFileDescriptor, maxUser) < 0) {
        throw runtime_error(string("failed starting listening"));
    }

    fprintf(stderr, "[STAT] TCP SERIAL SUCCESSFULLY INITIALIZED..\n");
}

void TransmissionControlProtocolSerial::receiveRequest(int remoteFileDescriptor, Request **request) {
    char sizeBuffer[4];
    if (recv(remoteFileDescriptor, sizeBuffer, 4, 0) < 0) {
        throw std::runtime_error(std::string ("lost connection"));
    }
    uint32_t size = 0;
    for (auto c : sizeBuffer) {
        size <<= 8;
        size |= (uint32_t) toUnsignedChar(c);
    }
    auto serializedRequest = (char *) malloc(size + 7);
    for (int i = 0; i < 4; i++) {
        serializedRequest[i] = sizeBuffer[i];
    }
    if (recv(remoteFileDescriptor, serializedRequest + 4, size + 3, 0) < 0) {
        throw std::runtime_error(std::string ("lost connection"));
    }
    *request = new Request();
    try {
        (*request)->disserialize(serializedRequest);
    } catch (runtime_error &error) {
        throw error;
    }
}

void TransmissionControlProtocolSerial::sendRequest(int remoteFileDescriptor, Request *request) {
    char *serializedRequest = nullptr;
    request->serialize(&serializedRequest);
    send(remoteFileDescriptor, serializedRequest, (size_t) request->getRequestSize() + 7, 0);
}

int TransmissionControlProtocolSerial::getListenFileDescriptor() { return listenFileDescriptor; }

TransmissionControlProtocolSerial::~TransmissionControlProtocolSerial() {
    close(listenFileDescriptor);
}