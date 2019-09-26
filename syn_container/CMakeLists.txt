cmake_minimum_required(VERSION 3.12)
project(rwlock)

set(CMAKE_CXX_STANDARD 14)

add_executable(rwlock  rwmap.h CondQueue.h
        testsynqueue.cpp)