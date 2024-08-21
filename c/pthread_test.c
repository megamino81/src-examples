#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_BUF   (1*1024*1024)
#define MAX_STACK (2*1024*1024)
#define MAX_THREAD 100000

void *
thread_start (void *arg)
{
    char buf[MAX_BUF];
    memset (buf, 0, sizeof (buf));
    strcpy (buf, "Hello,world!");

    while (1)
    {
        printf ("Thread %d \n", getpid ());
        sleep (3);
    }

    return NULL;
}

int
main (int argc, char **argv)
{
    int perr;
    pthread_t thread[MAX_THREAD];
    pthread_attr_t *test_attr;
    printf ("pid = %d\n", getpid ());

    test_attr = (pthread_attr_t *)malloc(sizeof(pthread_attr_t) * MAX_THREAD);

    for (int i = 0; i < MAX_THREAD; i++)
    {
        printf ("======== %d ===========\n", i);
        perr = pthread_attr_init (test_attr);
        if (perr)
        {
            printf ("Posix Error = %d \n", perr);
            return -1;
        }
#if 1
        perr = pthread_attr_setstacksize (test_attr, MAX_STACK);
        if (perr)
        {
            printf ("pthread_attr_setstacksize Error = %d \n", perr);
            return -1;
        }
#endif
        printf ("pthread_create start\n");
        perr = pthread_create (&thread[i], test_attr, thread_start, NULL);
        printf ("pthread_create done\n");
        if (perr)
        {
            printf ("pthread_create Error = %d \n", perr);
            return -1;
        }
        test_attr ++;
    }
    pause ();

    return 0;
}
