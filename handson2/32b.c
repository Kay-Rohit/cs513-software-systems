/*Name: Kantimahanty Rohit, Roll No. MT2022149*/

/* 32 b. protect shared memory from concurrent write access
*/

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/stat.h>
#include<sys/shm.h>

union semun{
  int val; //val of SETVAL
  struct semid_ds *buf; //IPC_STAT, IPC_SEt
  unsigned short *array; //array for GETALL and SETALL
}arg; //arg is union object


int main()
{

//-------------------shared mem---------------------------
    key_t shmkey;
    int shmid;
    ssize_t shm_size = 20; // Shared Memory size
    char *ptr1; //pointer when we pass 0

    if((shmkey = ftok(".", 'a'))==-1) //creates shm key
        printf("\nError while computing key!");

    if((shmid = shmget(shmkey, shm_size, IPC_CREAT | 0700))==-1)
        printf("\nUnable to get shared memory!!!");

    ptr1 = shmat(shmid, (void *)0, 0);
    if(*ptr1==-1)
        printf("\nError! cannot attach to the address space!");
//----------------------------------------------------------


//-----------------------semaphore--------------------------
  key_t semkey;
  int semid;

  if((semkey = ftok(".", 'b'))==-1)
        perror("\nError computing the key");

  if((semid = semget(semkey, 1, 0))==-1) //get semaphore if exists
  {
        semid = semget(semkey, 1, IPC_CREAT | 0700);
        if(semid==-1)
                perror("\nError getting semaphore id!!!");

        arg.val = 1; //binary semaphore
        semctl(semid, 0 , SETVAL, arg); //initialize binary semaphore
  }

  struct sembuf buf = {0, -1, 0 | SEM_UNDO};
  // 0 for first semaphore in the set
  // -1 to lock

//------------------------------------------------------------


    printf("\n\n...Before critical section...");
    //setting the semaphore lock
    if((semop(semid, &buf, 1))==-1)
        perror("\nError setting semaphore lock!!");

    printf("\n\n...Inside Critical section...");

        //writinf into the shared mem
    printf("\nWriting into shared mem...\n");
    sprintf(ptr1, "writing into shared mem from program 32b"); // Writing th>

	printf("\npress any key to exit from the critical section::");
    getchar();
    printf("\n\n...Outside critical section...\n");
    buf.sem_op=1; //unlock
    if((semop(semid, &buf, 1))==-1)
        perror("\nError removing semaphore lock!!!");

    return 0;
}
