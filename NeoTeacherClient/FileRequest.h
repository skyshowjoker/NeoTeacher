//
// Created by karl on 18-7-29.
//

#ifndef NEOTEACHERCLIENT_FILEREQUEST_H
#define NEOTEACHERCLIENT_FILEREQUEST_H


#include "Request.h"

class FileRequest : Request {
private:
    static const uint16_t singlePackageSize = 0xFFFF;
public:
    explicit FileRequest(std::string data);

    explicit FileRequest(char *data);

    void writeToLocal(int fileDescriptor);
};


#endif //NEOTEACHERCLIENT_FILEREQUEST_H
