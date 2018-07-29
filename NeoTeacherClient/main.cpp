#include <iostream>
#include "TransmissionControlProtocolSerial.h"

int main() {
//    auto setting = new Setting("/home/karl/Documents/NeuTeacher/NeoTeacher/NeoTeacherClient/debug.config.json");
    auto setting = new Setting("127.0.0.1", 8889, "./");
    TransmissionControlProtocolSerial TCPSerial(setting);
    auto request = new Request(Request::RTYPE_OK, "test msg");
    TCPSerial.sendRequest(request);
    return 0;
}
