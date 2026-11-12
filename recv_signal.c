/**
 * File: recv_signal.c
 * Assignment: Lab10 - Signals
 * Modified by: Blake Ackland - section 131 
 * 
 * Brief summary of program: This program waits in an infinite
                             loop for a sigusr1 signal and when
                             the signal is recieved it prints
                             sigval_int and exits.
 */
 #include <signal.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
  
 void handle_signal(int sig, siginfo_t *info, void *ucontext) {
     printf("Value of sival_int: %d\n", info->si_value.sival_int);
     exit(1);
 }
 
 int main() {
     //sigaction struct
     struct sigaction sa = {
         .sa_sigaction = handle_signal,
         .sa_flags = SA_SIGINFO
     };
 
     sigemptyset(&sa.sa_mask);
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