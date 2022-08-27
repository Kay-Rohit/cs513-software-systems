/* Name:Kantimahanty Rohit, Roll no. MT2022149 */

//24. Write a program to create an orphan process.

#include<stdio.h>

int main()
{
  if(!fork())
  {
	printf("\nInside Child Process with pid  = %d", getpid());
	printf("\nMaking child to sleep for 10 seconds...");
	sleep(10); //control goes to parent process
	printf("\nChild is now awake...");
  }
  else
	printf("\nInside parent process with pid = %d", getpid());
	//here parent exits and when control is returned to the child process it has no where to go thus become orphane


  return 0;
}
