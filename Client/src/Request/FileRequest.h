//
// Created by karl on 18-7-31.
//

#ifndef CLIENT_FILEREQUEST_H
#define CLIENT_FILEREQUEST_H


#include <string>
#include "Request.h"

class FileRequest : public Request {
public:
    explicit FileRequest(std::string data);

    void packData(std::string data);

    void depackData(std::string *dataBuffer);
};


#endif //CLIENT_FILEREQUEST_H
