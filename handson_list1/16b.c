
/* Name:Kantimahanty Rohit, Roll no. MT2022149 */

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
  struct flock lc;
  int r, fd;
  //decribing lock and initializing lc object with its method
  lc.l_type = F_RDLCK;
  lc.l_whence = SEEK_SET;
  lc.l_start = 0;
  lc.l_len = 0;
  lc.l_pid = getpid();
  printf("\n Implementing Read LOCK!!");
  printf("\n block before critical section...");
  fd = open("testfileb.txt", O_CREAT | O_RDWR, 0744);
  r = fcntl(fd, F_SETLKW, &lc); //setlckw waits for other process to release >

  if(r==-1) printf("\n ERRORgetting lock!");  

  //crritical section
  printf("\n Inside critical scetion!!");
  printf("\n enter any key to exit critical section : ");
  getchar();

  lc.l_type = F_UNLCK;
  r = fcntl(fd, F_SETLK, &lc); //release the lock

  if(r==-1) printf("\n error unlocking the file");

  printf("\n Out of critical section.");
  return 0;
}
