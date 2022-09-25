/*Name:Kantimahanty Rohit, Roll No. MT2022149 */

/*24. Write a program to create a message queue and print the key and message queue id.*/


#include <unistd.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

int main()
{
  int msgid;
  key_t key;

  key = ftok(".", 'a'); //file to key with value 97 and file being pwd
  msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0744);

  printf("\nKey values is %d", key);
  printf("\nMessage queue id is %d", msgid);

  //check with ipcs -q
  return 0;
}
