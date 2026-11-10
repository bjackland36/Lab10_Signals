/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Blake Ackland
 * 
 * Brief summary of modifications: 
            added handle_segfault method

 */

 #include <signal.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>

void handle_segfault(int sig)
{
    (void)sig;
    printf("Seg fault handled\n");
}

int main (int argc, char* argv[]) {

    signal(SIGSEGV, handle_segfault);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}