cmake_minimum_required(VERSION 3.10)
project(a)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -DLOCAL")
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -DLOCAL")
endif()

add_executable(a a.cpp)
