/**
 * @file schedule_priority_rr.cpp
 * @brief Priority round-robin scheduler
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
    Task* t = new Task; // freed in schedule ()
    t->name = strdup(name);
    t->priority = priority;
    t->burst = burst;
    t->og_burst = burst;
    t->start = -1;
    t->end = -1;

    // Insert task sorted by DESCENDING priority
    // >= so that if equal priority lower name executes first
    // purely for aesthetic reasons

    auto it = tasks.begin();
    while (it != tasks.end() && (*it)->priority >= t->priority) {
        advance(it,1);
    }
    tasks.insert(it, t);
}

/**
 * @brief Invoke the scheduler
 */
void Scheduler::schedule() {
    std::cout << "Priority RR Scheduler running!" << std::endl;
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
            // Insert task sorted by DESCENDING priority
            // >= so that if equal priority lower name executes first
            // purely for aesthetic reasons

            auto it = tasks.begin();
            while (it != tasks.end() && (*it)->priority >= t->priority) {
                advance(it,1);
            }
            tasks.insert(it, t);
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