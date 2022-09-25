/*Name: Kantimahanty Rohit, Roll : MT2022149*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
//#include<string.h> //for bzero()

void myThread(int *fd)
{

    ssize_t r, w;
    char dataFromClient[100];

    w = write(*fd, "I'm the server!", 15);
    if (w == -1)
        perror("Error while writing to network via socket!");
    else
        printf("Data sent to client!\n");

    r = read(*fd, dataFromClient, 100);
    if (r == -1)
        perror("Error while reading from network via socket!");
    else
        printf("Data from client: %s\n", dataFromClient);

    close(*fd);
}

int main()
{
    int sd, nsd;  
    struct sockaddr_in server, client;
    int clilen; //length of client
    pthread_t threadID;

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == -1)
        perror("\nError creating socket!");

    server.sin_addr.s_addr = htons(INADDR_ANY);
    server.sin_family = AF_INET;
    server.sin_port = htons(9000);
    //internet uses big endian and processors use little endian so we need htons to convert little endian to big endian

    if((bind(sd, (struct sockaddr *)&server, sizeof(server)))==-1)
        perror("\nError binding!!");

    if((listen(sd, 5))==-1) //backlog queue size = 5
        perror("\nError listening!");

    clilen = sizeof(client);

    while(1){
	printf("\nsd value:%d", sd);
	//getchar();
    	nsd = accept(sd, (struct sockaddr *)&client, &clilen); //passing an empty structure to be filled by the server with client details when client requests a connection 
    	if (nsd == -1)
        	perror("\nError making connection!");
    	else
        {
	if (pthread_create(&threadID, NULL, (void *)myThread, &nsd))
                perror("\nError while creating thread");
	close(nsd); //returns the control to the server
	}
    }
    return 0;
}
