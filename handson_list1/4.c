/* Name:Kantimahanty Rohit, Roll no. MT2022149 */
//. Write a program to open an existing file with read write mode. Try O_EXCL flag also. 

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(){
	int fd;
	char buf[80];
	char fn[]="test1.file";
	//fd = open(fn, O_RDWR);
	fd=open(fn, O_CREAT | O_RDWR, 0744);
	read(fd, buf, sizeof(buf));
	printf("/n contents in file are : %s", buf);
return 0;
}
