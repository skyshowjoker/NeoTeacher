# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/karl/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/182.3684.76/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/karl/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/182.3684.76/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/karl/Documents/NeuTeacher/NeoTeacher/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Client.dir/flags.make

CMakeFiles/Client.dir/main.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Client.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/main.cpp.o -c /home/karl/Documents/NeuTeacher/NeoTeacher/Client/main.cpp

CMakeFiles/Client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/Documents/NeuTeacher/NeoTeacher/Client/main.cpp > CMakeFiles/Client.dir/main.cpp.i

CMakeFiles/Client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/Documents/NeuTeacher/NeoTeacher/Client/main.cpp -o CMakeFiles/Client.dir/main.cpp.s

CMakeFiles/Client.dir/src/Request/Request.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/Request/Request.cpp.o: ../src/Request/Request.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Client.dir/src/Request/Request.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/Request/Request.cpp.o -c /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/Request.cpp

CMakeFiles/Client.dir/src/Request/Request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/Request/Request.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/Request.cpp > CMakeFiles/Client.dir/src/Request/Request.cpp.i

CMakeFiles/Client.dir/src/Request/Request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/Request/Request.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/Request.cpp -o CMakeFiles/Client.dir/src/Request/Request.cpp.s

CMakeFiles/Client.dir/src/Request/FileRequest.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/Request/FileRequest.cpp.o: ../src/Request/FileRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Client.dir/src/Request/FileRequest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/Request/FileRequest.cpp.o -c /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/FileRequest.cpp

CMakeFiles/Client.dir/src/Request/FileRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/Request/FileRequest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/FileRequest.cpp > CMakeFiles/Client.dir/src/Request/FileRequest.cpp.i

CMakeFiles/Client.dir/src/Request/FileRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/Request/FileRequest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/FileRequest.cpp -o CMakeFiles/Client.dir/src/Request/FileRequest.cpp.s

CMakeFiles/Client.dir/src/Request/MouseEventRequest.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/Request/MouseEventRequest.cpp.o: ../src/Request/MouseEventRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Client.dir/src/Request/MouseEventRequest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/Request/MouseEventRequest.cpp.o -c /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/MouseEventRequest.cpp

CMakeFiles/Client.dir/src/Request/MouseEventRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/Request/MouseEventRequest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/MouseEventRequest.cpp > CMakeFiles/Client.dir/src/Request/MouseEventRequest.cpp.i

CMakeFiles/Client.dir/src/Request/MouseEventRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/Request/MouseEventRequest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/MouseEventRequest.cpp -o CMakeFiles/Client.dir/src/Request/MouseEventRequest.cpp.s

CMakeFiles/Client.dir/src/Request/ErrorRequest.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/Request/ErrorRequest.cpp.o: ../src/Request/ErrorRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Client.dir/src/Request/ErrorRequest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/Request/ErrorRequest.cpp.o -c /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/ErrorRequest.cpp

CMakeFiles/Client.dir/src/Request/ErrorRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/Request/ErrorRequest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/ErrorRequest.cpp > CMakeFiles/Client.dir/src/Request/ErrorRequest.cpp.i

CMakeFiles/Client.dir/src/Request/ErrorRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/Request/ErrorRequest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/ErrorRequest.cpp -o CMakeFiles/Client.dir/src/Request/ErrorRequest.cpp.s

CMakeFiles/Client.dir/src/Request/HandInRequest.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/Request/HandInRequest.cpp.o: ../src/Request/HandInRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Client.dir/src/Request/HandInRequest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/Request/HandInRequest.cpp.o -c /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/HandInRequest.cpp

CMakeFiles/Client.dir/src/Request/HandInRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/Request/HandInRequest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/HandInRequest.cpp > CMakeFiles/Client.dir/src/Request/HandInRequest.cpp.i

CMakeFiles/Client.dir/src/Request/HandInRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/Request/HandInRequest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/HandInRequest.cpp -o CMakeFiles/Client.dir/src/Request/HandInRequest.cpp.s

CMakeFiles/Client.dir/src/Request/HandUpRequest.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/Request/HandUpRequest.cpp.o: ../src/Request/HandUpRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Client.dir/src/Request/HandUpRequest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/Request/HandUpRequest.cpp.o -c /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/HandUpRequest.cpp

CMakeFiles/Client.dir/src/Request/HandUpRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/Request/HandUpRequest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/HandUpRequest.cpp > CMakeFiles/Client.dir/src/Request/HandUpRequest.cpp.i

CMakeFiles/Client.dir/src/Request/HandUpRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/Request/HandUpRequest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/HandUpRequest.cpp -o CMakeFiles/Client.dir/src/Request/HandUpRequest.cpp.s

CMakeFiles/Client.dir/src/Request/OKRequest.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/Request/OKRequest.cpp.o: ../src/Request/OKRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Client.dir/src/Request/OKRequest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/Request/OKRequest.cpp.o -c /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/OKRequest.cpp

