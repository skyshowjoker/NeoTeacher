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
    this->setAddress(root.get("server_address", "127.0.0.1").asString());
    this->setPort((uint16_t) root.get("server_port", 8080).asUInt());
    this->setDataBasePath(root.get("database_path", "./").asString());
}

Setting::Setting(std::string address, uint16_t port, std::string path) {
    setAddress(std::move(address));
    setPort(port);
    setDataBasePath(std::move(path));
}

Setting::Setting(std::string path) {
    readFromFile(std::move(path));
}

void Setting::setDataBasePath(std::string path) {
    dataBasePath = std::move(path);
}

void Setting::setAddress(std::string address) {
    serverAddress = std::move(address);
}

void Setting::setPort(uint16_t port) {
    serverPort = port;
}

std::string Setting::getDataBasePath() {
    return dataBasePath;
}

std::string Setting::getAddress() {
    return serverAddress;
}

uint16_t Setting::getPort() {
    return serverPort;
}