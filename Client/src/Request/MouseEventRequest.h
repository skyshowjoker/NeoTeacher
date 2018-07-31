//
// Created by karl on 18-7-30.
//

#ifndef HACKMOUSE_MOUSEEVENTREQUEST_H
#define HACKMOUSE_MOUSEEVENTREQUEST_H


#include <linux/input.h>
#include "Request.h"

class MouseEventRequest : public Request {
public:
    explicit MouseEventRequest(input_event *event);

    void packData(input_event *event);

    void depackData(input_event *eventBuffer);

#ifdef __INDEBUG__
    std::string getRequestBody() {
        return requestBody;
    }
#endif
};


#endif //HACKMOUSE_MOUSEEVENTREQUEST_H
