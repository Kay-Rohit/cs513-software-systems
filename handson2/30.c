
/*Name: Kantimahanty Rohit, Roll No. MT2022149*/

/* 30. Write a program to create a shared memory. 
    1. Write some data to the shared memory
    2. Attach with `O_RDONLY` and check whether you are able to overwrite. 
    3. Detach the shared memory 
    4. Remove the shared memory
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    key_t key;
    int shmid;
    ssize_t shm_size = 20; // Shared Memory size
    char *ptr1; //pointer when we pass 0
    char *ptr2; //pointer when we pass SHM_RDONLY as a flag

    if((key = ftok(".", 'a'))==-1) //creates ahm key
        printf("\nError while computing key!");

    if((shmid = shmget(key, shm_size, IPC_CREAT | 0700))==-1)
        printf("\nUnable to get shared memory!!!");

    ptr1 = shmat(shmid, (void *)0, 0);
    if(*ptr1==-1)
        printf("\nError! acnnot attach to the address space!");



	//writinf into the shared mem
    printf("\nWriting into shared mem...\n");
    sprintf(ptr1, "writing into shared mem from program 30.c"); // Writing the string in buff to the shared memory

    printf("\nReading from the shared memory...\n");
    printf("\nData from shared memory: %s", ptr1); // Reading from the shared memory



	//GETTING ERROR 7759 segmentation fault (core dumped) while trying to write it
    ptr2 = shmat(shmid, (void *)0, SHM_RDONLY);
    if(*ptr2==-1)
        printf("\nCannot attach to the address space!");

	//checking if we can write into readonly shared mem
    //printf("\nWriting in the shared memory using 'SHM_RDONLY' flag...\n");
    //sprintf(ptr2, "Hello, writing into shared memory from program 30.c"); // Writing the string in buff to the shared memory


    printf("\nReading from the shared memory...\n");
    printf("\nData from shared memory: %s", ptr2); // Reading from the shared memory


	//detaching shared mem
    printf("\nDetachint the shared memory...\n");
    shmdt(ptr1);
    shmdt(ptr2);
	//deleting shared mem
    if((shmctl(shmid, IPC_RMID, NULL))==-1)
	printf("\nError !!!");
    printf("\nDeleted Shared Memory...\n");

    return 0;
}
