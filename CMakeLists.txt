cmake_minimum_required(VERSION 3.4...3.18)
project(RoadDataBase)

add_subdirectory(pybind11)

include_directories(pybind11)

# Список всех исходных файлов
set(SOURCES
    src/main.cpp
    src/Coordinate.cpp
    src/Sign.cpp
    src/RoadDB.cpp
)

# add_executable(RoadDataBase ${SOURCES})

pybind11_add_module(RoadDataBase ${SOURCES})

target_compile_definitions(RoadDataBase
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
