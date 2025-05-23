/**
 * THIS FILE IS USED AS-IS FROM
 * https://github.com/greggagne/osc10e/blob/master/ch5/project/posix/cpu.h
 */

// length of a time quantum
#define QUANTUM 10

// run the specified task for the following time slice
void run(Task *task, int slice);
