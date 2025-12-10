//
// Created by Noam on 11/11/2025.
//

#ifndef C_JOURNEY_LESSON_4_H
#define C_JOURNEY_LESSON_4_H
typedef struct Vec {
    double arr[10];
    double *parr;
}Vec;
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

#include <stdio.h>
int** array_alloc();
Vec add_vec(Vec a, Vec b);
Vec initialize_vec(int *array_vals,int size);

void push_to_list(int new_data);
void print_list();
void delete_list (Node **head);
void push_to_list_local_head (Node **head,int new_data);
void add_one(int *x);

#endif //C_JOURNEY_LESSON_4_H