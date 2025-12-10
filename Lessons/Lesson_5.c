#include "Lesson_5.h"
#include <stdio.h>
#include <assert.h>
struct Node_b{
    Node_b* right;
    Node_b* left;
    int data;
};


//! push data to head and update head
//! @return true iff successful
bool push (Node** head,int d){/* Notice that when we make changes in the head we pass a pointer to that pointer, the reason for that is because if we were to
    pass the Node* head directly we were just sending a copy of the header and all the changes we were making wouldn't affect the original hence we sent
    a pointer to that address so when we dereference it we address the content that is outside the function hence we change the value inside these pointers! **/
    Node *new_guy = malloc(sizeof(Node));
    if (!(new_guy)) return false;
    (new_guy) -> data = d;
    (new_guy) -> next = *head;
    *head = new_guy;
    return true;
}

//! pop data from head and update head
int pop (Node** head){
    Node* temp = *head;
    int result=(*head) -> data;
    *head = temp -> next;
    free(temp);
    return result;
}



//! print the list according to the example above
void print_list (Node* head){//notice here we sent a Node* instead of Node** the reason is because we Don't make any changes! we just want the data!!!
    Node *runner = head;
    while (runner){
        printf("%d ",runner->data);
        runner = runner->next;
    }
    printf("\n");
}


//Here we will give some nice examples and plays with pointers.
void foo1(int *arr[][2]){
    printf("%llu,%llu,",sizeof(*arr),sizeof(**arr));
    /* since arrays decay to pointers once we send them to functions we actually get int *(*arr)[2] which is
     * a pointer named arr to an array of 2 pointers from type int so we have arr --> [{-->int,-->int}]
     * sizeof(*arr) is a dereference to the array content (in our case its 2 pointers) so knowing each pointer
     * size is 8 bytes we get 16 bytes in total. sizeof(**arr) is a dereference to the first element of our array
     * in our case it's a pointer from type int and its weight is 8 bytes hence we get 8 */
}

Node_b* newNode_b(int data) {
    Node_b* newNode = (Node_b*)malloc(sizeof(Node_b));
    if (!newNode) {
        printf("Allocation for newNode in function newNode_b failed, returning NULL");
        return NULL;
    }
    newNode ->left = NULL;
    newNode -> right = NULL;
    newNode -> data = data;
    return newNode;
}
/* supreme knowledge bonus: the character '\0' in ascii is 0, why it's useful for us? because when someone will ever write
 *strcat(char *dest, const char *src){
 * while (*dest) dest++;
 * while (*dest = *src);
   } the amazing thing over here is that at a first glance our 2nd while is seemed like there is no stopping condition but the truth is
   * that the end of the src array of chars is always '\0' meaning its 0 in ascii value! and any other value is bigger than 0 therefore
   * we actually get that the condition fails when src is reaching to its end, it's an amazing thing!*/

/* In this lesson we will want to start with program design and weak ownership, e.g a definition of set of functions
 * that provide coherent module (or library) example for this is StrStack a module that allows a stack of strings
 * and includes 4 operations New,Push/Pop,IsEmpty,Free.
 * stack is LIFO (last in first out) we will also discuss a weak ownership this occurs for example when
* we define a struct looks like this:*/
 typedef struct StrStackLink
{
char* str; // weak ownership
struct StrStackLink *next;
} StrStackLink;
/* weak ownership is when we are taking the power of allocation, freeing or anything like that from the strcut
* and giving it to something else that happen behind the scenes, the struct has no responsibility to free the
* memory.
* now we will also define this */
typedef struct StrStack
{
StrStackLink* top;
} StrStack;
StrStack* str_stack_new()
{
    StrStack* stack = malloc (sizeof (StrStack));
    if (stack != NULL)
    {
        stack->top = NULL;
    }
    return stack;
}
// this is a linked list as we will define the base in h
//this is deallocation
void str_stack_delete (StrStack** stack)
{
while (!str_stack_is_empty (*stack))
{
str_stack_pop (*stack);
}
free (*stack);
*stack = NULL;
}
int str_stack_is_empty (StrStack const* stack)//checking if the stack itself is empty
{
    assert (stack != NULL);
    return stack->top == NULL;
}
void str_stack_push (StrStack* stack, char* s) {
    assert (stack != NULL);
    StrStackLink *p = malloc(sizeof(StrStackLink));
    if (!p)
    {
        printf("out of memory, cannot push a string to the stack\n");
        return;
    }
    p->str = s; // we do not duplicate ‘s’ – weak ownership
    p->next = stack->top;
    stack->top = p;
}
char* str_stack_pop (StrStack* stack)
{
    assert (stack != NULL);
    if (stack->top == NULL)
        return NULL; // not GNU style!
    char *s = stack->top->str;
    StrStackLink *p = stack->top;
    stack->top = p->next;
    free(p);
    return s;
}
/*assigning to a void pointer you can assign void* in the following way short* s = malloc(sizeof(short)*10)
 *void* w = &s this is something you cant do with other variables! but you can't use pointer arithmetic
 *operations in opposition to a normal pointers, also you can assign pointers to a void* type and vice verse */


/* The function memcpy, it's a function that copies a block of memory of specified size from one address to
 * another address it has no idea what type of variable it copies hence we have an issue
 * since it basically returns a void pointer we can't iterate over it and we can't do dereferencing
 * we can use memcpy to also swap an address with the help of malloc and without malloc, anyway
 * without malloc we will use the fact that char is a 1 byte then with that knowledge we can jump on pointers with sizes of arrays
 * for example: */
bool gswap (void *pa, void *pb, size_t num) {
    char * pa_char = pa; // implicit cast from void*
    char * pb_char = pb;
    char *end_a = pa_char + num;
    while (pa_char != end_a)
   {
    char tmp_char = *pa_char;
    *pa_char++ = *pb_char;
    *pb_char++ = tmp_char;
    }
    return true;
}
/* pointers to functions! (surprise) its possible, for example: int (*fun) (int) this is a pointer to a function
 * that gets int as an argument and returns an int as well if we remove the parentheses around the fun we just get
 * int *fun (int) which now is just a function that get an int and returns an int pointer. */

/* another important thing with function pointers here we can see something interesting:
 */ /**float (*get_ptr1 (const char op)) (float, float)**/ /* What does this mean?
 * well get_ptr1 is a function that gets a const char op and returns a pointer to a function that gets 2 floats
 * and returns a float! */


