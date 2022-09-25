/* Name:Kantimahanty Rohit, Roll no. MT2022149 */


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

struct db{
        int ticket;   
}db;

int main()
{
  int fd1, fd2;
  db.ticket = 5; //initializing a ticket no. to the db structure

  fd1 = open("ticketDB.txt", O_CREAT | O_WRONLY, 0744);
  //printf("%d ticket no = %d", fd1, db.ticket);
  write(fd1, &db, sizeof(db)); //writing the entire structure to the file
  close(fd1);

  fd2 = open("ticketDB.txt", O_RDONLY);
  printf("%d", fd2);

  read(fd2, &db, sizeof(db)); //retrieving the entire structure fro the file
  printf("\n Ticket No. = %d", db.ticket);
  close(fd2);

  return 0;
}


