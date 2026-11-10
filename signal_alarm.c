/**
 * File: signal_alarm.c
 * Modified by: Blake Ackland
 * 
 * Brief summary of program:
 */
 #include <signal.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>

void handle_signal(int sig) {
    (void)sig;
    printf("Alarm!!\n");
    exit(1);
}


 int main()
 {
    signal(SIGALRM, handle_signal);

    alarm(5);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
 }