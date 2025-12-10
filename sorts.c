//
// Created by Dumbledore on 11/7/2025.
//
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "functions.h"
#include <stdlib.h>
int* counting_sort(int array[], int n) {
    int k = find_max_val(array,n);
    int *c = calloc(k+1,sizeof(int));
    int *b = malloc(sizeof(int)*n);
    for (int x = 0; x < n; x++) {
        c[array[x]] = c[array[x]]+1;
    }
    for (int i = 1; i <= k; i++) {
        c[i] += c[i-1];
    }
    for (int j =n-1; j >= 0; j-- ) {
        int tmp = array[j];
        b[c[tmp]-1] = tmp;
        c[tmp]--;
    }
    free(c);
    return b;
}
void insertion_sort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
        /* rounds for example {9,17,16,20,3};
        round 1  i = 1; array[1] > array[0]
        round 2  i = 2; array[2] !> array[1] then we enter the inner loop
        inner loop round 1 j = 1 array[2] = array[1] {9,17,17,20,3}
        inner loop round 2 j = 0 array[2] > array[0] hence the condition fails
        then we exit the loop and assign the value array[1] = key = 16
        hence we get the array {9,16,17,20,3}
        we continue with this method until the array is sorted.
        */
    }

}
// void radix_sort(int array[], int size) {
//     int sub_size=detect_digits(array[0]);
//     for (int i = 1; i < size; i++) {
//         assert(array[i] < pow(10,sub_size));//if it fails the arrays integers are not with the same amount of digits!
//         }
//     char **checker =  malloc(size*sizeof(char*));
//     if (checker == NULL) {
//         free(checker);
//         printf("Memory Error");
//         return;
//     }
//     for (int i = 0; i < size; i++) {
//         checker[i] = malloc(sub_size*sizeof(char));
//         if (checker[i] == NULL) {
//             for (int j = i - 1; j >= 0; j--) {
//                 free(checker[j]);
//             }
//             free(checker);
//             return;
//         }
//     }
//     for (int i = 0; i < size; i++) {
//          snprintf(checker[i], sub_size, "%d", array[i]);
//     }
// }


