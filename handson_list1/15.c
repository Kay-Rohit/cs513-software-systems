/* Name:Kantimahanty Rohit, Roll no. MT2022149 */

//. Write a program to display the environmental variable of the user (use environ)

#include<stdio.h>
#include<stdlib.h>

extern char ** environ;

int main(int args, char *argv[])
{
printf("\n contents of envp are : \n");

char **curr = environ;
int count=0;
while(*curr != NULL)
{
count++;
printf("%d : %s: \n", count, *curr);
curr++;
}

return 0;
}
