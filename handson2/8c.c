// Name: Kantimahanty Rohit, Roll: MT2022149

// 8c : Write a separate program using signal system call to catch `SIGFPE`

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void callback()
{
    printf("Signal SIGFPE has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t status; // Determines the success of the `signal` call

    status = signal(SIGFPE, (void *)callback);
    if (status == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        raise(SIGFPE); // Send a signal associated with floating point error
}
