//#include <iostream>
//#include "TransmissionControlProtocolSerial.h"
//
//int main() {
////    auto setting = new Setting("/home/karl/Documents/NeuTeacher/NeoTeacher/NeoTeacherClient/debug.config.json");
//    auto setting = new Setting("127.0.0.1", 8889, "./");
//    TransmissionControlProtocolSerial TCPSerial(setting);
//    auto request = new Request(Request::RTYPE_OK, "test msg");
//    TCPSerial.sendRequest(request);
//    return 0;
//}

#define __IN_DEBUG__

#include <zconf.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <string>
#include <cstring>
#include "SystemController.h"
#include "Request.h"

void *timer(void *args) {
    sleep(1);
    *(bool *) args = false;
}

int main() {
    auto setting = new Setting("/home/karl/Documents/NeuTeacher/NeoTeacher/NeoTeacherClient/debug.config.json");
    auto controller = new SystemController(setting);

    std::vector<uint8_t> pixels;
    uint32_t width, height, bitsPerPixel;
//    controller->getScreenShot(pixels, height, width, bitsPerPixel);
//    printf ("width:  %u\n", width);
//    printf ("height: %u\n", height);
//    printf ("bpp:    %u\n", bitsPerPixel);
//    printf ("pixels:\n");
//    for (auto pixel : pixels) {
//        printf ("%u ", pixel);
//    }
    cv::Mat *image;
    controller->XScreenInit(1920, 1080);
    auto stream = *(controller->getScreenShotStream());
//    (*stream) >> &image;
//    cv::imshow("show", *image);
//    cv::imwrite("screenshot-raw.bmp", *image);
//    std::vector<int> jpegCompParams;
//    jpegCompParams.push_back(CV_IMWRITE_JPEG_QUALITY);
//    jpegCompParams.push_back(30);
//    cv::imwrite("screenshot.jpg", *image, jpegCompParams);
//    std::vector<int> pngCompParams;
//    pngCompParams.push_back(CV_IMWRITE_PNG_COMPRESSION);
//    pngCompParams.push_back(0);
//    cv::imwrite("screenshot.png", *image, pngCompParams);
//    cv::waitKey(0);
    bool flag = true;
    pthread_t pid;
    std::vector<int> para;
    para.push_back(CV_IMWRITE_JPEG_QUALITY);
    para.push_back(33);
    pthread_create(&pid, nullptr, &timer, (void *) &flag);
    int64_t i = 0;
    while (flag) {
        i++;
        stream >> &image;
//        auto filename = std::string("screenshot-") + std::to_string(i) + std::string(".jpg");
        auto filename = std::string("screenshot.jpg");
        cv::imwrite(filename.c_str(), *image, para);
        ~*image;
    }
    pthread_join(pid, nullptr);
    fprintf(stderr, "%lld screenshots per sec..\n", i);

    pthread_create(&pid, nullptr, &timer, (void *) &flag);
    flag = true;
    i = 0;
    while (flag) {
        *image = cv::imread("screenshot.jpg");
        cv::imshow("showImage", *image);
        cv::waitKey(1);
        i++;
    }
    pthread_join(pid, nullptr);
    fprintf(stderr, "can print %lld imgs per second..\n", i);
}

//int main() {
//    MainScheduler mainScheduler(...);
//    mainScheduler.start();
//}

void Login() {
    std::string username;
    std::string password;

   // get username;
    username = std::string ("shit");
   // get password;
    password = std::string ("fuck");

    auto *request = new LogInRequest(username, password);
    TCPSerial->sendRequest(request);
    free(request);
    Request * recvBuff = new Request();
    TCPSerial->recvRequest(&recvBuff);
    if (recvBuff->getRequestType() != Request::RTYPE_OK) {
        throw std::runtime_error(std::string("failed logging-in"));
    }
    MainScheduler.setLogin(true);
}
