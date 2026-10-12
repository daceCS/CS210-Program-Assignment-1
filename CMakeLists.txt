cmake_minimum_required(VERSION 3.26)
project(cs210_stack_queue_lab)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cs210_stack_queue_lab
        main.cpp
        Node.h
        List.h
        ArrayList.h
        LinkedList.h
        Data.h
        Stack.h
        StackList.h
        Queue.h
        Player.h)
