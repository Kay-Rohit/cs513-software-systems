/*Name: Kantimahanty Rohit, Roll No. MT2022149*/
/*17. Write a program to execute ls -l | wc.
 a. use dup*/

#include<stdio.h>
#include<unistd.h>

int main(){
  int fd[2];
  pipe(fd);

  if(!fork())
  {
	//child
	close(fd[0]); //close unused read end
	close(1); //close stdout
	
	dup(fd[1]); //redirect to pipe output
	execlp("/usr/bin/ls", "ls", "-l", NULL);
  }
  else
  {
	//parent
	close(fd[1]); //close unused write
	close(0); //close stadin

	dup(fd[0]);
	execlp("/usr/bin/wc", "wc", NULL);

	wait(0); //waiting for child
  }
  return 0;
}
