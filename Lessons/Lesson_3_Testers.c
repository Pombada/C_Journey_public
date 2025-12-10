#ifndef LESSON_3_TESTERS_C
#define LESSON_3_TESTERS_C
#include "Lesson_3_Testers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// Pointers and arrays, lets start with some pointers and arrays
void pointer_tester () {
    int array[] = {9,17,16,20};
    int *pa = array;
    printf("this is the first address content %d\n", pa[0]);// as we can see, this prints the thing that
    //is stored in value [0] of our array, now if we want an address only we will just print *pa.
    printf("This is the address itself of the pointer %d\n",pa);
    printf("This is the second address content but we use pointer addition %d\n", *(pa+1));
    //while using pointer addition we can safely say that *(pa + i) == pa[i]
    printf("this is the second address itself using pointer addition %d\n", (pa+2));
    printf("Notice how it is equal to this %d\n" , &array[2]);
    // we can pull the individual addresses in one of few ways. (we can also use subtraction)
    //we can also do arithmetic action on our pointers.
    int *q = pa+2;
    printf("This is another way to present the 2nd address content %d\n", q[0]);
    printf("Now notice that the pointer q contains all of the addresses in pointer pa \n");
    printf(" %d\n",q[0]);
    printf(" %d\n",q[1]);
    printf(" %d\n",q[-1]); /*This might make no sense due to the fact that how this sub array has negative
    * indexes but this is just an address of a sub array that points to the stored values of the pointer pa
    * and starts from the index 2, lets assume for a second that we will continue with same indexes of the pointer
    * pa and will try to access q[3] and 4, we will get garbage value\buggy behaviour.
    * So if we want to access the other indexes of pa we will need to use negative indexes. */
    printf(" %d\n",q[-2]);
    q++;
    printf(" We incremented q by 1 (in int size we actually promoted it in 4 bytes same size as our int"
           " so we jumped in 4 bytes in the memory in arithmetic operation q++ now we expect the third"
           " value in the contents of our pointer pa (when we print *q or q[0]) %d\n\n",*q);
    //We can also subtract among pointers (which is some cool shit) and the result would be an int.
    // for example lets try
    printf("q-pa = %d\n", (q-pa));
    //let's try another (we cant do addition from some reason)
    q++;
    printf("q-pa but now we incremented q by 1 = %d\n", (q-pa));
    printf("is q>pa? = %d\n", (q>pa));
    int *a;
    printf("%zu\n", sizeof(a)); //gives the size of the pointer in bytes
    char *type = (char *)array; // when we assign a pointer a define a type, it moves in memory according to the
    //type size so if we assigned a pointer to int and then added to this pointer 1 we actually added 4 bytes
    // in pointer movement since the pointer is pointing on an int.
    // in this occasion we treat the *type pointer as a char pointer even that he is going to point towards an int
    // we tell him to behave as a char pointer so when we do type++ the type will move 1 byte only.

}
void try_maloc () {
    long *result =malloc(100000000*sizeof(long));
    if (result == NULL) {
        printf("Memory Error\n");
    }
    printf("Address of result is %p\n", result);
}
//de allocating memory: this is a core concept in C language, we don't have a garbage collector in C meaning whatever you don't throw, stays on the program
// until you are done running it. so we will immediately practice memory cleaning function.
//has undefined behaviour in case it wasn't defined by malloc or was already freed
void memory_cleaning() {
    long *tester = malloc(50*sizeof(long));
    free(tester);//good practice to assign it to Null after were done but not necessary in this case since we
    // we are done in the scope in a second.
    //free(non_existent_bullshit); = undefined behaviour
    free(tester);//also undefined behaviour (since we already freed it before)
    // An important rule is to avoid dynamic allocation unless necessary due to it being inefficient.

}
/* segmentation fault - is an error of trying to access memory that is not in our program for example */

void seg_err_demo () {
    int *p;
    int a = *p;
    *p = 4; //wtf is this? you never defined pointer p in the first place so you will get a segmentation error.
}

    /* realloc is a function that reallocates memory to a wanted size (basically if you allocated too much space
     * and you want to minimize it you can do it with realloc) when using realloc we would like to
     *  make the allocations in a different variable, for example if we have
     *  int* boom = malloc(size,sizeof(size)*3);
     *  if we did boom = realloc(boom,boom*4);
     *  this will cause an issue in case of failure on realloc due to realloc returns NULL upon failure
     *  and now we basically lost access to the memory content of boom so we can't free it and
     *  we just caused a memory leak so always use another variable so in case of failure on that we can
     *  free boom without any issues.
     */

	/*notice the following block of code char *strdup (const char *s)
    {
     // Reserve space for string + ‘\0’
     char *d = malloc (strlen (s) + 1);
     if (d == NULL)
     {
     return NULL; // No memory
     }
     strcpy (d, s); // Copy the characters
     return d; // Return the new string
    }  this code seems like he returns a pointer but we said we will never return stack pointers cause it wont work
     we will always get an error, but notice careful that once we allocated using malloc we accessed the heap!
     and not the stack itself that means that char *d will take program space until we will free it (and it will
    continue to take space after the scope ends as well!) */


	// heres another mistake we would never like to make
	void foo (char const* p)
    {
         char *q = strdup (p);
         // do something with q
    }
/*
 strdup is a function like malloc it allocates memory and gives the ownership to char *q but if we notice here
we never return it, hence once the stack ends the char *q is dead but the memory is staying allocated and we
won't be able to free it, beware of such mistakes! this is an immidete memory leak, something we will try to avoid
at all cost! */
// so our options are as followed, either free it or use a function that returns something!


/* static variables stay until the program dies and we can declare them as follows: static some_name;
 * default static value is 0
*/
//same about globals

/*Crucial point! string literals are being kept in a read only section of the data that means that if you
 *will try to access them during your code you will get a segmentation error, for example. */
void seg_err_demo2() {
    char *msg ="text"; /*hence It's a good practice to declare them as const and when we will try to execute the
    * next line it will just give us compilation error (runtime error gives on some compilers a weird exit code
    * better to just stop it from executing at first */
    msg[0]='w'; //runtime error baby (segmentation one too)
    const char *msg2 = "pomba";
    //msg2[0]='4'; //that's a   compilation error right there
}
/* how to copy a string?
{
const char *p1 = "hi mom“; // data seg.
char *p2 = malloc (strlen(p1) + 1); // heap, also remember to make space for '\0'
strcpy (p2, p1);
printf ("%s\n", p2);
free (p2)
return 0;
}
*/
#endif // LESSON_3_TESTERS_C;
