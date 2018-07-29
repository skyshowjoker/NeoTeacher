//
// Created by karl on 18-7-27.
//

#ifndef NEOTEACHERCLIENT_REQUEST_H
#define NEOTEACHERCLIENT_REQUEST_H


#include <cstdint>
#include <string>

#ifndef toChar
#define toChar(u) ((char) ((short) (u) - 128))
#endif

#ifndef toUnsignedChar
#define toUnsignedChar(c) ((uint8_t) ((c) + 128))
#endif

class Request {
private:
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

    void setRequestBody(std::string &body);

    uint8_t getRequestType();

    uint32_t getRequestSize();

    std::string getRequestBody();

    bool check(uint16_t anotherCheckSum);

    void serialize(char **serializedRequest);

    void disserialize(char *serializedRequest);

    static const uint8_t RTYPE_OK = 0;
    static const uint8_t RTYPE_ERR = 1;
    static const uint8_t RTYPE_LOGIN = 2;
    // ...
};

#endif //NEOTEACHERCLIENT_REQUEST_H
