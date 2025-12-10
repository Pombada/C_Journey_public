#ifndef C_JOURNEY_FUNCTIONS_H
#define C_JOURNEY_FUNCTIONS_H

int find_peak_k_range (int array[],int size,int adder);
int find_peak (int array[],int start,int end,int size);
void arr_copy(int *dest, const int *src, const int n);
int find_max_val(int*, int);
int* counting_sort(int*, int);
void insertion_sort(int*, int);
void radix_sort(int*, int);
int detect_digits (int);
int * eves_shuffle(int arr[],int size);



#endif //C_JOURNEY_FUNCTIONS_H