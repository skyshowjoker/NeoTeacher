//
// Created by karl on 18-7-27.
//

#ifndef NEOTEACHERCLIENT_SETTING_H
#define NEOTEACHERCLIENT_SETTING_H

#include <string>

class Setting {
private:
    uint16_t serverPort;
    std::string dataBasePath = "./";
    uint32_t maxUser;

public:
    explicit Setting(std::string path);

    uint32_t getMaxUser();

    uint16_t getPort();

    std::string getDataBasePath();

    void setMaxUser(uint32_t maxUser);

    void setPort(uint16_t port);

    void setDataBasePath(std::string path);

    void readFromFile(std::string path);
};

#endif //NEOTEACHERCLIENT_SETTING_H
