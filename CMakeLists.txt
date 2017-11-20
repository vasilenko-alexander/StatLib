cmake_minimum_required(VERSION 3.2)

project(StatLib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(SOURCES ${CMAKE_SOURCE_DIR}/src/statlib.cpp)
set(INCLUDE ${CMAKE_SOURCE_DIR}/include)
set(PROJECT_LIBS_DIR ${CMAKE_SOURCE_DIR}/lib)

include_directories(${INCLUDE})

if(NOT MSVC)
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(SDL_FLAGS -lSDL2d
                  -lSDL2maind
                  -lpthread
                  -ldl)
else(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    set(SDL_FLAGS -lSDL2
                  -lSDL2maind
                  -lpthread
                  -ldl)
endif()

link_directories(${PROJECT_LIBS_DIR})

add_executable(StatLib ${SOURCES})
target_link_libraries(StatLib ${SDL_FLAGS})
