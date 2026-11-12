/**
 * File: signal_alarm.c
 * Assignment: Lab10 - Signals
 * Modified by: Blake Ackland - section 131  
 * 
 * Brief summary of program: This program has an alarm scheduled
                            to be sent after 5 seconds. When the alarm goes
                            off, the program tells the user.
 */
 #include <signal.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>

void handle_signal(int sig) {
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