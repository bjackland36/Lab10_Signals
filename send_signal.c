/**
 * File: send_signal.c
 * Modified by: Blake Ackland
 * 
 * Brief summary of program:
 */
 #include <signal.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Error: use form '%s <pid>'\n", argv[0]);
        return 1;
    }

    pid_t pid = (pid_t)atoi(argv[1]);
    srand(time(NULL));

    union sigval value;
    value.sival_int = rand();

    printf("Random number: %d\n", value.sival_int);

    if (sigqueue(pid, SIGUSR1, value) < 0) {
        perror("sigqueue");
        return 1;
    }

    printf("Sent SIGUSR1 with value %d to PID %d\n", value.sival_int, pid);
    return 0;
}