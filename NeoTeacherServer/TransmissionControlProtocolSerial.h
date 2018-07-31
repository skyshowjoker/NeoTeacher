//
// Created by karl on 18-7-27.
//

#ifndef NEOTEACHERCLIENT_TRANSMISSIONCONTROLPROTOCOLSERIAL_H
#define NEOTEACHERCLIENT_TRANSMISSIONCONTROLPROTOCOLSERIAL_H


#include "Setting.h"
#include "Request.h"

class TransmissionControlProtocolSerial {
private:
    int listenFileDescriptor;

public:
    explicit TransmissionControlProtocolSerial(Setting* setting);
    void sendRequest(int remoteFileDescriptor, Request* request);
    void receiveRequest(int remoteFileDescriptor, Request **request);

    int getListenFileDescriptor();
};


#endif //NEOTEACHERCLIENT_TRANSMISSIONCONTROLPROTOCOLSERIAL_H
