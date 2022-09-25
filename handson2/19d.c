/*Name:Kantimahanty Rohit, Roll No. MT2022149*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
  char fileName[]="./mknod_fifo19d";
  int status;

  status = mkfifo(fileName, S_IRWXU);
  if(status == -1)
        printf("\nError creating fifo file!!!");
  else
        printf("\nFIFO file created successfully!");
  return 0;
}
