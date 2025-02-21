cmake_minimum_required(VERSION 3.29)
project(cpp_grasshopper_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_grasshopper_game
        main.cpp
        mocks.h
        model.h
        view.h
        controller.h
)
