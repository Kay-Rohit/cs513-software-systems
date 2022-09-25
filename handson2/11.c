//Name: Kantimahanty Rohit, Roll: MT2022149

// 11 : Write a program to ignore a `SIGINT` signal then reset the default action of the `SIGINT` signal - use `sigaction` system call.

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void mySignalHandler(int signum)
{
    printf("Caught signal SIGINT (%d)\n", signum);
}

void main()
{
    int status;
    struct sigaction action;

    // Ignore SIGINT
    printf("Ignoring SIGINT for 5 seconds!\n");
    action.sa_handler = SIG_IGN; //ignore
    action.sa_flags = 0;
    status = sigaction(SIGINT, &action, NULL); //signal, newaction, oldaction
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        sleep(5);


    // Provide custom handler
    printf("Handling SIGINT for 5 seconds!\n");
    action.sa_handler = mySignalHandler;
    action.sa_flags = 0;
    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        sleep(5);

    // Setting default handler
    printf("Default action for SIGINT for 5 seconds!\n");
    action.sa_handler = SIG_DFL;
    action.sa_flags = 0;
    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        sleep(5);
}
