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

char toChar(uint8_t u) {
    return (char) ((short) u - 128);
}

TransmissionControlProtocolSerial::TransmissionControlProtocolSerial(Setting *setting) {
    auto address = setting->getAddress();
    auto port = setting->getPort();

    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor <= 0) {
        throw runtime_error(string("failed creating local file descriptor"));
    }

    sockaddr_in remoteAddress;
    bzero(&remoteAddress, sizeof(remoteAddress));
    remoteAddress.sin_port = port;
    remoteAddress.sin_family = AF_INET;

    auto err = inet_pton(AF_INET, address.c_str(), &remoteAddress.sin_addr);
    if (err < 0) {
        throw runtime_error(string("failed converting p to n"));
    }

    err = connect(socketFileDescriptor, (sockaddr *) &remoteAddress, sizeof(socketFileDescriptor));
    if (err < 0) {
        throw runtime_error(string("failed connect to server"));
    }

    fprintf(stderr, "[STAT] CONNECTED TO '%s'..\n", address.c_str());
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
