/*Name: Kantimahanty Rohit, Roll No: MT2022149*/

// Question - Write a separate program (for each time domain) to set a interval timer in 10s and 10ms - `ITIMER_VIRTUAL`

#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
void main(int argc, char *argv[])
{
    int status;
    struct itimerval timer;

    if (argc < 2)
    {
        printf("Pass 1 for 10s timer or 2 for 10ms timer\n");
        _exit(0);
    }
    arg = atoi(argv[1]);

    if (arg == 1)
    {
        // Setting a interval timer for 10s
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;
    }
    else if (arg == 2)
    {
        // Setting a interval timer for 10ms
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = 10000;
    }

    status = setitimer(ITIMER_VIRTUAL, &timer, 0);
    if (status == -1)
        perror("Error while setting an interval timer!");

    while(1);
}
