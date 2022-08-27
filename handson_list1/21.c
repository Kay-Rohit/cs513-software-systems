/* Name:Kantimahanty Rohit, Roll no. MT2022149 */

//21. Write a program, call fork and print the parent and child process id.

#include<stdio.h>
#include<fcntl.h>

int main()
{
  int pid, cid;
  if(!fork())
  {
	cid = getpid(); //child process
	printf("\nThe child process id is %d", cid);
  }
  else{
	pid = getpid();
	printf("\nThe parent process id is %d", pid);
 }
 // printf("\nThe parent process id is %d and child process id is %d", pid, cid);

return 0;
}
