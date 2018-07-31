//
// Created by karl on 18-7-31.
//

#include <openssl/sha.h>
#include "LoginRequest.h"

LoginRequest::LoginRequest(std::string username, std::vector<uint8_t> passwordSummary) {
    packData(std::move(username), std::move(passwordSummary));
    setRequestType(RTYPE_LOGIN);
    calculateCheckSum();
    calculateSize();
}

void LoginRequest::packData(std::string username, std::vector<uint8_t> passwordSummary) {
    setRequestBody(username + std::string("."));
    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++) {
        requestBody.push_back(toChar(passwordSummary[i]));
    }
}

void LoginRequest::depackData(std::string *usernameBuffer, std::vector<uint8_t> *passwordSummary) {
    auto tokenPos = requestBody.begin();
    for (; tokenPos < requestBody.end(); ++tokenPos) {
        if (*tokenPos == '.') {
            break;
        }
    }
    usernameBuffer->clear();
    usernameBuffer->assign(requestBody.begin(), tokenPos);
    auto passwordSummaryStr = std::string(tokenPos + 1, requestBody.end());
    for (auto c : passwordSummaryStr) {
        passwordSummary->push_back(toUnsignedChar(c));
    }
}
