//
// Created by karl on 18-7-27.
//

#include "User.h"

User::User(uint32_t id, sockaddr_in address, int connfd) {
    userId = id;
    userAddress = address;
    connectFileDescriptor = connfd;
}