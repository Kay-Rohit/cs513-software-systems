// Name: Kantimahanty Rohit, Roll: MT2022149

// 13a : Write two programs: first program is waiting to catch `SIGSTOP` signal, the second program will send the signal (using `kill` system call). Find out whether the first  program is able to catch the signal or not.

//catch `SIGSTOP` signal
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void mySignalHandler()
{
    printf("Received SIGSTOP signal!\n");
    _exit(0);
}

int main()
{
    __sighandler_t status; // Determines success of `signal`
    pid_t pid = getpid();

    printf("Process ID: %d\n", pid);
    status = signal(SIGSTOP, mySignalHandler);
    if (status == SIG_ERR)
        perror("\nError while catching signal!");

    printf("\nPutting the process to sleep for 10 seconds");
    sleep(10);

    return 0;
}
