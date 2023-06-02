cmake_minimum_required(VERSION 3.24)
project(PolymorphicSerialization)

set(CMAKE_CXX_STANDARD 17)

set(CORE_H Header/Core/*.hpp)
set(FILESYSTEM_H Header/FileSystem/*.hpp)
set(SERIALIZABLE_H Header/Serializable/*.hpp)
set(UTILS_H Header/Utils/*.hpp)
set(HEADER Header/*.hpp)

set(SOURCE Source/*.cpp)
set(CORE_C Source/Core/*.cpp)
set(FILESYSTEM_C Source/FileSystem/*.cpp)

file(GLOB HEADERS ${HEADER})
file(GLOB CORE_HEADERS ${CORE_H})
file(GLOB FILESYSTEM_HEADERS ${FILESYSTEM_H})
file(GLOB SERIALIZABLE_HEADERS ${SERIALIZABLE_H})
file(GLOB UTILS_HEADERS ${UTILS_H})

file(GLOB SOURCES ${SOURCE})
file(GLOB CORE_SOURCES ${CORE_C})
file(GLOB FILESYSTEM_SOURCES ${FILESYSTEM_C})


add_executable(PolymorphicSerialization
        main.cpp
        ${CORE_HEADERS}
        ${FILESYSTEM_HEADERS}
        ${SERIALIZABLE_HEADERS}
        ${UTILS_HEADERS}
        ${CORE_SOURCES}
        ${FILESYSTEM_SOURCES}
        ${SOURCES}
        )