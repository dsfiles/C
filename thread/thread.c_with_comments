/*
the following four c header files are needed to run the program
pthread.h is included to use the functions of the pthreads library such as pthread_create() and pthread_join()
stdlib.h is header file that provides access to the POSIX operating system API. it defines something like standard symbolic constants (like NULL) and types, and process related functions
stdio.h is standard input/output functions like printf()
*/
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// define a global variable that is shared by all the functions (or methods)
int myglobal;

// create a function to run in a thread
void* thread_function(void* arg)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        j = myglobal;
        j = j + 1;
        printf(".");  // display a period to the screen
        fflush(stdout);  // force the system to display the period (.) immediately
        sleep(1); // suspend execution for an interval of time (1 second in this example)
        myglobal = j;
    }
    return NULL; //return NULL (=0), you can think it doing nothing here
}

// main() function is the program entry point
int main(void)
{
    pthread_t mythread; // pthread_t is the data type used to uniquely identify a thread, often an integer 
    int i;
    /*
    The pthread_create() function starts a new thread in the calling process. For more information, visit:
    https://www.tutorialspoint.com/multithreading-in-c
    https://www.tutorialspoint.com/multithreading-in-c
    */
    if (pthread_create(&mythread, NULL, thread_function, NULL))
    {
        printf("error creating thread.");
        abort();
    }

    for (i = 0; i < 10; i++)
    {
        myglobal = myglobal + 1;
        printf("o");
        fflush(stdout);
        sleep(1);
    }

    //The pthread_join() function waits for mythread to terminate.
    if (pthread_join(mythread, NULL)) // if successful, pthread_join() will return 0
    {
        printf("error joining thread.");
        abort();
    }
    
    printf("\nmyglobal equals %d\n", myglobal); // at the very end, display the value of myglobal to the screen
    exit(0);
}
