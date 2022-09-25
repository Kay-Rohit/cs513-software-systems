/*Name: Kantimahanty Rohit, Roll No: MT2022149*/

/*32. Write a program to implement semaphore to protect any critical section.
 a. rewrite the ticket number creation program using semaphore*/

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/stat.h>

struct db{
  int ticket;
}db; //db is struct obj

union semun{
  int val; //val of SETVAL
  struct semid_ds *buf; //IPC_STAT, IPC_SEt
  unsigned short *array; //array for GETALL and SETALL
}arg; //arg is union object


int main()
{
  int fd, r, w;
  char filename[]="ticketDB.txt";

  //semaphore
  key_t key;
  int semid;

  if((fd = open(filename, O_RDWR, 0744))==-1)
	perror("\nError opening the database file!!!");

  if((key = ftok(".", 'a'))==-1)
	perror("\nError computing the key");

  if((semid = semget(key, 1, 0))==-1) //get semaphore if exists
  {
	semid = semget(key, 1, IPC_CREAT | 0700);
	if(semid==-1)
		perror("\nError getting semaphore id!!!");

	arg.val = 1; //binary semaphore
	semctl(semid, 0 , SETVAL, arg); //initialize binary semaphore
  }

  struct sembuf buf = {0, -1, 0 | SEM_UNDO};
  // 0 for first semaphore in the set
  // -1 to lock
  printf("\nBefore critical section...\n");

  //setting the semaphore lock
  if((semop(semid, &buf, 1))==-1)
	perror("\nError setting semaphore lock!!");

  printf("\nInside Critical section...\n");

  r =read(fd, &db, sizeof(db));
  if(r==-1)
	perror("\nError while reading from the database file!!!");
  else{
	db.ticket++; //incrementing ticket no.
	printf("\n Updated Ticket No. is %d", db.ticket);

 	lseek(fd, -1*sizeof(db), SEEK_CUR);
 	w=write(fd, &db, sizeof(db)); //writing the new ticket no. to the file
	if(w==-1)
		perror("\nError writing into the database!!!");
 	printf("\n Enter any key to save changes :");
 	getchar();
  }

  printf("\nOutside critical section...\n");
  buf.sem_op=1; //unlock
  if((semop(semid, &buf, 1))==-1)
	perror("\nError removing semaphore lock!!!");

  close(fd);


  return 0;
}
