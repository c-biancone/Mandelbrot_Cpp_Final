cmake_minimum_required(VERSION 3.21)
project(Gigabrot_Cpp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-Ofast -std=c++17 -lstdc++)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

add_executable(Gigabrot_Cpp
        #executables
            src/main.cpp
            #src/ThreadPoolTest.cpp

        #headers
        src/PPM.cpp
        src/PPM.h
        src/Mandelbrot.cpp
        src/Colorization.cpp
        src/Colorization.h
        src/Shading.cpp
        src/Shading.h
        src/InsideColor.cpp
        src/InsideColor.h
        src/LineColor.cpp
        src/LineColor.h
        src/Striping.cpp
        src/Striping.h
        src/NormalMap.cpp
        src/NormalMap.h
        src/Neumorphic.cpp
        src/Neumorphic.h
        src/ThreadPool.cpp
        src/ThreadPool.h
        src/UnboundedQueue.h
        )
