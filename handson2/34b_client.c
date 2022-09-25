/*Name:Kantimahanty Rohit, Roll No: MT2022149*/

/*34. Write a program to create a concurrent server.
 a. use pthread_creat*/

// client
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int sd; //socket file descriptor
    int status;
    struct sockaddr_in address;
    int r, w;
    char data[100];

    if((sd = socket(AF_INET, SOCK_STREAM, 0))==-1) //tcp mechanishm between two pcs
        perror("\nError while creating socket!");
    printf("\nsuccessfully created!\n");

    // Defined server's details
    address.sin_addr.s_addr = htons(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(9000);

    status = connect(sd, (struct sockaddr *)&address, sizeof(address));
    if (status == -1)
        perror("\nError while connecting to server!");
    printf("\nSuccessfully established the connection!\n");


    //writing to the server
    if((write(sd, "Hello Server", 13))==-1)
        perror("\nError sending data to server!!");

    //reading from the server
    if((read(sd, data, 100))==-1)
        perror("\nError! Cannot get message from the server!! ");
    else
        printf("%s\n", data);

    close(sd);

    return 0;

}
