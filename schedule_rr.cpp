/**
* @file schedule_rr.cpp
 * @brief Round-robin scheduler
 */

#include <iostream>
#include "schedulers.h"
#include "cpu.h"
#include "calc.h"

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
    t->og_burst = burst;
    t->start = -1;
    t->end = -1;
    tasks.push_back(t); // RR: add to the back of the list
}

/**
 * @brief Invoke the scheduler
 */
void Scheduler::schedule() {
    std::cout << "RR Scheduler running!" << std::endl;
    while (!tasks.empty()) {
        Task* t = tasks.front(); // get the first-in task
        if (t->start == -1) t->start = current_time;
        if (t->burst < QUANTUM) {
            run(t, t->burst);  // RR: run for quantum or less
            current_time += t->burst;
            t->burst = 0;
        } else {
            run(t, QUANTUM);
            current_time += QUANTUM;
            t->burst = t-> burst - QUANTUM;
        }

        if (t-> burst <= 0) {
            tasks.pop_front();       // remove from the list
            t->end = current_time;
            finishedTasks.push_back(t);
        } else {
            tasks.pop_front();
            tasks.push_back(t); // re-add task at the end.
        }
    }
    calculateAverages(finishedTasks);
    // Clean up after finishedTasks operation
    for (Task* t : finishedTasks) {
        free(t->name);
        delete t;
    }
    finishedTasks.clear();

}
