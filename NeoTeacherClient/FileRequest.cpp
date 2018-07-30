//
// Created by karl on 18-7-29.
//

#include <zconf.h>
#include "FileRequest.h"

FileRequest::FileRequest(std::string path) {
    this->requestBody = std::move(path);
}

FileRequest::FileRequest(char *data) {
    this->requestBody = std::string(data, singlePackageSize);
}

void FileRequest::writeToLocal(int fileDescriptor) {
    write(fileDescriptor, requestBody.c_str(), singlePackageSize);
}
