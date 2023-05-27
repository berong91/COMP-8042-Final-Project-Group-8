#cmake_minimum_required(VERSION 3.25)
project(Final_Project)

set(CMAKE_CXX_STANDARD 11)

file(GLOB Final_Project_SRC
        "source/*.h"
        "source/*.cpp"
        )

add_executable(Final_Project ${Final_Project_SRC})
