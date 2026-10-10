cmake_minimum_required(VERSION 3.20)

project(student_manager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(student src/main.cpp)

add_library(student_lib STATIC src/shared_ptr.cpp
    )

target_include_directories(student PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(student_lib PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(student PRIVATE student_lib)