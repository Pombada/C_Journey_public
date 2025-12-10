#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int find_peak_k_range (int array[],int size,int adder) {
    int result = find_peak(array,0,size-1,size);
    for (int i = 2; i < size; i++){
        if (result-i< 0) {
            while (i<size) {
                if (array[result] < array[result+i]) {
                    return adder;
                }
                i++;
                adder++;
            }
            break;
        }
        if (result+i>=size) {
            while (result-i >= 0) {
                if (array[result] < array[result-i]) {
                    return adder;
                }
                i++;
                adder++;
            }
            break;
        }
        if (array[result] >= array[result+i] && array[result] >= array[result-i]) {
            adder++;
        }
        else {
            return adder;
        }

    }
    return adder;
}
int find_peak(int array[],int start,int end,int size) {
    int i = (start+end+1)/2;
    if (i == size-1 && array[i] >= array[i-1] ) {
        return i;
    }
    if (i == 0 && array[i]>=array[i+1]) {
        return i;
    }
    if (array[i] >= array[i-1] && array[i] >= array[i+1]) {
        return i;
    }
    if (array[i-1] <= array[i]) {
        return find_peak(array,i+1,end,size);
    }
    return find_peak(array,start,i-1,size);
}

int find_peak_in_matrix(int size,int array[][size]) {
    for (int col = 0; col<size; col++) {
        for (int row = 0; row<size; row++) {
            int top_check = '0';
            int bottom_check = '0';
            int right_check = '0';
            int left_check = '0';
            if (col != 1) {
                left_check = (array[col][row]>=array[col-1][row]);
            }
            if (col != size - 1) {
                right_check = (array[col][row]>=array[col+1][row]);
            }
            if (row != size - 1) {
                bottom_check = (array[col][row]>=array[col][row+1]);
            }
            if (row != 1) {
                top_check = (array[col][row]>=array[col][row-1]);
            }
            if (top_check && bottom_check && right_check && left_check) {
                return array[col][row];
            }
        }
    }
}
int find_max_val(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
} // finds max value in array and returns it

void arr_copy(int *dest, const int *src, const int n)
{
    int* i = src;
    for (int j; j < n ; j++){
        dest[j] = i[j];
    }
} //function gets a destination and a source and copies the array from source to destination (without changing anything
// about the src!
int detect_digits(int first_num) {
    int digit_counter = 1;
    while (first_num/10!=0) {
        first_num = first_num/10;
        digit_counter++;
    }
    return digit_counter;
}


int * eves_shuffle(int arr[],const int size){
    if (size <= 1) {
        printf("Array is size 1 or under, If it's 1 then eve can't do any shuffle. If it's under 1 then its invalid!\n");
        return NULL;
    }
    int *was_it_shuffled = calloc(size, sizeof(int));
    int *demo_arr = malloc(sizeof(int)*size);
    int **alice_arr = malloc(5*sizeof(int*));
    int *result_arr = malloc(sizeof(int)*size);
    if (!(was_it_shuffled && demo_arr && alice_arr)) {
        free(demo_arr);
        free(was_it_shuffled);
        free(alice_arr);
        free(result_arr);
        printf("Memory allocation failed!\n");
        return NULL;
    }
    for (int i = 0; i < 5; i++) {
        alice_arr[i] = malloc(sizeof(int)*size);
        if (alice_arr[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(alice_arr[j]);
            }
            free(result_arr);
            free(demo_arr);
            free(was_it_shuffled);
            free(alice_arr);
            return NULL;

        }
    }
    memcpy(demo_arr,arr,size*sizeof(int));

    int k = 0;
    for (int shuffle = 0; shuffle <= 4; shuffle++) {
        for (int i = 0; i < size; i+=random()%size ) {
            int camel = random() % size;
            int j = random() % (size-1);
            if (k>size-1) {
                break;
            }
            while (was_it_shuffled[camel]) {
                camel = random() % size;
            }
            was_it_shuffled[camel] = 1;
            k++;
            if (camel > j) {
                int tmp = demo_arr[j+1];
                demo_arr[j+1] = demo_arr[camel];
                demo_arr[camel] = tmp;
            }
            else {
                int tmp = demo_arr[j];
                demo_arr[j] = demo_arr[camel];
                demo_arr[camel] = tmp;
            }

        }
        memcpy(alice_arr[shuffle],demo_arr,size*sizeof(int));
        for (int printer = 0; printer < size; printer++) {
            printf("%d ", alice_arr[shuffle][printer]);
        }
        printf("\n");


    }
    free(was_it_shuffled);
    free(demo_arr);
    for (int j = 0; j < 4; j++) {

        free(alice_arr[j]);

    }
    free(alice_arr);
}
