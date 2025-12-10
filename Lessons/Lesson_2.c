#ifndef LESSON_2_C
#define LESSON_2_C
#include <stdio.h>
#include <stdlib.h>
#include "Lesson_2.h"
#define MAX_N_IN 32

/*In the first example a[-1] will access the value of the object
* that comes before the array in memory the reason this works like that is
* because in the language c when ordered to find a value of an array that is index
* is -1 (meaning no such index exist) the program will go back to the argument before
* the declaration of the array itself. Hence, we will get 9,
* the same goes for the other argument that prints memory address
* since a points to a[0] in the array by arithmetics we get a-1 = a[-1] in the address
* memory that is the address of the thing that comes before a[0] in the memory addresses
 */
int Lesson_2_tester() {
	// int a[6] = {1,2,3,4,5,6};
	// printf("%d\n" "%p\n", a[-1], a-1);
	// printf("%zu\n" ,sizeof(size_t));
	// printf("%zu\n",sizeof(long double));
	// struct Student
	// {
	// 	char name[100];
	// 	int weight_Kgs;
	// };
	// struct Student student1;
	// strcpy(student1.name,"Johnny the fat kid");
	// student1.weight_Kgs = 400;
	// int y = 5;
	// int*p = &y;
	// int z = *p;
	// printf("%d\n", z);
	// printf("%d\n",*p);
	// char s1[MAX_N_IN] = {0};
	// char s2[MAX_N_IN] = {0};
	// char s_out[] = {0};
	// // Read input:
	// if(!fgets(s1, MAX_N_IN, stdin))
	// {
	// 	return EXIT_FAILURE;
	// }
	// if(!fgets(s2, MAX_N_IN,stdin))
	// {
	// 	return EXIT_FAILURE;
	//
	// }
	// for (int i = 0; i < sizeof(s1)/sizeof(s1[0]); i++){
	// 	s_out[i]= s1[i];
	//
	// }
	// for (int j = 0; j < sizeof(s2)/sizeof(s2[0]); j++){
	// 	s_out[j+(sizeof(s1)/sizeof(s1[0]))]=s2[j];
	// }
	//
	// // Rest of your code:
	// printf("%s", s_out);
	// return EXIT_SUCCESS;
	char s[MAX_N_IN+1];
	if(!fgets(s, sizeof(s), stdin))
	{
		return EXIT_FAILURE;
	}
	unsigned long long x = 0;
	for (int i = 0; i < MAX_N_IN; i++ ){
		if (s[i]=='\n' || s[i]=='\0'){
			break;
		}
		if (s[i]=='1'){
			int counter = 1;
				for (int j = i+1; j < MAX_N_IN;j++){
					if (s[j]=='\n' || s[j]=='\0') {
						break;
					}
					counter *= 2;
				}
				x+=counter;
			}
		}
	printf("%llu", x);
	return EXIT_SUCCESS;
}

/* sizeof is a function in compiling time that can run the biggest argument that the computer can use,
 * therefore we might use it.*/

/* sizeof is only possible in the same scope of the function otherwise its irrelevant since when we transfer
 an array to function we can't get its size as well (has to be pre-transferred) since the array himself
 Isn't being passed but a pointer to him */

/* size_t is a function that its job is to store number of bytes that an object can occupy. 
 * assuming we have an array of long doubles and each takes 16 bytes, and we have i objects
 * we are guaranteed to get a size of i*16 bytes. Hence, size_t guarantees he will be able
 * to represent this size (since our system is 64 bit and size_t max size is 8 byte = 64 bits)
 * we get exactly all possibilities for memory that our os can store. */

/* Struct - a collection of related variables (possibly of
 * different types) grouped together under a single name.
 * (like objects, but without functions). */

// dereferencing- We find the value by using its address, we simply point to a pointer, and then we print them.
// example provided after struct

/* getchar(void) this function gets a char from the keyboard and returns an unsigned int in case of error
 * it returns EOF (or -1) */


/* I would like to dedicate an explnation to this special cursed piece i met in one of my lab excersizes

#include <stdio.h>
#include <stdlib.h>

#define PI 3.141246
#define E  2.718282

void swap(double *a, double *b)
{
printf("Before: a=%.2f, b=%.2f\n", *a, *b);
double tmp = *a;
*a = *b;
*b = tmp;
printf("After:  a=%.2f, b=%.2f\n", *a, *b);
}

int main()
{
double x = PI;
double y = E;
printf("Before: x=%.2f, y=%.2f\n", x, y);
swap(&x,&y);
printf("After:  x=%.2f, y=%.2f\n", x, y);
return EXIT_SUCCESS;
}

the following code works as follows, first on main we send the addresses of x and y
to pre declared pointers a and b, then since we declared in our print f that we expect a double
we ask for Dereferencing this is asking the pointer his content, so we get the actual value of x and y
accordingly, at last we take a tmp value that store original a value (this is x) we assign
a original value (this is x) to y and b original value (this is y) to tmp (which contains x value not
address!) its crucial to note how use of dereferencing works well here, with the use of only * and & symbols
we can rend this algorithm useless. */
#endif