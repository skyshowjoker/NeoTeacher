//
// Created by karl on 18-7-30.
//

#include "MouseEventRequest.h"

/*
 * input_event is declared as follow:
        struct input_event {
            struct timeval time;
            __u16 type;
            __u16 code;
            __s32 value;
        };
 */

MouseEventRequest::MouseEventRequest(input_event *event) {
    packData(event);
    setRequestType(RTYPE_MOUSE);
    calculateSize();
    calculateCheckSum();
}

void MouseEventRequest::packData(input_event *event) {
    requestBody.clear();

    // type
    requestBody.push_back(toChar((uint8_t) (event->type >> 8)));
    requestBody.push_back(toChar((uint8_t) ((event->type << 8) >> 8)));

    // code
    requestBody.push_back(toChar((uint8_t) (event->code >> 8)));
    requestBody.push_back(toChar((uint8_t) ((event->code << 8) >> 8)));

    // value
    auto value = (uint32_t) ((long long) (event->value) - INT32_MIN);
    for (uint8_t i = 0; i < 4; i++) {
        requestBody.push_back(toChar((uint8_t) ((value << (i << 3)) >> 24)));
    }
}

void MouseEventRequest::depackData(input_event *eventBuffer) {
    uint16_t tmp = (((uint16_t) toUnsignedChar(requestBody.at(0))) << 8) + (uint16_t) toUnsignedChar(requestBody.at(1));
    eventBuffer->type = tmp;
    tmp = (((uint16_t) toUnsignedChar(requestBody.at(2))) << 8) + (uint16_t) toUnsignedChar(requestBody.at(3));
    eventBuffer->code = tmp;

    uint32_t value = 0;
    for (unsigned i = 0; i < 4; i++) {
        value <<= 8;
        value += toUnsignedChar(requestBody.at(4u + i));
    }
    eventBuffer->value = (int32_t) ((int64_t) value + INT32_MIN);
}
