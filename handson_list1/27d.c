/* Name : Kantimahanty Rohit, Roll No: MT2022149 */

#include <unistd.h> 
#include <stdio.h>  

//https://stackoverflow.com/questions/32142164/how-to-use-execv-system-call-in-linux

int main()
{
    char *arguments[]={"ls", "-Rl", NULL}; //need array of pointers pointing to all the strings
    execv("/bin/ls", arguments);
    printf("\n This printf statement will execute if execv fails!!!");

    return 0;
}

