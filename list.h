/**
 * @file list.h
 * @brief List header
 * THIS FILE IS ADAPTED FROM
 * https://github.com/greggagne/osc10e/blob/master/ch5/project/posix/list.h
 * BY:
 * - renaming delete to del as delete is reserved!
 * list data structure containing the tasks in the system
 */
#pragma once

#include "task.h"

struct node {
    Task *task;
    struct node *next;
};

// insert and delete operations.
void insert(struct node **head, Task *task);
void del(struct node **head, Task *task);
void traverse(struct node *head);
