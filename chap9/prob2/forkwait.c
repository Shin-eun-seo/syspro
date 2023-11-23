#include <sys/types.h> 
#include <stdio.h>
#include <stdlib.h>

int main() 
{
   int pid, child, status;
   printf("[%d] Parental process START \n", getpid( ));
   pid = fork();
   if (pid == 0) {
      printf("[%d] Child process START \n", getpid( ));
      exit(1);
   }
   child = wait(&status); 
   printf("[%d] Child Process %d end \n", getpid(), child);
   printf("\t end code %d\n", status>>8);
}

