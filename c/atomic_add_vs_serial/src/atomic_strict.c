/**
 * Create threads and each threads add the shared value atomically with most strong constraint.
 */
#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>


int NUM_THREADS = 10;
int INCREMENT_PER_THREAD = 10000000;

atomic_int cnt = 0;

void* increment_routine(void* arg) {
    int increment = INCREMENT_PER_THREAD;
    for (int i = 0; i < increment; i++) {
        atomic_fetch_add_explicit(
            &cnt, 1, memory_order_seq_cst);  // most strong constraint.
    }
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