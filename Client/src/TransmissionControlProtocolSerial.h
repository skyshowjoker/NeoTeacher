//
// Created by karl on 18-7-27.
//

#ifndef NEOTEACHERCLIENT_TRANSMISSIONCONTROLPROTOCOLSERIAL_H
#define NEOTEACHERCLIENT_TRANSMISSIONCONTROLPROTOCOLSERIAL_H


#include "Setting.h"
#include "Request/Request.h"

class TransmissionControlProtocolSerial {
private:
    int socketFileDescriptor;
public:
    explicit TransmissionControlProtocolSerial(Setting *setting);

    void sendRequest(Request *request);

    void receiveRequest(Request **pRequest);

    ~TransmissionControlProtocolSerial();
};


#endif //NEOTEACHERCLIENT_TRANSMISSIONCONTROLPROTOCOLSERIAL_H
