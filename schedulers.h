/**
 * THIS FILE IS USED ADAPTED FROM
 * https://github.com/greggagne/osc10e/blob/master/ch5/project/posix/schedulers.h
 * BY
 * - Including #pragma once
 */
#pragma once

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// add a task to the list 
void add(char *name, int priority, int burst);

// invoke the scheduler
void schedule();
