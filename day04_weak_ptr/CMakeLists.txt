cmake_minimum_required(VERSION 3.20)

project(student_manager1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(student1 src/main.cpp)

add_library(student_lib STATIC src/shared_ptr.cpp
    )

target_include_directories(student1 PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(student_lib PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(student1 PRIVATE student_lib)