#ifndef C_JOURNEY_LESSON_5_H
#define C_JOURNEY_LESSON_5_H
#include <stdbool.h>
#include <stdlib.h>
#include "Lesson_4.h"

bool gswap (void *pa, void *pb, size_t num);
typedef struct Node_b Node_b;
Node_b* newNode_b(int data);
typedef struct StrStackLink StrStackLink;
typedef struct StrStack StrStack;
StrStack* str_stack_new();
void foo1(int *arr[][2]);
int str_stack_is_empty(StrStack const*);
char* str_stack_pop (StrStack* stack);
bool push (Node** head,int d);
int pop (Node**);
void delete_list (Node** head);
void print_list (Node* head);






#endif