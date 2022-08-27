/* Name:Kantimahanty Rohit, Roll no. MT2022149 */

/*17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.*/

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

struct db{
  int ticket;
}db;

int main()
{
  int fd, r;
  struct flock fl;

//setting lock parameters
  fl.l_type = F_WRLCK;
  fl.l_whence = SEEK_SET;
  fl.l_start = 0;
  fl.l_len = 0;
  fl.l_pid = getpid();

  fd = open("dBase.txt", O_RDWR, 0744);

  printf("\n Before critical section ...");
  
//reading from file
  read(fd, &db, sizeof(db));
  printf("\n Ticket No. before updating is %d", db.ticket);

  fcntl(fd, F_SETLKW, &fl); //getting write lock

  printf("\n Insitical dection...");
  db.ticket++; //incrementing ticket no.
  printf("\n Updated Ticket No. is %d", db.ticket);
  
  lseek(fd, -1*sizeof(db), SEEK_CUR);
  write(fd, &db, sizeof(db)); //writing the new ticket no. to the file
  printf("\n Enter any key to save changes :");
  getchar();
  fl.l_type = F_UNLCK;
  printf("\n outside critical section...");
  fcntl(fd, F_SETLK, &fl);
  
  return 0;
}
