//
// Created by karl on 18-7-31.
//

#ifndef CLIENT_OKREQUEST_H
#define CLIENT_OKREQUEST_H


#include "Request.h"

class OKRequest : public Request {
public:
    OKRequest();

    void packData();

    void depackData();
};


#endif //CLIENT_OKREQUEST_H
