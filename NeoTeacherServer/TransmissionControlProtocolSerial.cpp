//
// Created by karl on 18-7-27.
//

#include <sys/socket.h>
#include <stdexcept>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include "TransmissionControlProtocolSerial.h"

using namespace std;

TransmissionControlProtocolSerial::TransmissionControlProtocolSerial(Setting *setting) {
    auto port = setting->getPort();
    auto maxUser = setting->getMaxUser();

    int listenFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (listenFileDescriptor < 0) {
        throw runtime_error(string("failed creating listening socket"));
    }

    sockaddr_in serverAddress;
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);

    if (bind(listenFileDescriptor, (sockaddr*) &serverAddress, sizeof(serverAddress)) < 0) {
        throw runtime_error(string("failed binding with socket"));
    }

    if (listen(listenFileDescriptor, maxUser) < 0) {
        throw runtime_error(string("failed starting listening"));
    }

    fprintf (stderr, "[STAT] TCP SERIAL SUCCESSFULLY INITIALIZED..\n");
}

void TransmissionControlProtocolSerial::recieveRequest(Request *buffer) {
    char sizeBuffer[4];
    recv(socketFileDescriptor, sizeBuffer, 4, MSG_WAITALL);
    unsigned int size = 0;
    for (int i = 0; i < 4; i++) {
        size <<= 8;
        size += sizeBuffer[i];
    }
    char serializedRequest[size + 7];
    for (int i = 0; i < 4; i++) {
        serializedRequest[i] = sizeBuffer[i];
    }
    recv(socketFileDescriptor, serializedRequest + 4, size + 3, MSG_WAITALL);
    buffer = new Request();
    try {
        buffer->disserialize(serializedRequest);
    } catch (runtime_error &error) {
        throw error;
    }
}

void TransmissionControlProtocolSerial::sendRequest(Request *request) {
    char *serializedRequest = nullptr;
    request->serialize(serializedRequest);
    send(socketFileDescriptor, serializedRequest, (size_t) request->getRequestSize() + 7, 0);
}
