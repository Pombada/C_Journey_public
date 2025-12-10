#include <stdio.h>
#include <stdlib.h>
/* My machine size for different variables types (In bits).
 * char = 1
 * short = 2
 * int = 4
 * float = 4
 * long = 4
 * double = 8
 * long long = 8
 * long double = 16
 */
void mult(int);
int fibonacci(int);
int Find_peak_ind(int array[],int size);
int Find_peak_ind_rec(int array[]);

int crap(void) {
    printf("Hello, World!\n");
    int x = 1;
    {
        int x = 3;
        printf("x=%d\n", x);
    }
    printf("x=%d\n",x);
    x = 45;
    printf("x=%d\n",x);
    mult(6);
    int h=sizeof(long);
    printf("h=%d\n",h);
    int arr[] = {1,3,4,60};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Peak has been found on this index %d\n",Find_peak_ind(arr,size));
    printf("Peak of the recursive function is in index %d\n", Find_peak_ind_rec(arr));

    return EXIT_SUCCESS;
}
void mult(int x){
    for (int i = 1;i <= x;i++){
        for (int j = 1; j <= x; j++){
            printf("%d ",i*j);
            }
        printf("\n");
        }
}
int fibonacci (int n)
{
    int f0 = 0;
    int f1 = 1;
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    int result = 0;
    for (int i = 1; i<n; i++){
        result = f0+f1;
        f0 = f1;
        f1=result;

    }
    return result;
}

/* Lesson 1 - tips:
 * we can run the program on university computers we need to run
 * > gcc hello.c
 * > ./hello
 * the 12 line is the file name, the 11 line is the compilation. we can also compile with
 * options for example gcc -std=c99 - wall hello.c-o hello
 * the c99 stands for the compiling standard.
 *
 *
 * Types and variables :
 * C is a static language - meaning you have to declare every type before using it.
 * Python is a dynamic language. The benefits of C lang in this department is that you are
 * able to control the memory bits of your machine what you can't do in python.
 *
 * Arithmetic types: operations +, -, * , /, %, etc...
 * integral types - char: 1 byte, int: size is uncertain changes from machine to machine.
 * float: only affirmative (Real) , double: represents R group
 * Warning: 'A' is different than "A" char can accept also numbers.
 * enum: integer like user defined type.
 * typedef: create custom type.
 * case: something that can be evaluated at compiling time for example case(1+2)
 * he has to get an int.
 * do while: always does first iteration and then checks condition for the loop.
 * const: makes it impossible to change the variable later.
 * to include a library we use: include <library name>
 * to include a file name we use: include "file.name"
 */

//Linear time
int Find_peak_ind(int array[],int size) {
    if (array[0] > array[1]) {
        return 0;
    }

    for (int i = 1; i < size; i++) {
        if (array[i] > array[i+1] && array[i] > array[i-1]) {
            return i;
        }
    }
    if (array[size - 1] > array[size - 2]) {
        return size-1;
    }
}
//Linear time
int Find_peak_ind_rec(int array[]) {
    if (array[0] > array[1]) {
        return 0;
    }
    return 1+Find_peak_ind_rec(array+1);
}
