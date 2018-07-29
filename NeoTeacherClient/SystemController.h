//
// Created by karl on 18-7-29.
//

#ifndef NEOTEACHERCLIENT_SYSTEMCONTROLLER_H
#define NEOTEACHERCLIENT_SYSTEMCONTROLLER_H

#include <linux/input.h>
#include <cstdint>

class SystemController {
private:
    int systemFileDescriptor;
    void sync(int fd);

public:
    void click(int fd, uint16_t keyValue);
    void press(int fd, uint16_t keyValue);
    void release(int fd, uint16_t keyValue);
};


#endif //NEOTEACHERCLIENT_SYSTEMCONTROLLER_H
