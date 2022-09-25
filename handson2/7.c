/*Name:Kantimahanty Rohit, Roll: MT022149*/

// 7- Write a simple program to print the created thread IDs.

#include <pthread.h>
#include <stdio.h>

void foo()
{
    printf("Running in thread with thread ID: %lu\n", pthread_self());
}

int main()
{
    pthread_t threadID;

    // Create thread
    if(pthread_create(&threadID, NULL, (void *)foo, NULL))
        perror("Error while creating thread");

    pthread_exit(NULL);

    return 0;
}
