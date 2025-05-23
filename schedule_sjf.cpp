/**
 * @file schedule_sjf.cpp
 * @brief Shortest-job-first scheduler
 */

#include <iostream>
#include "schedulers.h"

/**
 * @brief Add a task to the list
 * @param name Name of the task
 * @param priority Priority of the task
 * @param burst Burst time of the task
 */
void Scheduler::add(const char *name, const int priority, const int burst){}

/**
 * @brief Invoke the scheduler
 */
void Scheduler::schedule() {
    std::cout << "SJF Scheduler running!" << std::endl;
}
