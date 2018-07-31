#include <iostream>
#include "src/MainScheduler.h"

int main() {
    MainScheduler scheduler("/home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/debug.config.json");
    scheduler.start();
}
