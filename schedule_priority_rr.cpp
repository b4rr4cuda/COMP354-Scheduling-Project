/**
 * @file schedule_priority_rr.cpp
 * @brief Priority round-robin scheduler
 */

#include <iostream>
#include "schedulers.h"

/**
 * @brief Add a task to the list
 * @param name Name of the task
 * @param priority Priority of the task
 * @param burst Burst time of the task
 */
void Scheduler::add(const char *name, const int priority, const int burst) {}

/**
 * @brief Invoke the scheduler
 */
void Scheduler::schedule() {
    std::cout << "Priority RR Scheduler running!" << std::endl;
}