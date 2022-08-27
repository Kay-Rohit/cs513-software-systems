/* Name : Kantimahanty Rohit, Roll No: MT2022149 */

#include<stdio.h>
#include<unistd.h>

int main()
{
  char path[] = "bin/ls";

  execlp(path, "ls", "-Rl", NULL);

  printf("This printf statement will execute when execlp commands fails!!!");

  return 0;
}
