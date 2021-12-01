#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int myglobal;

void* thread_function(void* arg)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        j = myglobal;
        j = j + 1;
        printf(". ~~~ inside thread_function~~~\n");
	printf("i, j = %d, %d\n", i,j);
        fflush(stdout);
	printf("start to sleep inside the thread_function\n");
	sleep(0.2);
	printf("done sleeping inside the thread_function\n");
	printf("i, j = %d, %d\n", i,j);
        myglobal = j;
	printf("\t\tjust updated myglobal using j's value of %d\n", j);
	printf("\t\tmyglobal has been updated to %d\n",myglobal);
	printf("\t\texiting the thread_function");
    }
    return NULL;
}

int main(void)
{
    pthread_t mythread;
    int i;
    if (pthread_create(&mythread, NULL, thread_function, NULL))
    {
        printf("error creating thread.");
        abort();
    }

    for (i = 0; i < 10; i++)
    {
        myglobal = myglobal + 1;
        printf("o ~~~ inside the main function ~~~~\n");
	printf("\t\tmyglobal has been updated to %d\n",myglobal);
        fflush(stdout);
        printf("start to sleep inside main()\n");
	sleep(0.1);
        printf("done sleeping inside main()\n");
    }

    if (pthread_join(mythread, NULL))
    {
        printf("error joining thread.");
        abort();
    }
    printf("\nmyglobal equals %d\n", myglobal);
    exit(0);
}
