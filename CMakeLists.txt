cmake_minimum_required(VERSION 3.25)
project(orb_slam2_learning_note)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

#add_executable(orb_slam2_learning_note main.cpp)
#add_executable(orb_slam2_learning_note 01_ListInit.cpp)
#add_executable(orb_slam2_learning_note 02_Auto.cpp)
#add_executable(orb_slam2_learning_note 03_LoopBody.cpp)
#add_executable(orb_slam2_learning_note 04_Lambda.cpp)
#add_executable(orb_slam2_learning_note 05_Tuple.cpp)
add_executable(orb_slam2_learning_note 06_Map.cpp)

target_link_libraries(orb_slam2_learning_note ${OpenCV_LIBS})
