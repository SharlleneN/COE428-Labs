#include <stdio.h>
#include <string.h>
#include <stdlib.h>


static int top = 0;
static char * stack[100];


/**
* pop() removes the top string on the stack and returns it.
*
* If pop() is attempted on an empty stack, an error message
* is printed to stderr and the value NULL ((char *) 0) is returned.
*/


char *  pop()
{
   char * hold;
   if(top != 0){
       hold = malloc(strlen(stack[top - 1])+1);
       strcpy(hold, stack[top-1]);
       free(stack[top-1]);
       top--;
       return hold;
   }
   fprintf(stderr, "The stack is empty");
   return NULL;
}


/**
*  push(thing2push) adds the "thing2push" to the top of the stack.
*
*  If there is no more space available on the Stack, an error
*  message is printed to stderr.
*/
void push(char * thing2push)
{
   if(top < 100) {
       stack[top] = malloc(strlen(thing2push)+1);
       strcpy(stack[top], thing2push);
       top++;
   }
   else
       fprintf(stderr, "The stack is full");
}


/**
* isEmpty() returns a non-zero integer (not necessarily 1) if the
* stack is empty; otherwise, it returns 0 (zero).
*
*/
int isEmpty(){ return top==0; }
