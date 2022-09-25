/*Name: Kantimahanty Rohit, Roll : MT2022149*/

//3. Write a program to set (any one) system resource limit. Use setrlimit system call. 

#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main()
{
    struct rlimit rlim;
    int status;

    //This  is a limit, in seconds, on the amount of CPU time that the process >
    status = getrlimit(RLIMIT_CPU, &rlim);
    if(status==-1) perror("\nError getting CPU limits:");
    printf("\nThe cpu limit is : %ld , %ld", rlim.rlim_cur, rlim.rlim_max);

    //setting cpu limit
    rlim.rlim_cur = 4960;
    status = setrlimit(RLIMIT_CPU, &rlim);
    if(status == -1) perror("\n Unable to set resource (CPU) limit!! :");
    else{
    	status = getrlimit(RLIMIT_CPU, &rlim);
    	if(status==-1) perror("\nError getting CPU limits:");
    	printf("\nThe NEW cpu limit is : %ld , %ld", rlim.rlim_cur, rlim.rlim_max);
    }

    return 0;
}
