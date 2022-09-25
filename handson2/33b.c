#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
//#include<string.h> //for bzero()

int main()
{
    int sd, nsd;  
    struct sockaddr_in server, client;
    char data[100];

    int clilen;

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == -1)
        perror("\nError creating socket!");

    //was getting a data which was stored before so use the bzero to erase memory

    //bzero((char *)&server,  sizeof(server));

    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_family = AF_INET;
    server.sin_port = htons(9000);

    if((bind(sd, (struct sockaddr *)&server, sizeof(server)))==-1)
        perror("\nError binding!!");

    if((listen(sd, 5))==-1) //backlog queue size = 5
        perror("\nError listening!");

    clilen = sizeof(client);
    nsd = accept(sd, (struct sockaddr *)&client, &clilen); //passing an empty structure to be filled by the server with client details when client requests a connection 
    if (nsd == -1)
        perror("\nError making connection!");
    else
    {
        if((read(nsd, data, sizeof(data)))==-1)
            perror("Error! Cannot receive message from client!!");
        else
            printf("%s\n", data);

	if((write(nsd, "Hello client, this is server!", 29))==-1)
            perror("\nError sending data to client!!");
    }

    close(nsd);
    close(sd);

    return 0;
}
