/*Name: Kantimahanty Rohit, Roll no.: MT2022149*/

/*20. Write two programs so that both can communicate by FIFO -Use one way communication*/


#include <fcntl.h>     // Import for `open`
#include <unistd.h>    // Import for `write`
#include <stdio.h>

//read end of the one way communication

int main()
{
    int fd,r;
    char data[40];

    if((fd = open("myfifo", O_RDONLY)) == -1)
        printf("\nError while opening FIFO file!");
    else
    {
        if(read(fd, &data, sizeof(data))==-1)
            printf("\nError while reading from the FIFO file!");
        close(fd);
    }

    printf("\nReceived: %s from the fifo file", data);
    return 0;
}
