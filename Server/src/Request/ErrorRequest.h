//
// Created by karl on 18-7-31.
//

#ifndef CLIENT_ERRORREQUEST_H
#define CLIENT_ERRORREQUEST_H


#include "Request.h"

class ErrorRequest : public Request {
public:
    explicit ErrorRequest(std::string errorMessage);

    void packData(std::string errorMessage);

    void depackData(std::string *errorMessageBuffer);
};


#endif //CLIENT_ERRORREQUEST_H
