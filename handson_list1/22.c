/* Name:Kantimahanty Rohit, Roll no. MT2022149 */

/*22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file. */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
  int fd;
  char fn[]="testfile.txt";
  char bychild[]="This text is written by child process \n";
  char bypar[]="This text is written by parent process \n";

  fd = open(fn, O_CREAT | O_RDWR | O_APPEND, 0744);
  if(!fork())
	write(fd, bychild, sizeof(bychild));
  else
	write(fd, bypar, sizeof(bypar));

  close(fd);

  return 0;
}
