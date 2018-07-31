//
// Created by karl on 18-7-31.
//

#ifndef CLIENT_QUITREQUEST_H
#define CLIENT_QUITREQUEST_H


#include "Request.h"

class QuitRequest : public Request {
public:
    QuitRequest();
    void packData();
    void depackData();
};

#endif //CLIENT_QUITREQUEST_H
