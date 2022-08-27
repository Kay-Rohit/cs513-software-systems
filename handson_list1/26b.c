/* Name : Kantimahanty Rohit, Roll No: MT2022149 */

#include<unistd.h>
int main()
{
  char a[]="this is the passed agrument from 26b.c\n";
  char p[]="./26a";

  execl(p, a, NULL);
  return 0;
}
