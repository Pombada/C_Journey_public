cmake_minimum_required(VERSION 3.28)
project(C_Journey_public C)

set(CMAKE_C_STANDARD 99)

add_executable(C_Journey_public main.c
        Lessons/Lesson_1.c
        Lessons/Lesson_2.c
        Lessons/Lesson_3_Testers.c
        functions.c
        Lessons/Lesson_4.c
        Lessons/Lesson_5.c
        Lessons/Lesson_6.c
        sorts.c)
