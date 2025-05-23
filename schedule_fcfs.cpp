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
    Task* t = new Task;
    t->name = strdup(name); // make a deep copy for safety
    t->priority = priority;
    t->burst = burst;
    insert(&head, t);
}

/**
 * @brief Invoke the scheduler
 */
void Scheduler::schedule() {
    std::cout << "FCFS Scheduler running!" << std::endl;
    struct node* temp = head;
    while (temp != nullptr) {
        run(temp->task, temp->task->burst); // FCFS: run full burst
        temp = temp->next;
    }
}


