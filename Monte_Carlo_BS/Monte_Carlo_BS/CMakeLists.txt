cmake_minimum_required(VERSION 3.17)
project(Monte_Carlo_BS)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Monte_Carlo_BS
        ArmthAsianCall.cpp
        ArmthAsianCall.hpp
        BSModel.cpp
        BSModel.hpp
        main.cpp
        PathDepOption.cpp
        PathDepOption.hpp
        "Range Accrual Note.cpp"
        "Range Accrual Note.hpp"
        Stats1.cpp
        Stats1.hpp)
