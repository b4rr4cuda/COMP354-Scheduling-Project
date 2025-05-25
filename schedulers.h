/**
* @file schedulers.h
 * @brief Header file for schedulers
 * THIS FILE IS ADAPTED FROM
 * https://github.com/greggagne/osc10e/blob/master/ch5/project/posix/schedulers.h
 * BY
 * - Including #pragma once
 * - Using a singleton class pattern
 * - Replacing C linked list with std::list<Task*>
 * (consulted https://www.geeksforgeeks.org/singleton-pattern-c-design-patterns/ for
 * singleton pattern)
 */

#pragma once
#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

#include <list>
#include "task.h"

/**
 * @class Scheduler
 * @brief Singleton scheduler class for managing tasks using std::list
 */
class Scheduler {
public:
    // Delete copy constructor and assignment operator
    Scheduler(const Scheduler&) = delete;
    Scheduler& operator=(const Scheduler&) = delete;

    /**
     * @brief Get the singleton instance of Scheduler.
     * @return Reference to the Scheduler instance.
     */
    static Scheduler& getInstance() {
        static Scheduler instance;
        return instance;
    }

    /**
     * @brief Add a task to the scheduler's queue.
     * @param name Name of the task.
     * @param priority Task priority.
     * @param burst CPU burst time.
     */
    void add(const char* name, int priority, int burst);

    /**
     * @brief Run the scheduler.
     */
    void schedule();

private:
    Scheduler() = default; // private constructor
    std::list<Task*> tasks{};
    std::list<Task*> finishedTasks{};
    int current_time = 0;
};
