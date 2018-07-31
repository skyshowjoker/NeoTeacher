//
// Created by karl on 18-7-27.
//

#include "Setting.h"

#include <json/json.h>
#include <fstream>

void Setting::readFromFile(std::string path) {
    std::ifstream ifs(path);
    Json::Reader reader;
    Json::Value root;
    reader.parse(ifs, root);
    serverAddress = root.get("server_address", "127.0.0.1").asString();
    serverPort = (uint16_t) root.get("server_port", 8080).asUInt();
    dataBasePath = root.get("database_path", "./").asString();
    mouseEvent = (uint8_t) root.get("mouse_event", 6).asUInt();
    keyboardEvent = (uint8_t) root.get("keyboard_event", 2).asUInt();
    ifs.close();
}

Setting::Setting(std::string address, uint16_t port, std::string path) {
    serverAddress = std::move(address);
    serverPort = port;
    dataBasePath = std::move(path);
}

Setting::Setting(std::string path) {
    readFromFile(std::move(path));
}

#ifdef __IN_DEBUG__
void Setting::setDataBasePath(std::string path) {
    dataBasePath = std::move(path);
}

void Setting::setAddress(std::string address) {
    serverAddress = std::move(address);
}

void Setting::setPort(uint16_t port) {
    serverPort = port;
}
#endif

std::string Setting::getDataBasePath() {
    return dataBasePath;
}

std::string Setting::getAddress() {
    return serverAddress;
}

uint16_t Setting::getPort() {
    return serverPort;
}

uint8_t Setting::getMouseEvent() {
    return mouseEvent;
}

uint8_t Setting::getKeyboardEvent() {
    return keyboardEvent;
}

Setting::~Setting() = default;
