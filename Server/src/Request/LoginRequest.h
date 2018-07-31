//
// Created by karl on 18-7-31.
//

#ifndef CLIENT_LOGINREQUEST_H
#define CLIENT_LOGINREQUEST_H

#include <vector>
#include "Request.h"

class LoginRequest : public Request {
public:
    LoginRequest(std::string username, std::vector<uint8_t> passwordSummary);

    void packData(std::string username, std::vector<uint8_t> passwordSummary);

    void depackData(std::string *usernameBuffer, std::vector<uint8_t> *passwordSummary);
};

#endif //CLIENT_LOGINREQUEST_H
