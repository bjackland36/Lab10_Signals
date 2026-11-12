/**
 * File: signal_sigaction.c
 * Assignment: Lab10 - Signals
 * Modified by: Blake Ackland - section 131 
 * 
 * Brief summary of program: Waits in an infinite loop for a SIGUSR1
                             signal and when SIGUSR1 signal is received,
                            the program prints PID of process and ends.
 * Use 'kill -10 <pid>' to send SIGUSR1
 */ 
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
 
void handle_signal(int sig, siginfo_t *info, void *context) {
    printf("PID of sender: %d\n", info->si_pid);
    exit(1);
}

int main() {
    //sigaction struct
    struct sigaction sa = {
        .sa_sigaction = handle_signal,
        .sa_flags = SA_SIGINFO
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

