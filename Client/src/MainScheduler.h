//
// Created by karl on 18-7-31.
//

#ifndef CLIENT_MAINSCHEDULER_H
#define CLIENT_MAINSCHEDULER_H


#include "TransmissionControlProtocolSerial.h"
#include "SystemController.h"

class MainScheduler {
private:
    Setting *setting;
    SystemController *systemController;
    TransmissionControlProtocolSerial *TCPSerial;

public:
    explicit MainScheduler(std::string path);
    void init(std::string path);
    void start();
    void end();

    ~MainScheduler();
};


#endif //CLIENT_MAINSCHEDULER_H
