#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


// Declaration of functions from the stack module
extern void push(char *thing2push);
extern char *pop();
extern int isEmpty();


int main(int argc, char *argv[]) {
   int ch;
   int previous_char;
  
   // Initialize previous_char to handle the first character
   previous_char = getchar();


   while ((ch = getchar()) != EOF) {
       if (ch == '<' || ch == '/') {
           previous_char = ch;
       } else if (isalpha(ch)) {
           if (previous_char != '/') {
               char tag[2] = {ch, '\0'};
               push(tag);
           } else {
               // Check if the stack is empty before calling pop
               if (isEmpty()) {
                   printf("NOT Valid");
                   exit(1);
               }
               char *popped = pop();
               if (popped[0] != ch) {
                   printf("NOT Valid");
                   exit(1);
               }
               free(popped);
           }
       }
       // Update previous_char for the next iteration
       previous_char = ch;
   }


   // Check if the stack is empty after processing all characters
   if (!isEmpty()) {
       printf("NOT Valid");
       exit(1);
   } else {
       printf("Valid");
       exit(0);
   }
}

