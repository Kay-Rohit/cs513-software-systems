// Name: Kantimahanty Rohit, Roll: MT2022149

// 12 : Write a program to create an orphan process. Use `kill` system call to send `SIGKILL` signal to the parent process from the child process.

#include <sys/types.h> // Import for `kill`, `fork`
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    pid_t cpid, ppid;
    int status; // Determines success of `kill`

    if(!fork())
    {
        // Child
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        sleep(10);

        status = kill(getppid(), SIGKILL);

        if (!status)
        {
            printf("Successfully killed parent!\n");
            sleep(10);
            printf("Child now exiting!\n");
        }
        else
            perror("Error while killing parent!");
    }
    else
    {
        // Parent
        while (1);
    }
}
