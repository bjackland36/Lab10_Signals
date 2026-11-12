/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
* Assignment: Lab10 - Signals
* Modified by: Blake Ackland - section 131 
 * 
 * Brief summary of modifications:
        removed exit(1) from handle_signal
        SIGINT is now futile. Must use 'kill -9 <pid>' to kill
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal(int sig) {
    printf("\nReceived a signal\n");
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}