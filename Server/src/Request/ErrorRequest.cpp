//
// Created by karl on 18-7-31.
//

#include "ErrorRequest.h"

ErrorRequest::ErrorRequest(std::string errorMessage) {
    packData(std::move(errorMessage));
    setRequestType(RTYPE_ERR);
    calculateSize();
    calculateCheckSum();
}

void ErrorRequest::packData(std::string errorMessage) {
    setRequestBody(std::move(errorMessage));
}

void ErrorRequest::depackData(std::string *errorMessageBuffer) {
    errorMessageBuffer->clear();
    *errorMessageBuffer = requestBody;
}
