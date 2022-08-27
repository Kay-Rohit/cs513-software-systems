/* Name:Kantimahanty Rohit, Roll no. MT2022149 */
/*11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
 a. use dup
 b. use dup2
 c. use fcntl*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
int w1, w2;
char buff1[]="Written using original file descriptor!!";
char buff2[]="\n Written using duplicated file descriptor made using dup";
int fd1, fd2;
fd1 = open("testfilea.txt", O_CREAT | O_RDWR | O_APPEND, 0744); //fd 3
fd2 = dup(fd1);
printf("\n Duplicated file descriptor using dup system call and values are : %d , %d", fd1, fd2);
w1 = write(fd1, buff1, sizeof(buff1)); //writinf using original fd
w2 = write(fd2, buff2, sizeof(buff2)); //writing using dup duplicated fd
if(w1!=0 && w2!=0) printf("\n Successfully written in file using both file descriptors!!");
close(fd1);
close(fd2);
return 0;
}
