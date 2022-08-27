/* Name:Kantimahanty Rohit, Roll no. MT2022149 */
//Write a program to copy file1 into file2 ($cp file1 file2)


#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(int argc, char* argv[]){
	int fd1, fd2,n, w;
	char buf[100];// int wr;
	if(argc<2) printf("\n please provide file names as arguments!!");
	fd1 = open(argv[1], O_RDONLY, 0777);
	fd2 = open(argv[2], O_CREAT | O_RDWR , 0777);
	printf("\n fd1 = %d and fd2 = %d", fd1, fd2);
//read command returns 0 when it reaches end of the file
	while((n=read(fd1, buf, 20))!=0)
		w = write(fd2, buf, n);
	printf("\n %d lines copied successfully to file %s", w, argv[2]);
	//else printf("\n error while copying!!");
	close(fd1);
	close(fd2);
	return 0;
}
