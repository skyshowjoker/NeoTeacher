cmake_minimum_required(VERSION 3.12)
project(NeoTeacherServer)

set(CMAKE_CXX_STANDARD 17)

FIND_PACKAGE(PkgConfig REQUIRED)
FIND_PACKAGE(Threads)
PKG_CHECK_MODULES(JSON REQUIRED jsoncpp)

INCLUDE_DIRECTORIES(${JSON_INCLUDE_DIRS})
LINK_DIRECTORIES(${JSON_LIBRARY_DIRS})

ADD_DEFINITIONS(${JSON_CFLAGS_OTHER})

add_executable(${PROJECT_NAME} main.cpp TransmissionControlProtocolSerial.cpp TransmissionControlProtocolSerial.h Setting.cpp Setting.h Request.cpp Request.h MainScheduler.cpp MainScheduler.h User.cpp User.h ClientList.cpp ClientList.h Client.cpp Client.h)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${JSON_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})