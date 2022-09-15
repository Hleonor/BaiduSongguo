cmake_minimum_required(VERSION 3.22)
project(Baidu)

set(CMAKE_CXX_STANDARD 14)

add_executable(Baidu main.cpp)

add_executable(chess FirstWeek/chess.cpp)
add_executable(combineArr FirstWeek/combineArr.cpp)
add_executable(factorial FirstWeek/factorial.cpp)
add_executable(matrixMultiple FirstWeek/matrixMultiple.cpp)
add_executable(MXRCompetition FirstWeek/MXRCompetition.cpp)
add_executable(powerOf2 FirstWeek/powerOf2.cpp)
add_executable(NoRepeatString SecondWeek/NoRepeatString.cpp)