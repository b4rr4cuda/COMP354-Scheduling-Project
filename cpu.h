/**
 * @file cpu.h
 * @brief CPU simulation header
 * THIS FILE IS ADAPTED FROM
 * https://github.com/greggagne/osc10e/blob/master/ch5/project/posix/cpu.h
 * BY:
 * - Adding define guard
 * - Added anti-name mangling
 */

// length of a time quantum
#pragma once
#define QUANTUM 10

#ifdef __cplusplus
extern "C" {
#endif

// run the specified task for the following time slice
void run(Task *task, int slice);


#ifdef __cplusplus
}
#endif
