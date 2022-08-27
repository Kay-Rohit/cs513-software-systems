/* Name:Kantimahanty Rohit, Roll no. MT2022149 */

/*19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.*/

#include<unistd.h>
#include<sys/time.h>
#include<x86intrin.h> //for rdtdc()system call
#include<stdio.h>


//get time to run getpid() using time stamp!!


int main()
{
  //time_t start, end;
  //start = clock();
  //int pid = getpid();
  //end = clock();
  //printf("Time taken to run getpid() system call = %.2f seconds", difftime(end,start));
  
  long long int start, end;
  start = __rdtsc();
  pid_t pid = getpid();
  end = __rdtsc();

  printf("The time taken to run getpid() system call is : %llu milliseconds", end-start);

  return 0;
}
