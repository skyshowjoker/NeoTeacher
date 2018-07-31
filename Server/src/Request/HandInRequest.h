//
// Created by karl on 18-7-29.
//

#ifndef NEOTEACHERCLIENT_FILEREQUEST_H
#define NEOTEACHERCLIENT_FILEREQUEST_H


#include "Request.h"

class HandInRequest : public Request {
public:
    explicit HandInRequest(std::string path);

    void packData(std::string path);

    void depackData(struct stat *stat64Buffer);
};


#endif //NEOTEACHERCLIENT_FILEREQUEST_H
