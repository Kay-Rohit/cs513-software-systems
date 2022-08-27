/* Name:Kantimahanty Rohit, Roll no. MT2022149 */


#include<stdio.h>
#include<stdlib.h>

int main(int args, char *argv[], char *envp[])
{
printf("\n contents of envp are : \n");

char **curr = envp;
int count=0;
while(*curr != NULL)
{
count++;
printf("%d : %s: \n", count, *curr);
curr++;
}

return 0;
}
