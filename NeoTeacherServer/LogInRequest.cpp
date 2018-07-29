//
// Created by karl on 18-7-29.
//

#include "LogInRequest.h"

LogInRequest::LogInRequest(std::string username, std::string password) {
    setRequestBody(username + "." + password);
}