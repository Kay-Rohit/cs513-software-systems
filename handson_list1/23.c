/* Name:Kantimahanty Rohit, Roll no. MT2022149 */

//23. Write a program to create a Zombie state of the running program.

#include<stdio.h>
int main()
{
  if(!fork())
	printf("\n\nInside child process with pid = %d \n\n", getpid());
  else{
	printf("\nInside parent process with pid = %d", getpid());
	printf("\nMaking the parent sleep for 10 seconds \n");
	sleep(10);
	printf("\nParent is now awake !!");
  }

return 0;
}
