/*Name: Kantimahanty Rohit, Roll No: MT2022149*/

// 29. Write a program to remove the message queue.

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>

//pass the msqid as command line argument
int main(int argc, char *argv[])
{
    if(argc<2) 
	printf("\nPlease pass msqid as command line argument...");
    int msgqid=atoi(argv[1]);
    int status;

    printf("\nMessage Queue Identifier is  %d", msgqid);

    status = msgctl(msgqid, IPC_RMID, NULL);

    if (status == -1)
        printf("\nCannot remove Message Queue!!!"); 
    else
	printf("\nSuccessfully removed from message queue!");
  return 0;
}
