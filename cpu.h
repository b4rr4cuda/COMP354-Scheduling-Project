/**
 * @file cpu.h
 * @brief CPU simulation header
 * THIS FILE IS ADAPTED FROM
 * https://github.com/greggagne/osc10e/blob/master/ch5/project/posix/cpu.h
 * BY:
 * - Adding define guard
 */

// length of a time quantum
#pragma once
#define QUANTUM 10

// run the specified task for the following time slice
void run(Task *task, int slice);
