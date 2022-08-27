/* Name:Kantimahanty Rohit, Roll no. MT2022149 */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
int w1, w2;
char buff1[]="Written using original file descriptor!!";
char buff2[]="\n Written using duplicated file descriptor made using dup";
int fd1, fd2, fd3;
fd1 = open("testfileb1.txt", O_CREAT | O_RDWR | O_APPEND, 0744); //fd 3
fd2 = open("testfileb2.txt", O_CREAT | O_RDWR | O_APPEND, 0744); //fd 4

//dup2 system call allows to specify where to duplicate
fd3 = dup2(fd1, fd2);
//dup2 call makes the fd2 to point at testfileb1 instead of testfileb1 with fd value of 4
printf("\nOriginal and Duplicated file descriptor using dup2 system call and values are : %d %d %d ", fd1, fd2, fd3);
w1 = write(fd1, buff1, sizeof(buff1)); //writinf using original fd
w2 = write(fd2, buff2, sizeof(buff2)); //writing using dup2 duplicated fd
if(w1!=0 && w2!=0) printf("\n Successfully written in file using both file descriptor!!");
close(fd1);
close(fd2);
close(fd3);
return 0;
}
