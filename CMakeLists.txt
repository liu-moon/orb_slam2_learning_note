cmake_minimum_required(VERSION 3.25)
project(orb_slam2_learning_note)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

include_directories(
        ${OpenCV_INCLUDE_DIRS}
)


add_executable(orb_slam2_learning_note 01_CalFeaturePointDirection.cpp)

target_link_libraries(orb_slam2_learning_note ${OpenCV_LIBS})
