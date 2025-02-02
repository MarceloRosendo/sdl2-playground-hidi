cmake_minimum_required(VERSION 3.0.0)

project(sdltest)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(SourceFiles
    main.cpp
    screens/window.cpp
    objects/square.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/screens)

add_executable(${PROJECT_NAME} ${SourceFiles} ${HeaderFiles})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})