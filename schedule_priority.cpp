/**
* @file schedule_priority.cpp
 * @brief Priority scheduler
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
    Task* t = new Task; // freed in schedule ()
    t->name = strdup(name);
    t->priority = priority;
    t->burst = burst;
    t->start = 0;
    t->end = 0;

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
    std::cout << "Priority Scheduler running!" << std::endl;
    while (!tasks.empty()) {
        Task* t = tasks.front(); // get the first-in task
        run(t, t->burst);        // Priority: run full burst
        tasks.pop_front();       // remove from the list
        free(t->name);
        delete t;
    }
}
