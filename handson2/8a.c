//Name: KAntimahanty Rohit, Roll: MT2022149

// 8a : Write a separate program using signal system call to catch `SIGSEGV`

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void callback()
{
    printf("Signal SIGSEGV has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t status;

    status = signal(SIGSEGV, (void *)callback);
    if (status == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        raise(SIGSEGV); // Send segmentation fault signal 
}
