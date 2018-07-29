//
// Created by karl on 18-7-27.
//

#ifndef NEOTEACHERCLIENT_TRANSMISSIONCONTROLPROTOCOLSERIAL_H
#define NEOTEACHERCLIENT_TRANSMISSIONCONTROLPROTOCOLSERIAL_H


#include "Setting.h"
#include "Request.h"

class TransmissionControlProtocolSerial {
private:
    int socketFileDescriptor;
    int remoteFileDescriptor;
public:
    explicit TransmissionControlProtocolSerial(Setting *setting);

    void sendRequest(Request *request);

    void recieveRequest(Request **buffer);
};


#endif //NEOTEACHERCLIENT_TRANSMISSIONCONTROLPROTOCOLSERIAL_H
