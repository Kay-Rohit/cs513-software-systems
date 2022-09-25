// Name: Kantimahanty Rohit, Roll: MT2022149
// 8d : Write a separate program using signal system call to catch `SIGALRM` (use `alarm` system call)

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void callback()
{
    printf("Signal SIGALRM has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t status; // Determines status of `signal` call

    alarm(1); // Set an alarm for 1s

    // Catch the SIGALRM signal
    status = signal(SIGALRM, (void *)callback);
    if (status == SIG_ERR)
        perror("Error while catching signal!");
    else
        while (1);
}
