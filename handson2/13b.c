// Name: Kantimahanty Rohit, Roll: MT2022149

//send `SIGSTOP` signal
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int status; // Determines success of `kill`
    pid_t pid;

    if (argc < 2)
    {
        printf("Pass the PID of the process to whom the SIGSTOP signal is to be sent!\n");
        _exit(0);
    }

    pid = atoi(argv[1]);
    status = kill(pid, SIGSTOP);
    if(!status) 
        printf("\nSuccessfully sent SIGSTOP signal to process (%d)", pid);
    else 
        perror("\nError while sending signal!");

    return 0;
}
