/* Name : Kantimahanty Rohit, Roll No: MT2022149 */

#include <unistd.h> 
#include <stdio.h>  

int main()
{
    char *arguments[]={"ls", "-Rl", NULL}; //need array of pointers pointing to>
    execvp("/bin/ls", arguments);
    printf("\n This printf statement will execute if execvp fails!!!");

    return 0;
}
