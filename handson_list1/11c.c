/* Name:Kantimahanty Rohit, Roll no. MT2022149 */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
int w1, w2;
char buff1[]="Written using original file descriptor!!";
char buff2[]="\n Written using duplicated file descriptor!!";
int fd1, fd2;
fd1 = open("testfilec.txt", O_CREAT | O_RDWR | O_APPEND, 0744);
fd2 = fcntl(fd1, F_DUPFD, 0);
printf("\n Duplicated file descriptor using fcntl system call and values are %d, %d", fd1, fd2);
w1 = write(fd1, buff1, sizeof(buff1)); //writinf using original fd
w2 = write(fd2, buff2, sizeof(buff2)); //writing using duplicated fd
if(w1!=0 && w2!=0) printf("\n Successfully written in file using both file descriptors...");
close(fd1);
close(fd2);
return 0;
}
