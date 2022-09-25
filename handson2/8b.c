// Name: Kantimahanty Rohit, Roll: MT2022149

// 8b : Write a separate program using signal system call to catch `SIGINT`

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void callback()
{
    printf("\nSignal SIGINT has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t status; // Determines the success of the `signal` call

    status = signal(SIGINT, (void *)callback);
    if (status == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        while(1);
}
