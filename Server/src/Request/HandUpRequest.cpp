//
// Created by karl on 18-7-31.
//

#include "HandUpRequest.h"

HandUpRequest::HandUpRequest() {
    setRequestType(RTYPE_HANDUP);
    calculateSize();
    calculateCheckSum();
}

void HandUpRequest::packData() {}

void HandUpRequest::depackData() {}