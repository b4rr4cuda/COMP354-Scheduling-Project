/**
 * @file driver.cpp
 * @brief Entry file.
 *
 * THIS FILE IS ADAPTEDFROM
 * https://github.com/greggagne/osc10e/blob/master/ch5/project/posix/driver.c
 * BY:
 * - Changing includes to standardized CPP headers
 * - Including guards when running with no arguments to prevent segmentation faults
 * - Changed NULL to nullptr
 * - Rewrote loop for robustness
 * - Added consts
 * - Joined declarations and assignments where appropriate
 * - Added DoxyGen
 * - Refactoring
 *
 * Schedule is in the format
 * [name] [priority] [CPU burst]
 */


#include <cstdio>
#include <cstring>
#include "schedulers.h"

#define SIZE    100


/**
 * @brief Main function
 * @param argc
 * @param argv
 * @return
 */
int main(const int argc, char *argv[])
{
    char *temp;
    char task[SIZE];

    Scheduler scheduler;

    // guard to prevent segfaults if no arguments provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s schedule.txt\n", argv[0]);
        exit(1);
    }
    // end of guard

    FILE *in = fopen(argv[1], "r");

    // guard to prevent errors if no file
    if (!in) {
        perror("Could not open input file");
        exit(1);
    }
    // end of guard

    while (fgets(task,SIZE,in) != nullptr) {
        temp = strdup(task);
        if (!temp) continue; //guard

        char *name = strsep(&temp, ",");
        char *priority_str = strsep(&temp, ",");
        char *burst_str = strsep(&temp, ",");

        if (!name || !priority_str || !burst_str) {
            fprintf(stderr, "Malformed line: %s\n", task);
            free(temp);
            continue;
        }

        int priority = atoi(priority_str);
        int burst = atoi(burst_str);

        scheduler.add(name, priority, burst);

        free(temp);
    }

    fclose(in);

    // invoke the scheduler
    scheduler.schedule();

    return 0;
}