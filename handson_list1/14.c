/* Name:Kantimahanty Rohit, Roll no. MT2022149 */

/*Write a program to find the type of a file.
 a. Input should be taken from command line.
 b. program should be able to identify any type of a file. */

#include<stdio.h>
#include<sys/stat.h>


int main(int argc, char * argv[])
{
struct stat fileS;
int i, m;
if(argc<2)
	printf("Please give file name as command line agrument!! \n");
	for(i=0; i<argc-1; i++)
	{
		if(stat(argv[i], &fileS) == -1) printf("Error opening the file! \n");	
		else{
			//m = fileS.st_mode; //not working
			printf("file mode in octal is %o \n", fileS.st_mode);
			if(S_ISREG(fileS.st_mode)) printf("The file type is regular \n"); 
			if(S_ISDIR(fileS.st_mode)) printf("The file type is directory \n");
			if(S_ISCHR(fileS.st_mode)) printf("The file type is character device \n"); 
			if(S_ISBLK(fileS.st_mode)) printf("The file type is block device \n");
			if(S_ISFIFO(fileS.st_mode)) printf("The file type is FIFO \n");
			if(S_ISLNK(fileS.st_mode)) printf("The file type is symbolic link \n"); 
			if(S_ISSOCK(fileS.st_mode)) printf("The file type is socket \n");
		}
// using %o to print in octal form - inode(7) linux manual page
//https://man7.org/linux/man-pages/man7/inode.7.html
	}
return 0;
}
