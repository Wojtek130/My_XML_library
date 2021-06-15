cmake_minimum_required(VERSION 3.0) #required

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g")

project (xml_parser) #required
add_executable(xml_parser main.cpp manipulators.cpp xml.cpp) #required 