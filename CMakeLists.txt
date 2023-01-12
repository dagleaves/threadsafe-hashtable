cmake_minimum_required(VERSION 3.14)
project(csce311_lab3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
