/**
 * @file schedule_fcfs.cpp
 * @brief First-come first-serve scheduler
 */


#include <iostream>
#include "schedulers.h"
#include "cpu.h"

/**
 * @brief Add a task to the list
 * @param name Name of the task
 * @param priority Priority of the task
 * @param burst Burst time of the task
 */
void Scheduler::add(const char *name, const int priority, const int burst) {
    Task* t = new Task; // freed in schedule()!
    t->name = strdup(name); // make a deep copy for safety
    t->priority = priority;
    t->burst = burst;
    tasks.push_back(t); // FCFS: add to the back of the list
}

/**
 * @brief Invoke the scheduler
 */
void Scheduler::schedule() {
    std::cout << "FCFS Scheduler running!" << std::endl;
    while (!tasks.empty()) {
        Task* t = tasks.front(); // get the first-in task
        run(t, t->burst);        // FCFS: run full burst
        tasks.pop_front();       // remove from the list

        free(t->name);
        delete t;
    }
}


