/**
 * File: recv_signal.c
 * Modified by: Blake Ackland
 * 
 * Brief summary of program:
 */

 #include <signal.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
  
 void handle_signal(int sival_int) {
     printf("Value of sival_int: %d\n", sival_int);
     exit(1);
 }
 
 int main() {
     //sigaction struct
     struct sigaction sa = {
         .sa_handler = handle_signal,
         .sa_flags = 0
     };
 
     if (sigaction(SIGUSR1, &sa, NULL) < 0) {
         perror("sigaction");
         exit(1);
     }
     while (1)
     {
         //Infinite loop
     }
     return 0;
 }