cmake_minimum_required(VERSION 2.6)
project(linkedlistcpp)

add_executable(linkedlistcpp main.cpp linkedList.cpp)

install(TARGETS linkedlistcpp RUNTIME DESTINATION bin)
