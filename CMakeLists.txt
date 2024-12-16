cmake_minimum_required(VERSION 3.29)
project(csc340_assignment5)

set(CMAKE_CXX_STANDARD 14)

include_directories(assignment4_code)
include_directories(assignment4_code/LinkedBagDS)

add_executable(csc340_assignment5
    assignment4_code/LinkedBagDS/BagInterface.h
    assignment4_code/LinkedBagDS/LinkedBag.cpp
    assignment4_code/LinkedBagDS/LinkedBag.h
    assignment4_code/LinkedBagDS/Node.cpp
    assignment4_code/LinkedBagDS/Node.h
    assignment4_code/Graph.cpp
    assignment4_code/Graph.h
    assignment4_code/Instagram340_Graph_main.cpp
        assignment4_code/User.cpp)
