//
// Created by karl on 18-7-29.
//

#ifndef NEOTEACHERSERVER_LOGINREQUEST_H
#define NEOTEACHERSERVER_LOGINREQUEST_H

#include "Request.h"

class LogInRequest : Request {
public:
    LogInRequest(std::string username, std::string password);
};


#endif //NEOTEACHERSERVER_LOGINREQUEST_H
