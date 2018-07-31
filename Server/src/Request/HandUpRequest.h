//
// Created by karl on 18-7-31.
//

#ifndef CLIENT_HANDUPREQUEST_H
#define CLIENT_HANDUPREQUEST_H


#include "Request.h"

class HandUpRequest : public Request {
public:
    HandUpRequest();
    void packData();
    void depackData();
};


#endif //CLIENT_HANDUPREQUEST_H
