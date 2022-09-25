/*Name: Kantimahanty Rohit, Roll No: MT2022149*/

//6.Write a simple program to create three threads

#include<pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>

#include<pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* mythread()
{
  printf("\nThe thread is %lu",pthread_self());
  
}

void main()
{
    pthread_t first_th,second_th,third_th;
    pthread_create(&first_th, NULL, mythread,NULL);
        // perror("Error while creating thread one");

    pthread_create(&second_th,NULL,mythread,NULL);
        // perror("Error while creating thread one");

    pthread_create(&third_th,NULL,mythread,NULL);
        // perror("Error while creating thread one");

    // Wait for the threads to terminate and then terminate the main process
    pthread_exit(NULL);   
}
