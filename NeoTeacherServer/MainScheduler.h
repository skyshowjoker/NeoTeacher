//
// Created by karl on 18-7-27.
//

#ifndef NEOTEACHERCLIENT_MAINSCHEDULER_H
#define NEOTEACHERCLIENT_MAINSCHEDULER_H


#include <string>
#include "Setting.h"
#include "TransmissionControlProtocolSerial.h"
#include "ClientManager.h"

class MainScheduler {
private:
    Setting *setting;
    TransmissionControlProtocolSerial *TCPSerial;
    ClientManager *clientManager;

//    void *handleNewConnection(void *args);

public:
    explicit MainScheduler(std::string filePath);

    void start();
};


#endif //NEOTEACHERCLIENT_MAINSCHEDULER_H
