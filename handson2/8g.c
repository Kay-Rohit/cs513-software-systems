// Name: Kantimahanty Rohit, Roll: MT2022149

// 8g : Write a separate program using signal system call to catch `SIGPROF` (use `setitimer` system call)

#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void callback()
{
    printf("Signal SIGPROF has been caught!\n");
    _exit(0);
}

void main()
{
    int timerStatus;
    __sighandler_t status;

    struct itimerval timer;

    // Generate signal after 5s
    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    timerStatus = setitimer(ITIMER_PROF, &timer, 0);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");

    // Catch the SIGALRM signal
    status = signal(SIGPROF, (void *)callback);
    if (status == SIG_ERR)
        perror("Error while catching signal!");
    else
        while(1);
}
