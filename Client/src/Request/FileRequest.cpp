//
// Created by karl on 18-7-31.
//

#include "FileRequest.h"

FileRequest::FileRequest(std::string data) {
    packData(std::move(data));
    setRequestType(RTYPE_FILE);
    calculateCheckSum();
    calculateSize();
}

void FileRequest::packData(std::string data) {
    setRequestBody(std::move(data));
}

void FileRequest::depackData(std::string *dataBuffer) {
    dataBuffer->clear();
    dataBuffer->assign(requestBody);
}
