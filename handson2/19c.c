/*Name: Kantimahanty Rohit, Roll No. Mt2022149*/

/*19. Create a FIFO file by
 a. mknod command
 b. mkfifo command
 c. use strace command to find out, which command (mknod or mkfifo) is better.
 c. mknod system call*/

//19a - mknod fifo19a p
//19b - mkfifo fifo19b
//19c - strace mkfifo fifo19c -> mkfifo calls mknod internally

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
  char fileName[]="./mknod_fifo19c";
  int status;

  status = mknod(fileName, __S_IFIFO | S_IRWXU, 0);
  if(status == -1)
	printf("\nError creating fifo file!!!");
  else
	printf("\nFIFO file created successfully!");
  return 0;
}
