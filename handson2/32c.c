/*Name: Kantimahanty Rohit, Roll No.: MT2022149*/

//32c. Write a program to implement semaphore to protect any critical section - Protect multiple pseudo resources (may be two) using counting semaphore 

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>
#include <stdio.h>

void main()
{
    char file[] = "testfile.txt";

    int fd,r,w;
    char data[128];

    key_t key;
    int semid;

    // Create a new ticket file / open an exisiting one
    if((fd = open(file, O_RDONLY))==-1)
        printf("\nError! opening the file");

    // Defines a semaphore's structure
    union semun
    {
        int val;
    } sem_set;

    if((key = ftok(".", 'z'))==-1)
        printf("\nError while computing key!");

    semid = semget(key, 1, 0); // Get the semaphore if it exists
    if (semid == -1)
    {
        semid = semget(key, 1, IPC_CREAT | 0700); // new semaphore 
        if (semid == -1)
            printf("\nError while creating semaphore!");

        sem_set.val = 2; // >1 for counting semaphore

        if((semctl(semid, 0, SETVAL, sem_set))==-1)
            printf("Error while initializing a binary sempahore!");
    }

    struct sembuf s;
    s.sem_num = 0;
    s.sem_flg = IPC_NOWAIT;

    printf("\n...Outside the critical section!...\n");

    s.sem_op = -1; //lock
    if((semop(semid, &s, 1))==-1)
        printf("\nError getting lock!!!");

    r = read(fd, data, sizeof(data));
    if (r == -1)
        printf("\nError ! reading from the test file!");
    else
        printf("\nTest file contains: \n %s", data);

    printf("\n\nPress enter key to exit critical section!\n");
    getchar();

    
    s.sem_op = 1; //unlock
    if((semop(semid, &s, 1))==-1)
        printf("\nError while operating on semaphore!");

    close(fd);
}