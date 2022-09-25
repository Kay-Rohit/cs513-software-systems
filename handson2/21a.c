/*Name: Kantimahanty Rohit, Roll no.: MT2022149*/

/*21. Write two programs so that both can communicate by FIFO -Use two way communication*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

//2 way communication - first send data to 21b and
//then receive data from 21b and print it

int main()
{
    char send[] = "Sending data from 21a to 21b";
    char receive[50];

    int fd1, fd2;
    char fifo1[] = "./myfifo1";
    char fifo2[] = "./myfifo2";

	//create myfifo1 for sending the data to b
    mkfifo(fifo1, S_IRWXU);
       // printf("\nError while creating FIFO file1 !");

	//then write 
    if((fd1 = open(fifo1, O_WRONLY, 0744)) == -1)
        printf("\nError while opening the sending fifo file in 21a!");
    else
    {
        if(write(fd1, &send, sizeof(send))==-1)
            printf("\nError while writing to the FIFO file in 21a!");
        close(fd1);
    }

    	//then read
    if((fd2 = open(fifo2, O_RDONLY, 0744)) == -1)
	printf("\nError while opening the receiving fifo file in 21a!");
    else{
	if(read(fd2, &receive, sizeof(receive)) == -1)
		printf("\nError reading the received file in 21a");
	close(fd2);
    }
    printf("Received: %s - from 21b", receive);

    return 0;
}
