/**
 * Create threads and each threads add with a global big lock.
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


int NUM_THREADS = 10;
int INCREMENT_PER_THREAD = 10000000;
pthread_mutex_t lock;

int cnt = 0;

void* increment_routine(void* arg) {
    int increment = INCREMENT_PER_THREAD;

    pthread_mutex_lock(&lock);
    
    for (int i = 0; i < increment; i++) {
        cnt++;
    }

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(int argc, char const* argv[]) {
    // read arguments
    if (argc == 3) {
        NUM_THREADS = atoi(argv[1]);
        INCREMENT_PER_THREAD = atoi(argv[2]);
    }

    // create threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_routine, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("cnt: %d\n", cnt);
    return 0;
}