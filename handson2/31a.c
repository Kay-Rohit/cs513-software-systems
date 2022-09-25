/*Name: Kantimahanty Rohit , Roll No. MT2022149*/

//31a . Write a program to create a semaphore and initialize value to the semaphore - binary semaphore

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    key_t key;
    int semid;
    int semctlStatus;

    union semun {
        int val; // Value of the semaphore
    } sem_set;

    if((key = ftok(".", 'a'))==-1)
        printf("\nError while computing key!");

    if((semid = semget(key, 1, IPC_CREAT | 0777))==-1)
        printf("\nCannot create semaphore!");

    sem_set.val = 1; // 1 implies binary semaphore
    if((semctl(semid, 0, SETVAL, sem_set))==-1)
        printf("\nError setting value of the binary semaphore!!!");
    printf("\nBinary semaphore Initialized suceesfully!!!\n\n Check using 'ipcs -s'");

    return 0;
}
