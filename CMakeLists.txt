cmake_minimum_required(VERSION 3.10)

project(dsa_project)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/header)

set(SOURCES
    main.cpp
)

add_executable(app ${SOURCES})

