//
// Created by Noam on 11/11/2025.
//
#include "Lesson_4.h"
//Node *head = NULL; // notice we made the head global
#include <stdlib.h>
/* There is a difference in syntax of declarations of pointers, For example: int *x[5] != int (*x)[5].
 * The former states that x is an array of 5 pointers. While the latter basically means that x is a pointer
 * to an array of 5 chars, another example int *const x[5] = An array of 5 const pointers to an int
 * const int *x[5] = an array of 5 pointers to const int, int *(*x[5])[10][13]
 * in this case x is an array of 5 pointers to an array of 10 elements where each has 13 pointers from int type.
 * (pain in the ass i know), but in general, search for an identifier, then start going left, in case there are
 * parentheses go right to check what they are meant for, then again left. The usual decryption direction
 * is from right to left. */

/* better practice when we allocate a full dynamic array is to mention in the allocation a dereferencing
 * to the pointer type example provided in function array alloc*/
int** array_alloc() {
 int** example = malloc(5 * sizeof(*example));
 if (example == NULL) {
  return NULL;
 }
 for (int i = 0; i <5; i++) {
  example[i] = malloc(5 * sizeof(**example));/*in this case if we decided that now example is a pointer
  to a double suddenly everything will be alright */
  if (example[i] == NULL) {
   free(example);
   return NULL;
  }
 }
 int** bad_example = malloc(5 * sizeof(int*));
 if (bad_example == NULL) {
  free(example);
  return NULL;
 }
 for (int i = 0; i <5; i++) {
  bad_example[i] = malloc(5 * sizeof(int**));
  if (bad_example[i] == NULL) {
   free(example);
   free(bad_example);
   return NULL;
  }
 }

}
// 1d arrays are always pass as pointers so int *p = int a[] = int a[num] (num is ignored)

/* now we will use pointers to dereference and access struct values at the same time.*/
Vec add_vec(Vec a, Vec b) {
 Vec c;
 a.arr[0]=5;
 a.arr[1]=4;
 a.parr = a.arr;
 b = a;
 *b.parr = 9;//now what we did was to change the value of a.arr[0] = 8! notice that!!!
 *(b.parr+1) = 3;//now we changed the value of a.arr[1] to 3 using pointer arithmetics!
 c.arr[0]=a.arr[0]+b.arr[0];
 c.arr[1]=a.arr[1]+b.arr[1];
 c.parr = c.arr;
 return c;
}
//another good practice is to have a function that its soul purpose is to initialize the struct so for example
Vec initialize_vec(int *array_vals,const int size){
 Vec result;
 for (int i = 0; i < size; i++) {
  result.arr[i]=array_vals[i];
 }
 result.parr = result.arr;
 return result;
}
// now we will talk a little bit about linked lists. (go to the first lines to see I defined a global head)

// this function takes a node and adds another link to it
// void push_to_list (int new_data)
// {
//  Node* new_node = malloc(sizeof (*new_node));//creates enough space for a Node struct
//  new_node->data = new_data;//assigns the data for the new node by given func value
//  new_node->next = head;//on the first time it points on null because thats what the head points too
//  head = new_node;//makes the head point on the new node
// }/* visually you can see it like this: pre-function activation head-->NULL
// * after function activation head-->next_node-->NULL */

/*here lie's the issue with a global head, first you can only have 1 linked list with that, (since its global)
 * now if we were to create a local head we were needed to change the push to list function so here's
 * the fixed one */
void push_to_list_local_head (Node **head,int new_data) {
 Node* new_node = malloc (sizeof (*new_node));
 new_node->data = new_data;
 new_node->next = *head;
 *head = new_node;
}
void delete_list (Node **head)
{
 Node *temp = *head;
 while(temp != NULL) {
  Node *next = temp->next;
  free(temp);
  temp = next;
 }
 *head = NULL;
}
void add_one(int *x)/*If you want a function to change a variable from outside of it, you must pass
* the address of the variable from outside and deal with it with a pointer on the function itself (see
* example on main with this particular function */
{
 ++*x; // or (*x)++;
}

