/* Name : Kantimahanty Rohit, Roll No: MT2022149 */

/*27. Write a program to execute ls -Rl by the following system calls
 a. execl
 b. execlp
 c. execle
 d. execv
 e. execvp*/

#include<unistd.h>
#include<stdio.h>

int main()
{
  char path[] = "/bin/ls";
  //char opt[] = "-Rl";

  execl(path, "ls", "-Rl", NULL);

  printf("If the execl fails to execute, this printf statement will execute!!!");
  return 0;
}
