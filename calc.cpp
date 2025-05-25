//
// Created by Sofya Fedkina on 25/05/2025.
//

#include "calc.h"


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
        int waiting = t->end - t->burst;     // turnaround - burst
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
