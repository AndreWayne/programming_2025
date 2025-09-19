cmake_minimum_required(VERSION 3.15)
project(MyHelloWorldProject LANGUAGES CXX)

set(SOURCE_FILES
main.cpp
)


set(CMAKE_CXX_STANDARD 17)


add_executable(MyExecutable ${SOURCE_FILES})