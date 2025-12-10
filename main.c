#include <stdio.h>
#include "Lessons/Lesson_3_Testers.h"
#include "functions.h"
#include "Lessons/Lesson_4.h"
#include "Lessons/Lesson_5.h"
int potato; //this is a global variable, It dies once the program dies only his default value is 0
/* Five layers of memory
 * 1. Stack - scopes
 * 2. Free space - no idea wtf is this
 * 3. Heap - allocated memory, can be controlled and freed with the command free
 * 4. Data - this is global and static variables
 * 5. Code - the actual text dies when the program dies. */

int main(void) {
    int array2[] = {1,3,2,4,3};
    int size2 = sizeof(array2)/sizeof(array2[0]);
     int array[] = {9,17,16,20,3};
     int size = sizeof(array) / sizeof(array[0]);
    // try_maloc();
    // seg_err_demo();
    // printf("%d",potato);
    // seg_err_demo2();
    insertion_sort(array,size);
    for (int i =0; i < size; i++) {
        printf("array[%d] = %d\n",i,array[i]);
    }
    int* result = counting_sort(array2,size2);
    for (int i = 0; i < size2; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    //pointers now (Lesson_4!)
    Node *head = NULL;
    int x = 5;
    add_one(&x);
    printf("%d\n", x);//expected 6
    int *foo_tester[3][2];
    foo1(foo_tester);
    printf("%llu\n", sizeof(foo_tester)); /* here we want the overall size of foo_tester now since
    we know it's an array of pointers from type int of the size 3x2 we get that each pointers size is 8x3x2 = 48 */
    int a = 5, b = 10;
    double f = 1.0, g = -1.0;
    gswap (&a, &b, sizeof (int));
    gswap (&f, &g, sizeof (double));
    printf("%d\n",a); // it worked (it better be lol)!
    // we can also swap pointers to string literals!
    char *hello_ptr = "hello", *goodbye_ptr = "good-bye";
    gswap (&hello_ptr, &goodbye_ptr, sizeof (char*));
    printf("%s\n",hello_ptr); // you can also swap literal strings char by char.
    eves_shuffle(array2,size2);
    return 0;
}