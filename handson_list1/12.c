
/* Name:Kantimahanty Rohit, Roll no. MT2022149 */

//12. Write a program to find out the opening mode of a file. Use fcntl.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
int fd,m,flag_mode;
char fn[]="testfile.file";

fd = open(fn, O_CREAT | O_RDWR, 0744);

m = fcntl(fd, F_GETFL);
if(m==-1) printf("Error reading the file flag status!!\n");
else{
//https://stackoverflow.com/questions/23412803/fcntl-and-f-getfl-strange-result
// 0 for read only mode
// 1 for write only mode
// 2 for read write mode
	flag_mode = m&O_ACCMODE;
	printf("File mode is : %d \n", flag_mode);
	if(flag_mode == 0) printf("i.e. Read Only mode ");
	if(flag_mode == 1) printf("i.e. Write Only mode ");
	if(flag_mode == 2) printf("i.e. Read Write mode ");
}
return 0;
}
