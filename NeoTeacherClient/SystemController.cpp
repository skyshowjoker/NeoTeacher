//
// Created by karl on 18-7-29.
//

#include <cstdint>
#include <zconf.h>
#include "SystemController.h"

void SystemController::sync(int fd) {
    input_event syncEvent = {0};
    syncEvent.type = EV_SYN;
    syncEvent.code = SYN_REPORT;
    syncEvent.value = 0;
    write(fd, &syncEvent, sizeof(syncEvent));
}

void SystemController::click(int fd, uint16_t keyValue) {
    SystemController::press(fd, keyValue);
    SystemController::release(fd, keyValue);
}

void SystemController::press(int fd, uint16_t keyValue) {
    input_event pressEvent = {0};
    pressEvent.type = EV_KEY;
    pressEvent.code = keyValue;
    pressEvent.value = 1;
    write(fd, &pressEvent, sizeof(pressEvent));
    sync(fd);
}

void SystemController::release(int fd, uint16_t keyValue) {
    input_event pressEvent = {0};
    pressEvent.type = EV_KEY;
    pressEvent.code = keyValue;
    pressEvent.value = 0;
    write(fd, &pressEvent, sizeof(pressEvent));
    sync(fd);
}