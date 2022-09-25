/*Name: Kantimahanty Rohit, Roll no.: MT2022149*/

/*17. Write a program to execute ls -l | wc.
 a. use dup
 b. use dup2
 c. use fcntl*/

#include<unistd.h>
#include<stdio.h>

int main()
{
  int fd[2];
  //create pipe
  pipe(fd);

  if(!fork())
  {
	//child
	close(fd[0]); //close read end
	//redirect stdout to pipe 
	dup2(fd[1], 1); //redirects stdout to pipes write end
	execlp("/usr/bin/ls","ls", "-l", NULL);
  }
  else
  {
	//parent
	close(fd[1]); //close unused write end
	dup2(fd[0], 0); //redirects stdin to pipes input end
	execlp("/usr/bin/wc", "wc", NULL);

	wait(0);
  }

  return 0;
}
