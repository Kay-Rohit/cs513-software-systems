/* Name:Kantimahanty Rohit, Roll no. MT2022149 */
//Write a program to open a file in read only mode, read line by line and display each line as it is read.
//Close the file when end of file is reached.


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<error.h>

#define BUFFSIZE 1024

char Rd_buff[BUFFSIZE];
int main()
{
	int fd,i,l_rd;
	char fn[]="source.txt";
	i=0;
	l_rd=0;

	fd = open(fn, O_RDONLY);
	while(read(fd, &Rd_buff[i], 1))
	{
		l_rd++;
		if(Rd_buff[i]=='\n'){
			getchar();
			write(1, Rd_buff, l_rd);//output on the screen
			l_rd=1;
			i=0;
		}
		i++;
	}
}
