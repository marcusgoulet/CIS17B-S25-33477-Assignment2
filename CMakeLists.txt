cmake_minimum_required(VERSION 3.10)
project(CIS17B_S25_33477_Assignment2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include headers from the include directory
include_directories(include)

# Add all source files
file(GLOB SOURCES "src/*.cpp")

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES} src/main.cpp)
