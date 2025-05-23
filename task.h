/**
 * THIS FILE IS USED AS-IS FROm
 * https://github.com/greggagne/osc10e/blob/master/ch5/project/posix/task.h
 *
 * Representation of a task in the system.
 */

#ifndef TASK_H
#define TASK_H

// representation of a task
typedef struct task {
    char *name;
    int tid;
    int priority;
    int burst;
} Task;

#endif