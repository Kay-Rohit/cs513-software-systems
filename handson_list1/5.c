/* Name:Kantimahanty Rohit, Roll no. MT2022149 */
//Write a program to create five new files with infinite loop. Execute the program in the background
//and check the file descriptor table at /proc/pid/fd.

#include<fcntl.h>
#include<unistd.h>

void main()
{
  while(1){
  creat("file1.txt", O_CREAT);
  creat("file2.txt", O_CREAT);
  creat("file3.txt", O_CREAT);
  creat("file4.txt", O_CREAT);
  creat("file5.txt", O_CREAT);
  }
}
