cmake_minimum_required(VERSION 3.24)
project(esp32_iot)


include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(testNetwork ${SOURCES})

