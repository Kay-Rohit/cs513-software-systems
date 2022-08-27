/* Name:Kantimahanty Rohit, Roll no. MT2022149 */
//Write a program to create a file and print the file descriptor value. Use creat ( ) system call

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
int fd;
char fn[]="test.file";
if(creat(fn, 0744)!=-1) printf("/n file created successfully!");
else printf("/n error!!");

fd = open(fn, O_RDWR);
printf("/n fd = %d", fd);

return 0;
}
