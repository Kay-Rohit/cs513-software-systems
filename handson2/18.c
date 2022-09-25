/*Name: Kantimahanty Rohit, Roll no.: MT2022149*/

/*18. Write a program to find out total number of directories on the pwd.
 execute ls -l | grep ^d | wc ? Use only dup2.*/

#include <unistd.h>
#include <stdio.h>

int main(){

  int p1[2]; //ls -l | grep^d
  int p2[2]; //grep^d | wc

  if(pipe(p1) == -1) printf("\n Error creating first pipe");
  if(pipe(p2) == -1) printf("\n Error creating second pipe");

  if(!fork())
  {
        //child 1
        close(p1[0]); //close read end of pipe 1

	close(p2[0]);
	close(p2[1]); //close readwrite end of pipe 2

        dup2(p1[1], 1); //redirects stdout to pipe1 write end
        execlp("/usr/bin/ls","ls", "-l", NULL);
  }
  else if(!fork())
  {
        //child 2
        close(p1[1]); //close unused write end of pipe 1
	close(p2[0]); //close read end of pipe 2

        dup2(p1[0], 0); //redirects stdin to pipe1 read end
	dup2(p2[1], 1); //redirects stdout to pipe2 write end
        execlp("/usr/bin/grep", "grep","^d", NULL);
  }
  else
  {
	//parent
        close(p2[1]); //close unused write end of pipe 1
        close(p1[0]);
	close(p1[1]); //close read write end of pipe 1

        dup2(p2[0], 0); //redirects stdin to pipe1 read end
        execlp("/usr/bin/wc", "wc", NULL);

	wait(0);
  }//end of parent

  return 0;
}//end of main
