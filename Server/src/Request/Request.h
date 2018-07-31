//
// Created by karl on 18-7-27.
//

#ifndef NEOTEACHERCLIENT_REQUEST_H
#define NEOTEACHERCLIENT_REQUEST_H

#include <cstdint>
#include <string>

#define __SCU8__ static const uint8_t

char toChar(uint8_t u);

uint8_t toUnsignedChar(char c);

class Request {
protected:
    uint8_t requestType;
    uint32_t requestSize;
    uint16_t checkSum;
    std::string requestBody;

    void calculateCheckSum();

    void calculateSize();



public:
    Request();

    Request(uint8_t type, std::string body);

    void setRequestType(uint8_t type);

    void setRequestBody(std::string body);

    uint32_t getRequestSize() {
        return requestSize;
    }

    uint8_t getRequestType() {
        return requestType;
    }

    std::string getRequestBody() {
        return requestBody;
    }

    bool check(uint16_t anotherCheckSum);

    void serialize(char **serializedRequest);

    void disserialize(char *serializedRequest);

    __SCU8__ RTYPE_OK = 0;
    __SCU8__ RTYPE_ERR = 1;
    __SCU8__ RTYPE_LOGIN = 2;
    __SCU8__ RTYPE_HANDUP = 3;
    __SCU8__ RTYPE_HANDIN = 4;
    __SCU8__ RTYPE_FILE = 5;
    __SCU8__ RTYPE_QUIT = 6;

    __SCU8__ RTYPE_MOUSE = 10;
    // ...
};

#endif //NEOTEACHERCLIENT_REQUEST_H
