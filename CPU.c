/**
 * @file CPU.c
 * @brief Simulating CPU implementation
 *
 * THIS FILE IS USED AS-IS FROM
 * https://github.com/greggagne/osc10e/blob/master/ch5/project/posix/CPU.c
 * "Virtual" CPU that also maintains track of system time.
 */

#include <stdio.h>

#include "task.h"

// run this task for the specified time slice
void run(Task *task, int slice) {
    printf("Running task = [%s] [%d] [%d] for %d units.\n",task->name, task->priority, task->burst, slice);
}
