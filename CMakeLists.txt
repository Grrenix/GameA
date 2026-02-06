cmake_minimum_required(VERSION 3.20)
project(GameA)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Add engine project
add_subdirectory(engine)

add_executable(GameA
    src/main.cpp
)

target_link_libraries(GameA PRIVATE engine)
