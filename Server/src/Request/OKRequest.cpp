//
// Created by karl on 18-7-31.
//

#include "OKRequest.h"

OKRequest::OKRequest() {
    setRequestType(RTYPE_OK);
    setRequestBody("");
    calculateCheckSum();
    calculateSize();
}

void OKRequest::packData() {}

void OKRequest::depackData() {}