CMakeFiles/Client.dir/src/Request/OKRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/Request/OKRequest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/OKRequest.cpp > CMakeFiles/Client.dir/src/Request/OKRequest.cpp.i

CMakeFiles/Client.dir/src/Request/OKRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/Request/OKRequest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/OKRequest.cpp -o CMakeFiles/Client.dir/src/Request/OKRequest.cpp.s

CMakeFiles/Client.dir/src/Request/LoginRequest.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/Request/LoginRequest.cpp.o: ../src/Request/LoginRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Client.dir/src/Request/LoginRequest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/Request/LoginRequest.cpp.o -c /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/LoginRequest.cpp

CMakeFiles/Client.dir/src/Request/LoginRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/Request/LoginRequest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/LoginRequest.cpp > CMakeFiles/Client.dir/src/Request/LoginRequest.cpp.i

CMakeFiles/Client.dir/src/Request/LoginRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/Request/LoginRequest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/LoginRequest.cpp -o CMakeFiles/Client.dir/src/Request/LoginRequest.cpp.s

CMakeFiles/Client.dir/src/MainScheduler.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/MainScheduler.cpp.o: ../src/MainScheduler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Client.dir/src/MainScheduler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/MainScheduler.cpp.o -c /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/MainScheduler.cpp

CMakeFiles/Client.dir/src/MainScheduler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/MainScheduler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/MainScheduler.cpp > CMakeFiles/Client.dir/src/MainScheduler.cpp.i

CMakeFiles/Client.dir/src/MainScheduler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/MainScheduler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/MainScheduler.cpp -o CMakeFiles/Client.dir/src/MainScheduler.cpp.s

CMakeFiles/Client.dir/src/Setting.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/Setting.cpp.o: ../src/Setting.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Client.dir/src/Setting.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/Setting.cpp.o -c /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Setting.cpp

CMakeFiles/Client.dir/src/Setting.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/Setting.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Setting.cpp > CMakeFiles/Client.dir/src/Setting.cpp.i

CMakeFiles/Client.dir/src/Setting.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/Setting.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Setting.cpp -o CMakeFiles/Client.dir/src/Setting.cpp.s

CMakeFiles/Client.dir/src/SystemController.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/SystemController.cpp.o: ../src/SystemController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Client.dir/src/SystemController.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/SystemController.cpp.o -c /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/SystemController.cpp

CMakeFiles/Client.dir/src/SystemController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/SystemController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/SystemController.cpp > CMakeFiles/Client.dir/src/SystemController.cpp.i

CMakeFiles/Client.dir/src/SystemController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/SystemController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/SystemController.cpp -o CMakeFiles/Client.dir/src/SystemController.cpp.s

CMakeFiles/Client.dir/src/TransmissionControlProtocolSerial.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/TransmissionControlProtocolSerial.cpp.o: ../src/TransmissionControlProtocolSerial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Client.dir/src/TransmissionControlProtocolSerial.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/TransmissionControlProtocolSerial.cpp.o -c /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/TransmissionControlProtocolSerial.cpp

CMakeFiles/Client.dir/src/TransmissionControlProtocolSerial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/TransmissionControlProtocolSerial.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/TransmissionControlProtocolSerial.cpp > CMakeFiles/Client.dir/src/TransmissionControlProtocolSerial.cpp.i

CMakeFiles/Client.dir/src/TransmissionControlProtocolSerial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/TransmissionControlProtocolSerial.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/TransmissionControlProtocolSerial.cpp -o CMakeFiles/Client.dir/src/TransmissionControlProtocolSerial.cpp.s

CMakeFiles/Client.dir/src/UserOperations.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/UserOperations.cpp.o: ../src/UserOperations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Client.dir/src/UserOperations.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/UserOperations.cpp.o -c /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/UserOperations.cpp

CMakeFiles/Client.dir/src/UserOperations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/UserOperations.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/UserOperations.cpp > CMakeFiles/Client.dir/src/UserOperations.cpp.i

CMakeFiles/Client.dir/src/UserOperations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/UserOperations.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/UserOperations.cpp -o CMakeFiles/Client.dir/src/UserOperations.cpp.s

CMakeFiles/Client.dir/src/Request/QuitRequest.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/Request/QuitRequest.cpp.o: ../src/Request/QuitRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Client.dir/src/Request/QuitRequest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/Request/QuitRequest.cpp.o -c /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/QuitRequest.cpp

CMakeFiles/Client.dir/src/Request/QuitRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/Request/QuitRequest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/QuitRequest.cpp > CMakeFiles/Client.dir/src/Request/QuitRequest.cpp.i

CMakeFiles/Client.dir/src/Request/QuitRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/Request/QuitRequest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karl/Documents/NeuTeacher/NeoTeacher/Client/src/Request/QuitRequest.cpp -o CMakeFiles/Client.dir/src/Request/QuitRequest.cpp.s

# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/main.cpp.o" \
"CMakeFiles/Client.dir/src/Request/Request.cpp.o" \
"CMakeFiles/Client.dir/src/Request/FileRequest.cpp.o" \
"CMakeFiles/Client.dir/src/Request/MouseEventRequest.cpp.o" \
"CMakeFiles/Client.dir/src/Request/ErrorRequest.cpp.o" \
"CMakeFiles/Client.dir/src/Request/HandInRequest.cpp.o" \
"CMakeFiles/Client.dir/src/Request/HandUpRequest.cpp.o" \
"CMakeFiles/Client.dir/src/Request/OKRequest.cpp.o" \
"CMakeFiles/Client.dir/src/Request/LoginRequest.cpp.o" \
"CMakeFiles/Client.dir/src/MainScheduler.cpp.o" \
"CMakeFiles/Client.dir/src/Setting.cpp.o" \
"CMakeFiles/Client.dir/src/SystemController.cpp.o" \
"CMakeFiles/Client.dir/src/TransmissionControlProtocolSerial.cpp.o" \
"CMakeFiles/Client.dir/src/UserOperations.cpp.o" \
"CMakeFiles/Client.dir/src/Request/QuitRequest.cpp.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

Client: CMakeFiles/Client.dir/main.cpp.o
Client: CMakeFiles/Client.dir/src/Request/Request.cpp.o
Client: CMakeFiles/Client.dir/src/Request/FileRequest.cpp.o
Client: CMakeFiles/Client.dir/src/Request/MouseEventRequest.cpp.o
Client: CMakeFiles/Client.dir/src/Request/ErrorRequest.cpp.o
Client: CMakeFiles/Client.dir/src/Request/HandInRequest.cpp.o
Client: CMakeFiles/Client.dir/src/Request/HandUpRequest.cpp.o
Client: CMakeFiles/Client.dir/src/Request/OKRequest.cpp.o
Client: CMakeFiles/Client.dir/src/Request/LoginRequest.cpp.o
Client: CMakeFiles/Client.dir/src/MainScheduler.cpp.o
Client: CMakeFiles/Client.dir/src/Setting.cpp.o
Client: CMakeFiles/Client.dir/src/SystemController.cpp.o
Client: CMakeFiles/Client.dir/src/TransmissionControlProtocolSerial.cpp.o
Client: CMakeFiles/Client.dir/src/UserOperations.cpp.o
Client: CMakeFiles/Client.dir/src/Request/QuitRequest.cpp.o
Client: CMakeFiles/Client.dir/build.make
Client: /usr/lib/x86_64-linux-gnu/libSM.so
Client: /usr/lib/x86_64-linux-gnu/libICE.so
Client: /usr/lib/x86_64-linux-gnu/libX11.so
Client: /usr/lib/x86_64-linux-gnu/libXext.so
Client: /usr/local/lib/libopencv_dnn.so.3.4.1
Client: /usr/local/lib/libopencv_ml.so.3.4.1
Client: /usr/local/lib/libopencv_objdetect.so.3.4.1
Client: /usr/local/lib/libopencv_shape.so.3.4.1
Client: /usr/local/lib/libopencv_stitching.so.3.4.1
Client: /usr/local/lib/libopencv_superres.so.3.4.1
Client: /usr/local/lib/libopencv_videostab.so.3.4.1
Client: /usr/local/lib/libopencv_viz.so.3.4.1
Client: /usr/lib/x86_64-linux-gnu/libssl.so
Client: /usr/lib/x86_64-linux-gnu/libcrypto.so
Client: /usr/local/lib/libopencv_calib3d.so.3.4.1
Client: /usr/local/lib/libopencv_features2d.so.3.4.1
Client: /usr/local/lib/libopencv_flann.so.3.4.1
Client: /usr/local/lib/libopencv_highgui.so.3.4.1
Client: /usr/local/lib/libopencv_photo.so.3.4.1
Client: /usr/local/lib/libopencv_video.so.3.4.1
Client: /usr/local/lib/libopencv_videoio.so.3.4.1
Client: /usr/local/lib/libopencv_imgcodecs.so.3.4.1
Client: /usr/local/lib/libopencv_imgproc.so.3.4.1
Client: /usr/local/lib/libopencv_core.so.3.4.1
Client: CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Client.dir/build: Client

.PHONY : CMakeFiles/Client.dir/build

CMakeFiles/Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Client.dir/clean

CMakeFiles/Client.dir/depend:
	cd /home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/karl/Documents/NeuTeacher/NeoTeacher/Client /home/karl/Documents/NeuTeacher/NeoTeacher/Client /home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug /home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug /home/karl/Documents/NeuTeacher/NeoTeacher/Client/cmake-build-debug/CMakeFiles/Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Client.dir/depend

