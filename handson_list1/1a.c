/* Name:Kantimahanty Rohit, Roll no. MT2022149 */
//soft link (symlink system call)

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd;
	fd = open("test.file", O_CREAT|O_RDWR| 0744);
	char fn[]="test.file";
	char sln[]="test.symlink";
	if(!symlink(fn, sln))
	printf("Soft link created succesfully with name: %s", sln);
	else
	printf("Error creating softlink file");
	return 0;
}
