// Name: Kantimahanty Rohit, Roll: MT2022149

// 10a : Write a separate program using sigaction system call to catch `SIGINT` signal

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void mySignalHandler(int signalNumber)
{
    printf("Caught signal SIGINT (%d)\n", signalNumber);
    _exit(0);
}

void main()
{
    int status;
    struct sigaction action;
    char *a;

    action.sa_handler = mySignalHandler;
    action.sa_flags = 0;

    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
    {
        raise(SIGINT);
    }
}