/* Name:Kantimahanty Rohit, Roll no. MT2022149 */

/*20. Find out the priority of your running program. Modify the priority with nice command.*/

#include <unistd.h> // Import for `nice` system call
#include <stdio.h>  // Import for `printf` function
#include <stdlib.h> // `atoi` conversion from string to int

int main(int argc, char * argv[])
{
    int pr1, pr2;
    if (argc < 2)
        printf("please pass the priority (as command line argument) to set as new priority \n");
    else
    {
        pr2 = atoi(argv[1]); //store the passed priority
        pr1 = nice(0); // Get the priorty
	int pid = getpid();
        printf("Current priority of the process[%d]: %d\n",pid, pr1);
        pr1 = nice(pr2); // Adds new priority to the current process
        printf("New priority: %d\n", pr1);

	getchar();
    }
return 0;
}
