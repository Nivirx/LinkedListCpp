cmake_minimum_required(VERSION 2.6)
project(linkedlistcpp)

set(SRC_FILES src/main.cpp src/linkedList.cpp)
set(HEADER_FILES include/linkedList.hpp)

include_directories(include/)
add_executable(linkedlistcpp ${SRC_FILES} ${HEADER_FILES})

install(TARGETS linkedlistcpp RUNTIME DESTINATION bin)
