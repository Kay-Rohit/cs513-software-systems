/*Name: Kantimahanty Rohit, Roll : MT2022149*/

//2 - Write a program to print the system resource limits. Use getrlimit system call. 

#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main()
{
    struct rlimit rlim;
    int status;

    //This  is a limit, in seconds, on the amount of CPU time that the process can consume
    status = getrlimit(RLIMIT_CPU, &rlim);
    if(status==-1) perror("\nError getting CPU limits:");
    printf("\nThe cpu limit is : %ld , %ld", rlim.rlim_cur, rlim.rlim_max);
    return 0;
}
