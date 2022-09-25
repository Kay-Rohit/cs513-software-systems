#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h> //for copying

int main()
{
    key_t key;
    int msgqid;
    int status;

    struct msgContent
    {
        long int msg_type; //id
        char msg_text[30]; //message
    } m;

    if((key = ftok(".", 'a')) == -1)
        printf("\nError while computing key!");

    if ((msgqid=msgget(key, IPC_CREAT | 0744)) == -1)
        printf("\nError while creating message queue!");

    m.msg_type = 1;
    strcpy(m.msg_text ,"This is the sent message!");

    status = msgsnd(msgqid, (void *)&m, sizeof(m), 0); //added (void *) for type conversion

    if (status == -1)
        printf("\nmessage not sent!");
    else
        printf("\nMessage sent successfully!\n use 'ipcs -q'");
  return 0;
}
