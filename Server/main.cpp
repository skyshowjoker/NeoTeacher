#include <iostream>
#include "src/Setting.h"
#include "src/TransmissionControlProtocolSerial.h"
#include "src/ClientManager.h"

int main() {
    auto setting = new Setting("/home/karl/Documents/NeuTeacher/NeoTeacher/Server/debug.config.json");
    auto TCPSerial = new TransmissionControlProtocolSerial(setting);
    auto clientManager = new ClientManager();
    clientManager->handleNewConnection(TCPSerial);
    return 0;
}