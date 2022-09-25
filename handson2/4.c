/*Name: Kantimahanty Rohit, Roll No: MT2022149*/

/*4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter. */

#include<unistd.h>
#include<sys/time.h>
#include<x86intrin.h> //for rdtdc()system call
#include<stdio.h>

//get time to run getpid() using time stamp!!

int main()
{
  long long int start, end;
  pid_t pid;

  start = __rdtsc();
  for(int i =0; i<100; i++)
  	
pid = getpid();
  end = __rdtsc();

  printf("The time taken to run 100 getpid() system call is : %llu milliseconds", end-start);

  return 0;
}

