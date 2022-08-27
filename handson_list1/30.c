/* Name : Kantimahanty Rohit, Roll No: MT2022149 */

//30. Write a program to run a script at a specific time using a Daemon process.

#include <time.h>      // time related
#include <stdio.h>
#include <stdlib.h>    // atoi
#include <sys/types.h> // setsid
#include <unistd.h>
#include <sys/stat.h>  // umask


//for reference
//https://pubs.opengroup.org/onlinepubs/009695399/functions/mktime.html

int main(int argc, char* argv[])//argv will store out time in seconds!!
{
  time_t currtime, runtime;
  struct tm *tim; //using the time structure 
  if(argc<2) printf("\n Pass the time as argument!!");
  else{
	time(&currtime); //get current time
	tim = localtime(&currtime);

	tim->tm_sec = atoi(argv[1]);  //to store the time and run after <some> seconds
	
	runtime=mktime(tim);
	
	if(!fork()) //creating deamon process
	{
		setsid(); //creates session
		chdir("/"); //go to root
		umask(0);
		do{
			time(&currtime); //update the current time
			
			//printf("%f\n", difftime(runtime, currtime));
			//printf("%ld currtimme\n", currtime);
			//printf("%ld runtime\n", runtime);
		}
		while((runtime-currtime)>0);
		//sleep(15);
		printf("\n printing this after %s seconds which is the specified time!!!", argv[1]);
		exit(0);
	}
   }

  return 0;
}
