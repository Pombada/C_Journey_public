#define DECLARE_FUNC(func, struct_name, StructName) \
void struct_name##func (StructName **prefix)
#include "Lesson_4.h"
typedef struct LinkedList{
    char *str;
    Node *head;
}LinkedList;

#include "Lesson_6.h"
/* in this Lesson we will talk about compilation in C we will start from the first stage Preprocessor
 * Compiler, Linker. Each is a program which processes the output of his former the preprocessor is not
 * a part of the compiler it's a separate step in the compilation process, and it's a text substitution tool.
 * Compilation is the process where we create source code file.
 * Linking creates a single executable file from multiple object files kind of like what we do when we say
 * gcc -blah -blah blah file1.c file2.c ....
 * The preprocessor Does not know c language rules (too bad for him, he is truly misses out lol) he removes comments
 * expands macros includes header files controls conditional compilation.
 * gcc is called the compiler, although it runs the preprocessing and optionally linking.
 * for example if we run gcc hello.c -o hello
 * what we just did was to send hello.c to the preprocessor it created a C code file that was sent to the compiler
 * he created hello.o object that was sent to the linker along with stdio.h and the executable file was Hello
 * what the compiler does is to create an object file for each code file e.g. .c files, and it turns it into .o
 * files so it takes all its references and headers and combines it into one file per .c file.
 * The linker is a special guy, he takes all the .o files we just made with the compiler and combines
 * them into a single executable, */

/***testing! we can test what the preprocessor does by typing gcc -E hello.c it will print the C code after running
the preprocessing stage there it reads all our #includes and crap like that we defined at the early stage of
the project note that this is case-sensitive File =! file he also does the substitutions for macros crafty little
bugger that's for sure so if we defined a macro named THREE and defined his value to be 3 then somewhere along
the code lines we defined a long long why_not_long_long = THREE the preprocessor will just make the
why_not_long_long = 3 so the compiler will understand what is going on, and we can see that if we just do
gcc (file_name) -E, lets put it to the test!***/
DECLARE_FUNC(_new,list,LinkedList);
DECLARE_FUNC(_free, list, LinkedList);
//this is the equivalent of void list_new (LinkedList **list); void list_free (LinkedList **list);
// which is kinda cool (notice the definition I did at the top for the macros).

//closing condition to preprocessor is #endif (this is the shit I always see at my header) #ifndef also is made
// to protect your file from over including of same header file twice or more.

/* ASSert you read that right!, we will talk about the benefits of using it,
 * for example when we want to find the sqrt of something we want that value to not be a minus (since you
 * can't find sqrt of a negative number) hence we will assert x>=0 if its false then we have a problem
 * and our code will warn us about this issue. It's good to use it for debug only since we have the program
 * user can't do anything about this issue. We will not use it to check malloc or user input issues!
 * since it's a world stage problem and not our problem as developers these are edge cases we will need to think
 * of different solutions for.
 * NDEBUG - this is a flag that disables all the assertions you do at compile time basically everytime you
 * type in assert(some_condition) it's not being checked once you enable that flag this is an important thing
 * to remember because in case we called a function, and we want to use the function for something
 * then using assert(function_name() == 0) will not be useful after we use NDEBUG since the function will never be
 * called, But we can do int check = function_name(); assert (check == 0) and now we will always call the function
 * we can compile with gcc blah.c -DNDEBUG -o bullshido.exe that's equivalent to basically #define NDEBUG
 * at the beginning of the file.  */


/*Error handling - we can make function that print the errors or terminate the program, using exit() but when you are using this
 *you need to remember to close files and free memory. And it also terminates the program in case of exception which is not preferred in our
 *course there are a few ways to handle failures of functions, the common conventions are by returning 1,-1 or define macros that represent
 * 1 and 0 and define them as EXIT_SUCCESS/FAILURE or using bool values */
void perror(const char *str); // this prints a descriptive error message to stderr based on global system variable errno, preceded by str
char *strerror(int errnum); //this one searches an internal array for the system error number errnum and returns a pointer to an error message string






