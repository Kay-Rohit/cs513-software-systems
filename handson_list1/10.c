/* Name:Kantimahanty Rohit, Roll no. MT2022149 */
/*Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
 a. check the return value of lseek
 b. open the file with od and check the empty spaces in between the data. */


#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

//od -c file.txt | grep " " | wc -l 
//od -b file.txt | grep "040" | wc -l

int main()
{
int fd,r,w,seek;
char buff[50];
fd = open("file.txt", O_CREAT | O_RDONLY, 0744);
seek = lseek(fd, 0, 1);
read(fd, buff, 10);
printf("\nseek value after opening the file = %d\n", seek);
write(1, buff, 10);
seek = lseek(fd, 10, 1);
read(fd, buff, 10);
printf("\nseek value after skipping 10 bytes = %d\n", seek);
write(1, buff, 10);

return 0;
}
