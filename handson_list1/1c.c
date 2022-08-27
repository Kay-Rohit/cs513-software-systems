/* Name:Kantimahanty Rohit, Roll no. MT2022149 */
// FIFO (mkfifo Library Function or mknod system call)

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<fcntl.h>
#include <stdio.h>
#include <error.h>
// mkfifo myfifo.file   -  shell command

int main()
{
 int fd,e;
 char fn[] = "test5.file";
 ///fd = open(fn, O_CREAT | O_RDWR, 0744);
 mkfifo(fn, 0744);
// if(e) printf("\n file created successfully");
// else printf("\n error in creating fifo file");
 perror("error is:"); 
return 0;
}
