/*Name: Kantimahanty Rohit, Roll no.: MT2022149*/

/*17. Write a program to execute ls -l | wc.
 c. use fcntl*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
  int fd[2];
  //create pipe
  pipe(fd);

  if(!fork())
  {
        //child
        close(fd[0]); //close read end
        
	close(1); 
        fcntl(fd[1], F_DUPFD, 0); //redirects stdout to pipes write end
        execlp("/usr/bin/ls","ls", "-l", NULL);
  }
  else
  {
        //parent
        close(fd[1]); //close unused write end

	close(0);
        fcntl(fd[0], F_DUPFD, 0); //redirects stdin to pipes input end
        execlp("/usr/bin/wc", "wc", NULL);

        wait(0);
  }

  return 0;
}
