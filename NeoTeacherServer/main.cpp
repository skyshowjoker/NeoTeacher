#include <iostream>
#include "MainScheduler.h"

int main() {
    MainScheduler mainScheduler(std::string("/home/karl/Documents/NeuTeacher/NeoTeacher/NeoTeacherServer/debug.config.json"));
    mainScheduler.start();
    return 0;
}
