/*Name: Kantimahanty Rohit, Roll No: MT2022169*/

/*32d. Remove created semaphore*/

#include<unistd.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/sem.h>


int main(int argc, char * argv[])
{
  if(argc<2)
	printf("\nPlease pass semaphore id to be removed!!!");
  else{
  	for(int i=1; i<argc-1; i++){
		if((semctl(atoi(argv[i]), 0, IPC_RMID))==-1)
			printf("\nError deleting semaphore with id %c", argv[i]);
		else
  			printf("\nSucessfully removed all the semaphores!!!");
  	}
  }

  return 0;
}
