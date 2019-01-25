
#include "header.h"
pthread_cond_t      condA  = PTHREAD_COND_INITIALIZER;
pthread_cond_t      condB  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t     mutex = PTHREAD_MUTEX_INITIALIZER;
#define MAX_COUNT 1000
int exit_flag;
int count = 1;

void *print_odd() {
    /* Wait for Odd Thread */
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (count % 2 == 0)
            pthread_cond_wait(&condA, &mutex);
        pthread_mutex_unlock(&mutex);
        pthread_mutex_lock(&mutex);
        printf("%d\n", count);
        /* Do your code */
        count++;
        pthread_cond_signal(&condB);
        if(count > MAX_COUNT){
            pthread_mutex_unlock(&mutex);
            exit_flag++;
            return NULL;
        }   
        pthread_mutex_unlock(&mutex);
        }
    }
void *print_even()
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (count % 2 != 0)
            pthread_cond_wait(&condB, &mutex);
        pthread_mutex_unlock(&mutex);
        pthread_mutex_lock(&mutex);
        printf("%d\n", count);
        count++;
        pthread_cond_signal(&condA);
        if (count > MAX_COUNT)
        {
            pthread_mutex_unlock(&mutex);
            exit_flag++;
            return NULL;
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    int n, ret;
    pthread_t odd, even;
    const pthread_attr_t detach;

    ret = pthread_create(&odd, NULL, print_odd, NULL);
    if (ret)
    {
        printf("Failed to launch odd thread");
        exit(EXIT_FAILURE);
    }
    ret = pthread_create(&even, NULL, print_even, NULL);
    if (ret)
    {
        printf("Failed to launch even thread");
        exit(EXIT_FAILURE);
    }

    if (pthread_detach(odd))
    {
        fprintf(stderr, "Error Detaching Odd thread\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_detach(even))
    {
        fprintf(stderr, "Error Detaching Even thread\n");
        exit(EXIT_FAILURE);
    }
    while (exit_flag < 2);
    return 0;
}