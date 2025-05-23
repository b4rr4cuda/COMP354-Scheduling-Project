cmake_minimum_required(VERSION 3.31)
project(COMP354_Scheduling_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(fcfs driver.cpp schedule_fcfs.cpp list.c CPU.c)
add_executable(sjf driver.cpp schedule_sjf.cpp list.c CPU.c)
add_executable(rr driver.cpp schedule_rr.cpp list.c CPU.c)
add_executable(priority driver.cpp schedule_priority.cpp list.c CPU.c)
add_executable(priority_rr driver.cpp schedule_priority_rr.cpp list.c CPU.c)

