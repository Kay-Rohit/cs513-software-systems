/* Name : Kantimahanty Rohit, Roll No: MT2022149 */

//28. Write a program to get maximum and minimum real time priority

#include <sched.h> //for getting min and max priority 
#include <stdio.h>  
//man sched
int main()
{
  int maxi, mini;
  if((maxi=sched_get_priority_max(SCHED_FIFO))==-1) //get max priority of scheduling mentioned - FIFO||RR
	printf("Error while getting max priority !!\n");
  printf("Maximum priority of FIFO scheduling is : %d\n", maxi);

  if((mini=sched_get_priority_min(SCHED_FIFO))==-1) //get max priority of FIFO scheduling
	printf("Error while getting the min priority!!\n");
  printf("Minimum priority of FIFO scheduling is : %d\n", mini);

  return 0;
}
