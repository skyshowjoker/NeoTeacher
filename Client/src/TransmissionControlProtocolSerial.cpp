//
// Created by karl on 18-7-27.
//

#include <sys/socket.h>
#include <stdexcept>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include <zconf.h>
#include "TransmissionControlProtocolSerial.h"

using namespace std;

//char toChar(uint8_t u) {
//    return (char) ((short) u - 128);
//}

TransmissionControlProtocolSerial::TransmissionControlProtocolSerial(Setting *setting) {
    auto address = setting->getAddress();
    auto port = setting->getPort();
    fprintf (stderr, "[STAT] CONNECTING TO %s:%u..\n", address.c_str(), port);

    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor <= 0) {
        throw runtime_error(string("failed creating local file descriptor"));
    }

    sockaddr_in remoteAddress;
    bzero(&remoteAddress, sizeof(remoteAddress));
    remoteAddress.sin_port = htons(port);
    remoteAddress.sin_family = AF_INET;
    auto err = inet_pton(AF_INET, address.c_str(), &remoteAddress.sin_addr);
    if (err < 0) {
        throw runtime_error(string("failed converting p to n"));
    }

    err = connect(socketFileDescriptor, (sockaddr *) &remoteAddress, sizeof(remoteAddress));
    if (err < 0) {
        if (errno == 111) {
            fprintf(stderr, "server '%s' refuse to connect at port %u\n", address.c_str(), port);
        }
        throw runtime_error(string("failed connect to server, and the errno: ") + to_string(errno));
    }

    fprintf(stderr, "[STAT] CONNECTED TO '%s'..\n", address.c_str());
}

void TransmissionControlProtocolSerial::receiveRequest(Request **pRequest) {
    char sizeBuffer[4] = {0};
    recv(socketFileDescriptor, sizeBuffer, 4, 0);
    uint32_t size = 0;
    for (auto c : sizeBuffer) {
        size <<= 8;
        size |= (uint32_t) toUnsignedChar(c);
    }
    char serializedRequest[size + 7];
    for (int i = 0; i < 4; i++) {
        serializedRequest[i] = sizeBuffer[i];
    }
    recv(socketFileDescriptor, serializedRequest + 4, size + 3, 0);
    *pRequest = new Request();
    try {
        (*pRequest)->disserialize(serializedRequest);
    } catch (runtime_error &error) {
        throw error;
    }
}

void TransmissionControlProtocolSerial::sendRequest(Request *request) {
    char *serializedRequest = nullptr;
    request->serialize(&serializedRequest);
    size_t size = request->getRequestSize() + 7;
    fprintf (stderr, "#DEBUG# fd = %d\n", socketFileDescriptor);
    send(socketFileDescriptor, serializedRequest, size, 0);
    delete serializedRequest;
}

TransmissionControlProtocolSerial::~TransmissionControlProtocolSerial() {
    close(socketFileDescriptor);
}
