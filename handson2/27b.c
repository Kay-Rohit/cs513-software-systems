/*Name: Kantimahanty Rohit, Roll no.: MT2022149*/

/*27. Write a program to receive messages from the message queue.
use - IPC_NOWAIT flag*/


#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    key_t key;
    int msgqid;
    ssize_t m;

    struct message
    {
        long int msg_type;     // Used to identify message type - should be > 0
        char msg_text[50]; // msg
    } msg;

    if((key = ftok(".", 'a')) == -1)
        printf("\nError while creating key!");

    if((msgqid = msgget(key, IPC_CREAT | 0744))==-1)
        printf("\nError while creating message queue!!!");

    msg.msg_type = 1; //imp tp receive msg as msg type will be checked
    printf("\n Key:%d and msqid:%d\n", key, msgqid);

    m = msgrcv(msgqid, (void *)&msg, sizeof(msg), msg.msg_type, IPC_NOWAIT);

    if (m == -1)
        printf("\nError while receiving!");
    else
        printf("\nReceived the text: %s", msg.msg_text);

  return 0;
}
//ipcrm -q <msqid> - to remove msg queue
