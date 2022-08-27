/* Name : Kantimahanty Rohit, Roll No: MT2022149 */

#include <unistd.h>
#include <stdio.h>

int main()
{
    char path[] = "/bin/ls";
    execle(path, "ls", "-Rl", NULL, NULL);
    printf("\n This printf statement will execute if execle fails!!!");

    return 0;
}
