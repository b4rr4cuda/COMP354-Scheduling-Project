/**
* @file schedulers.h
 * @brief Header file for schedulers
 * THIS FILE IS ADAPTED FROM
 * https://github.com/greggagne/osc10e/blob/master/ch5/project/posix/schedulers.h
 * BY
 * - Including #pragma once
 * - Using a class pattern
 * - Replacing C linked list with std::list<Task*>
 */

#pragma once
#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

#include <list>
#include "task.h"

/**
 * @class Scheduler
 * @brief Scheduler class for managing tasks
 */
class Scheduler {
public:
    Scheduler() = default;

    // Disable copying to avoid accidental duplication
    Scheduler(const Scheduler&) = delete;
    Scheduler& operator=(const Scheduler&) = delete;

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
    std::list<Task*> tasks{};
    std::list<Task*> finishedTasks{};
    int current_time = 0;
};
