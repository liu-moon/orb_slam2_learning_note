cmake_minimum_required(VERSION 3.25)
project(orb_slam2_learning_note)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(
        ${OpenCV_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIRS}
)


add_executable(orb_slam2_learning_note 01_LearnEigen.cpp)

target_link_libraries(orb_slam2_learning_note ${OpenCV_LIBS})
