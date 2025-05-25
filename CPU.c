/**
 * @file CPU.c
 * @brief Simulating CPU implementation
 *
 * THIS FILE IS ADAPTED
 * https://github.com/greggagne/osc10e/blob/master/ch5/project/posix/CPU.c
 * "Virtual" CPU that also maintains track of system time.
 */

#include <stdio.h>
#include "task.h"

// run this task for the specified time slice
void run(const Task *task, const int slice) {
    printf("Running task = [%s] [%d] [%d] for %d units.\n",task->name, task->priority, task->burst, slice);
}
