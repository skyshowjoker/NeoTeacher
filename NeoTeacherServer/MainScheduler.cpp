//
// Created by karl on 18-7-27.
//

#include <stdexcept>
#include "MainScheduler.h"

void * handleNewConnection(void *args) {

}

MainScheduler::MainScheduler(std::string filePath) {
    setting = new Setting(std::move(filePath));
    TCPSerial = new TransmissionControlProtocolSerial(setting);
    userList = new UserList();

    pthread_t pid;
    pthread_attr_t attr;
    if (!pthread_attr_init(&attr)) {
        throw std::runtime_error(std::string("failed initializing pthread_attr"));
    }
    pthread_create(&pid, &attr, &handleNewConnection, nullptr);
}
