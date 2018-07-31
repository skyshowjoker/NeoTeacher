//
// Created by karl on 18-7-31.
//

#include <iostream>
#include <openssl/ssl.h>
#include <cstring>
#include <vector>
#include <sys/stat.h>
#include "UserOperations.h"
#include "TransmissionControlProtocolSerial.h"
#include "Request/LoginRequest.h"
#include "Request/ErrorRequest.h"
#include "Request/OKRequest.h"
#include "Request/HandInRequest.h"
#include "Request/HandUpRequest.h"
#include "Request/QuitRequest.h"

void checkUsername(std::string &username) {
    for (auto c : username) {
        if (c < '0' || c > '9') {
            throw std::runtime_error(std::string("username cannot contain non-digit character(s)."));
        }
    }
}

void checkPassword(std::string &password) {
}

void UserOperations::Login(TransmissionControlProtocolSerial *TCPSerial) {
    std::string username;
    std::string password;

    std::cin >> username >> password;

    try {
        checkUsername(username);
        checkPassword(password);
    } catch (std::exception &e) {
        throw e;
    }

    uint8_t summary[SHA512_DIGEST_LENGTH];
    auto message = password.c_str();

    SHA512((unsigned char *) message, strlen(message), (unsigned char *) &summary);

    auto summaryVec = new std::vector<uint8_t>();
    for (auto u : summary) {
        summaryVec->push_back(u);
    }
    auto request = new LoginRequest(username, *summaryVec);

    // debug
    fprintf(stderr, "####### DEBUG #######\n");
    fprintf(stderr, "size:    %u\n", request->getRequestSize());
    fprintf(stderr, "type:    %u\n", request->getRequestType());
    fprintf(stderr, "body:\n");
    for (auto c : request->getRequestBody()) {
        fprintf (stderr, "%d ", c);
    }
    fprintf(stderr, "\n#####################\n");

    TCPSerial->sendRequest(request);
    delete request;
    Request * recvRequest;
    TCPSerial->receiveRequest(&recvRequest);
    if (recvRequest->getRequestType() == Request::RTYPE_OK) {
        return;
    } else if (recvRequest->getRequestType() == Request::RTYPE_ERR) {
        std::string errorMessage;
        ((ErrorRequest*) recvRequest)->depackData(&errorMessage);
        throw std::runtime_error(errorMessage);
    } else {
        throw std::runtime_error("unknown error");
    }
}


void UserOperations::HandIn(TransmissionControlProtocolSerial* TCPSerial) {
    std::string path;
    std::cin >> path;

    HandInRequest * handInRequest;
    try {
        handInRequest = new HandInRequest(path);
    } catch (std::runtime_error &error) {
        throw error;
    }
    TCPSerial->sendRequest(handInRequest);
    delete handInRequest;
    Request * recvRequest;
    TCPSerial->receiveRequest(&recvRequest);
    if (recvRequest->getRequestType() == Request::RTYPE_OK) {
        return;
    } else if (recvRequest->getRequestType() == Request::RTYPE_ERR) {
        std::string errorMessage;
        ((ErrorRequest*) recvRequest)->depackData(&errorMessage);
        throw std::runtime_error(errorMessage);
    } else {
        throw std::runtime_error("unknown error");
    }
}

void UserOperations::HandUp(TransmissionControlProtocolSerial *TCPSerial) {
    auto request = new HandUpRequest();
    TCPSerial->sendRequest(request);
    delete request;
    Request * recvRequest;
    TCPSerial->receiveRequest(&recvRequest);
    if (recvRequest->getRequestType() == Request::RTYPE_OK) {
        return;
    } else if (recvRequest->getRequestType() == Request::RTYPE_ERR) {
        std::string errorMessage;
        ((ErrorRequest*) recvRequest)->depackData(&errorMessage);
        throw std::runtime_error(errorMessage);
    } else {
        throw std::runtime_error("unknown error");
    }
}

void UserOperations::Quit(TransmissionControlProtocolSerial* TCPSerial) {
    auto request = new QuitRequest();
    TCPSerial->sendRequest(request);
    delete request;

    Request * recvRequest;
    TCPSerial->receiveRequest(&recvRequest);
    if (recvRequest->getRequestType() == Request::RTYPE_OK) {
        return;
    } else if (recvRequest->getRequestType() == Request::RTYPE_ERR) {
        std::string errorMessage;
        ((ErrorRequest*) recvRequest)->depackData(&errorMessage);
        throw std::runtime_error(errorMessage);
    } else {
        throw std::runtime_error("unknown error");
    }
}