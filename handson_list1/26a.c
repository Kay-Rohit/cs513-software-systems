/* Name : Kantimahanty Rohit, Roll No: MT2022149 */

/*26. Write a program to execute an executable program.
 a. use some executable program
 b. pass some input to an executable program. (for example execute an executable of $./a.out name)*/

#include<stdio.h>

int main(int argc, char * argv[])
{
  printf("This is an example of executable of executable and the passed argument is : %s \n", argv[0]);
 // printf("%s", argv[1]);
  return 0;
}
