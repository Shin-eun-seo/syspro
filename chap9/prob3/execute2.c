#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( ) 
{
   printf("Parental process START\n");
   if (fork( ) == 0) {
      execl("/bin/echo", "echo", "hello", NULL);
      fprintf(stderr,"first dowm"); 
      exit(1);
   }

   if (fork( ) == 0) {
      execl("/bin/date", "date", NULL);
      fprintf(stderr,"Second down"); 
      exit(2);
   }

   if (fork( ) == 0) {
      execl("/bin/ls","ls", "-l", NULL);
      fprintf(stderr,"Three down"); 
      exit(3);
   }
   printf("Parental process end\n");
}


