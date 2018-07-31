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
    uint8_t mouseEvent;
    uint8_t keyboardEvent;
    uint32_t maxUser;

public:
    explicit Setting(std::string path);

    Setting(std::string address, uint16_t port, std::string path);

    std::string getAddress();

    uint32_t getMaxUser();

    void setMaxUser(uint32_t maxUser);

    uint16_t getPort();

    std::string getDataBasePath();

    uint8_t getMouseEvent();

    uint8_t getKeyboardEvent();

    void readFromFile(std::string path);

    ~Setting();

#ifdef __IN_DEBUG__
    void setAddress(std::string address);

    void setPort(uint16_t port);

    void setDataBasePath(std::string path);
#endif
};

#endif //NEOTEACHERCLIENT_SETTING_H
