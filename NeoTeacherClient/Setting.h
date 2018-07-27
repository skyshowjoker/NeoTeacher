//
// Created by karl on 18-7-27.
//

#ifndef NEOTEACHERCLIENT_SETTING_H
#define NEOTEACHERCLIENT_SETTING_H

#include <string>

class Setting {
private:
    std::string serverAddress;
    uint16_t serverPort;
    std::string dataBasePath = "./";

public:
    explicit Setting(std::string path);

    Setting(std::string address, uint16_t port, std::string path);

    std::string getAddress();

    uint16_t getPort();

    std::string getDataBasePath();

    void setAddress(std::string address);

    void setPort(uint16_t port);

    void setDataBasePath(std::string path);

    void readFromFile(std::string path);
};

#endif //NEOTEACHERCLIENT_SETTING_H
