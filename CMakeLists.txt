cmake_minimum_required(VERSION 3.26)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataStructure main.cpp)
add_executable(addPositiveNums algorithm/addPositiveNums.c)
add_executable(addTwoNums algorithm/addTwoNums.c)
add_executable(Euclid algorithm/Euclid.c)

add_executable(ListApp linear/LinkedList.cpp linear/LinkedList.h)
add_executable(SqList linear/SqList.cpp linear/SqList.h)

add_executable(OperatorOverload test/OperatorOverload.cpp)
add_executable(Test1 test/Test1.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=UTF-8")