
/* Name:Kantimahanty Rohit, Roll no. MT2022149 */

/*25. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{

  int cid1,cid2,cid3;
  cid1 = fork();
//  cid2 = fork();
//  cid3 = fork();
  if(cid1==0)
  {
	printf("\n inside the child process 1 with pid = %d", getpid());
	printf("\n making child1 sleep for 10 seconds...\n");
	sleep(10);
	printf("\n now exiting child process 1\n");
  }
 // cid2 = fork();
  else if((cid2=fork()) == 0) 
  { 
        printf("\n inside the child process 2 with pid = %d", getpid());
        printf("\n making child2 sleep for 12 seconds...\n");
	sleep(12);
	//theoritically this child process will becomw orphane as parent will wait only for child process 1 i.e. for 10 seconds then executes and exits
	//but this child 2 will wake up 2 seconds after that with no parent process to return to
        printf("\n now exiting child process 2\n");
  }
 // cid3 = fork();
  else if((cid3=fork()) == 0) 
  { 
        printf("\n inside the child process 3 with pid = %d", getpid());
	printf("\n making child3 sleep for 5 seconds...\n");
        sleep(5);
        printf("\n now exiting child process 3\n");
  }
  else
  {
  int w = waitpid(cid1, NULL, 0);
  printf("\n Exiting from parent process...\n");
  }
  return 0;
}
