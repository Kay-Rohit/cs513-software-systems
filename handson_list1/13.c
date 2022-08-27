/* Name:Kantimahanty Rohit, Roll no. MT2022149 */

//Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
//verify whether the data is available within 10 seconds or not (check in $man 2 select).

#include<sys/select.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
#include<error.h>

int main()
{
  fd_set rfds;
  struct timeval tv;
  int retval;

  /* watch sdtin(fd 0) to see when it has input */
  FD_ZERO(&rfds);
  FD_SET(0, &rfds);

  /* wait upto 10 seconds */
  tv.tv_sec = 10;
  tv.tv_usec = 0;

  retval = select(1, &rfds,NULL ,NULL, &tv);
  if(retval) printf("\n Data is available within 10 seconds...");
  else printf("\n Data was not available within 10 seconds!");
return 0;
}
