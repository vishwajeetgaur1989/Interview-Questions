
#include "header.h"
enum { STATE_A, STATE_B } state = STATE_A;
pthread_cond_t      condA  = PTHREAD_COND_INITIALIZER;
pthread_cond_t      condB  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t     mutex = PTHREAD_MUTEX_INITIALIZER;

void *print_odd() {
    int i;
    /* Wait for Odd Thread */
    pthread_mutex_lock(&mutex);
    while(state != STATE_A) 
        pthread_cond_wait(&condA, &mutex);
    pthread_mutex_unlock(&mutex);
 /* Do your code */
    for(i=1;i<100;i++) {
        if(i%2!=0) {
            printf("%d\n",i);
            pthread_mutex_lock(&mutex);
            state = STATE_B;
            pthread_cond_signal(&condB);
            pthread_mutex_unlock(&mutex);
        }
    }
}
void *print_even() {
    int i;
    pthread_mutex_lock(&mutex);
    while(state !=STATE_B) 
        pthread_cond_wait(&condB, &mutex);
    pthread_mutex_unlock(&mutex);    
    for(i=1;i<100;i++) {
        if(i%2==0) {
            printf("%d\n",i);
            pthread_mutex_lock(&mutex);
            state = STATE_A;
            pthread_cond_signal(&condA);
            pthread_mutex_unlock(&mutex);
        }
    }
}

int main() 
{
    int n, ret;
    pthread_t odd, even;

    //printf("Enter number of elements required to print !!");
    //scanf("%d", &n);

    ret = pthread_create(&odd, NULL, print_odd, NULL);
    if(ret) {
        printf("Failed to launch odd thread");
        exit(EXIT_FAILURE);
    }
    ret = pthread_create(&even, NULL, print_even, NULL);
    if(ret) {
        printf("Failed to launch even thread");
        exit(EXIT_FAILURE);
    }

    pthread_join(odd, NULL);
    pthread_join(even,NULL);
    #if 0
    if(pthread_detach(odd)) {
        fprintf(stderr, "Error joining thread\n");
        exit(EXIT_FAILURE);
    }
    if(pthread_detach(even)) {
       fprintf(stderr, "Error joining thread\n");
       exit(EXIT_FAILURE);
    }
    #endif
    return 0;
}