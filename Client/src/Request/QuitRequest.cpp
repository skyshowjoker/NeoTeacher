//
// Created by karl on 18-7-31.
//

#include "QuitRequest.h"

QuitRequest::QuitRequest() {
    setRequestType(RTYPE_QUIT);
    calculateCheckSum();
    calculateSize();
}


void QuitRequest::packData() {}

void QuitRequest::depackData() {}