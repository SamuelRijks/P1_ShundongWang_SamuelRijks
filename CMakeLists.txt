cmake_minimum_required(VERSION 3.25)
project(P1_ShundongWang_SamuelRijks)

set(CMAKE_CXX_STANDARD 17)

add_executable(P1_ShundongWang_SamuelRijks Sources/main.cpp
        Sources/src/MyEnum.cpp
        Headers/include/MyEnum.h
        Sources/src/Position.cpp
        Headers/include/Position.h
        Sources/src/Snake.cpp 
        Headers/include/Snake.h
        Sources/src/Taulell.cpp
        Headers/include/Taulell.h
        Headers/include/cogido.h
)
