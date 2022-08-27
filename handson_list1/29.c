/* Name : Kantimahanty Rohit, Roll No: MT2022149 */

/*29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).*/


//grep define.SCHED_ /usr/include/linux/sched.h 

//#define SCHED_NORMAL    0
//#define SCHED_FIFO      1
//#define SCHED_RR        2
//#define SCHED_BATCH     3
//#define SCHED_IDLE      5
//#define SCHED_DEADLINE  6


#include<stdio.h>
#include<sched.h>
#include<unistd.h> //getpid()

int main()
{
  int pid = getpid(); //get pid of current process

  //get current scheduling algo of the process
  int curr_policy = sched_getscheduler(pid);

  //structure of scheduling parameter
  struct sched_param p;
  p.sched_priority = 15; //setting priority

  if(curr_policy==-1) printf("\n Unable to get the scheduling policy!!\n");

  switch(curr_policy){
	case 0: printf("\nCurrent policy is SCHED_NORMAL");
		break;
	case 1: printf("\nCurrent policy is SCHED_FIFO");
		break;
	case 2: printf("\nCurrent policy is SCHED_RR");
		break;
	case 3: printf("\nCurrent policy is SCHED_BATCH");
		break;
	case 5: printf("\nCurrent policy is SCHED_IDLE");
		break;	
	case 6: printf("\nCurrent policy is SCHED_DEADLINE");
		break;
	default: printf("\Error!!");
		break;
  }

  //now changing the scheduling algo
  sched_setscheduler(pid, SCHED_FIFO, &p); //1 for FIFO policy

  //getting the new policy
  int new_policy = sched_getscheduler(pid);
  if(new_policy == 1)
	printf("\n Yay !! \nSuccesfully changed the new policy to sched_fifo !!!");
  else
	printf("\nUnable to set new policy to FIFO, insted it was set as %d", new_policy);

  return 0;
}
