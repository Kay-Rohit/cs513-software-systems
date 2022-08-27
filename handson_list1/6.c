/* Name:Kantimahanty Rohit, Roll no. MT2022149 */
//Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	char buf[40]; int readCount;
	readCount = read(0, buf, sizeof(buf));
	printf("/n Printing on the standard output ... /n");
	write(1, buf, readCount);
	//fd=0 is standard input file descripter
	//fd=1 is tandard output file descripter
	close(0);
	close(1);
	return 0;
}
