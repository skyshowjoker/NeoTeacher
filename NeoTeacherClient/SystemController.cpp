//
// Created by karl on 18-7-29.
//

#include <cstdint>
#include <zconf.h>
#include <fcntl.h>
#include <stdexcept>
#include "SystemController.h"

#include <vector>
#include <cstring>

SystemController::SystemController(Setting *setting) {
//    uint8_t keyboardEvent = setting->getKeyboardEvent();
    uint8_t mouseEvent = setting->getMouseEvent();

    std::string mouseEventPath = std::string("/dev/input/event") + std::to_string(mouseEvent);

    if ((fileDescriptor[MOUSE] = open(mouseEventPath.c_str(), O_RDWR)) == -1) {
        throw std::runtime_error(std::string("failed open mouse event"));
    }
}

void SystemController::sync(int fd) {
    input_event syncEvent = {0};
    syncEvent.type = EV_SYN;
    syncEvent.code = SYN_REPORT;
    syncEvent.value = 0;
    write(fd, &syncEvent, sizeof(syncEvent));
}

void SystemController::click(int device, uint16_t keyValue) {
    SystemController::press(device, keyValue);
    SystemController::release(device, keyValue);
}

void SystemController::press(int device, uint16_t keyValue) {
    input_event pressEvent = {0};
    pressEvent.type = EV_KEY;
    pressEvent.code = keyValue;
    pressEvent.value = 1;
    write(fileDescriptor[device], &pressEvent, sizeof(pressEvent));
    sync(fileDescriptor[device]);
#ifdef __IN_DEBUG__
    fprintf(stderr, "")
#endif
}

void SystemController::release(int device, uint16_t keyValue) {
    input_event pressEvent = {0};
    pressEvent.type = EV_KEY;
    pressEvent.code = keyValue;
    pressEvent.value = 0;
    write(fileDescriptor[device], &pressEvent, sizeof(pressEvent));
    sync(fileDescriptor[device]);
}

void SystemController::shutdown() {
    system("shutdown 10");
}

void SystemController::reboot() {
    system("shutdown -r 10");
}

//void SystemController::getScreenShot(std::vector<uint8_t> &pixels, uint32_t &height, uint32_t &width,
//                                     uint32_t &bitsPerPixel) {
//    Display *display = XOpenDisplay(nullptr);
//    Window root = DefaultRootWindow(display);
//
//    XWindowAttributes attributes = {0};
//    XGetWindowAttributes(display, root, &attributes);
//
//    height = (uint32_t) attributes.height;
//    width = (uint32_t) attributes.width;
//
//    XImage *img = XGetImage(display, root, 0, 0, width, height, AllPlanes, ZPixmap);
//    bitsPerPixel = (uint32_t) img->bits_per_pixel;
//    pixels.resize(height * width * 4);
//
//    memcpy(&pixels[0], img->data, pixels.size());
//
//    XDestroyImage(img);
////    XCloseDisplay(display);
////}

void SystemController::XScreenInit(uint width, uint height) {
    screen = new ScreenShot(0, 0, width, height);
}

SystemController::ScreenShot * SystemController::getScreenShotStream() {
    return screen;
}
