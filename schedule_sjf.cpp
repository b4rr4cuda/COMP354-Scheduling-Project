/**
 * @file schedule_sjf.cpp
 * @brief Shortest-job-first scheduler
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
    t->start = 0;
    t->end = 0;

    // Insert task sorted by ASCENDING time
    // if equal time lower name executes first


    auto it = tasks.begin();
    while (it != tasks.end() && (*it)->burst <= t->burst) {
        advance(it,1);
    }
    tasks.insert(it, t);
}

/**
 * @brief Invoke the scheduler
 */
void Scheduler::schedule() {
    std::cout << "SJF Scheduler running!" << std::endl;
    while (!tasks.empty()) {
        Task* t = tasks.front(); // get the first-in task
        t->start = current_time;
        run(t, t->burst);        // FCFS: run full burst
        tasks.pop_front();       // remove from the list
        current_time += t->burst;
        t->end = current_time;
        finishedTasks.push_back(t);
    }
    calculateAverages(finishedTasks);
    // Clean up after finishedTasks operation
    for (Task* t : finishedTasks) {
        free(t->name);
        delete t;
    }
    finishedTasks.clear();
}
