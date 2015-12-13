// g++ fork5.cpp -o fork5

#include <stdio.h>
#include <unistd.h>

int main()
{
   fork(); /* A */
   ( fork()  /* B */ &&
     fork()  /* C */ ) || /* B and C are grouped according to precedence */
   fork(); /* D */
   fork(); /* E */

   printf("forked\n");
   return 0;
}
