/**
 * File: signal_sigaction.c
 * Modified by: Blake Ackland
 * 
 * Brief summary of program:
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
 
void handle_signal(int sig) {
    printf("PID: %d\n", getpid());
}

int main() {
    struct sigaction sa = {
        .sa_handler = handle_signal,    // no additional blocked signals
        .sa_flags = 0,                  // default behavior
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

