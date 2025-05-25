/**
* @file calc.cpp
 * @brief Calculations
 */

#include "calc.h"

/**
 * @brief Calculates and prints average turnaround, waiting, and response times for a list of tasks.
 *
 * Assumes all tasks arrive at time zero. Turnaround time is computed as task end time,
 * waiting time as turnaround minus original burst time, and response time as task start time.
 *
 * @param tasks A constant reference to a list of pointers to Task objects representing completed tasks.
 *
 * If the task list is empty, a message is printed indicating no tasks to process.
 */
void calculateAverages(const std::list<Task*>& tasks) {

    if (tasks.empty()) {
        std::cout << "No tasks to process.\n";
        return;
    }

    double total_turnaround = 0.0;
    double total_waiting = 0.0;
    double total_response = 0.0;
    int n = 0;

    for (const Task* t : tasks) {
        int turnaround = t->end;             // since arrival is 0
        int waiting = t->end - t->og_burst;     // turnaround - burst
        int response = t->start;             // since arrival is 0

        total_turnaround += turnaround;
        total_waiting += waiting;
        total_response += response;
        ++n;
    }

    std::cout << "Average Turnaround Time: " << (total_turnaround / n) << "\n";
    std::cout << "Average Waiting Time: " << (total_waiting / n) << "\n";
    std::cout << "Average Response Time: " << (total_response / n) << "\n";
}
