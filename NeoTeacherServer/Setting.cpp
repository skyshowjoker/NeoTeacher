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
    setMaxUser(root.get("max_user", 1024).asUInt());
    setPort((uint16_t) root.get("server_port", 8080).asUInt());
    setDataBasePath(root.get("database_path", "./").asString());
}

Setting::Setting(std::string path) {
    readFromFile(std::move(path));
}

void Setting::setDataBasePath(std::string path) {
    dataBasePath = std::move(path);
}

void Setting::setPort(uint16_t port) {
    serverPort = port;
}

void Setting::setMaxUser(uint32_t maxUser) {
    this->maxUser = maxUser;
}

std::string Setting::getDataBasePath() {
    return dataBasePath;
}

uint16_t Setting::getPort() {
    return serverPort;
}

uint32_t Setting::getMaxUser() {
    return maxUser;
}
