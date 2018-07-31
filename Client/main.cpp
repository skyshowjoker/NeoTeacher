#include <iostream>
#include "src/MainScheduler.h"

int main() {
    MainScheduler scheduler("/home/karl/Documents/NeuTeacher/NeoTeacher/Client/debug.config.json");
    scheduler.start();
}
