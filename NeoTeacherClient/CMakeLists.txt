cmake_minimum_required(VERSION 3.12)
project(NeoTeacherClient)

set(CMAKE_CXX_STANDARD 17)

add_executable(NeoTeacherClient main.cpp TransmissionControlProtocolSerial.cpp TransmissionControlProtocolSerial.h Setting.cpp Setting.h Request.cpp Request.h)