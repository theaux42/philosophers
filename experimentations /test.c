#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define NUM_THREADS 180
volatile int IS_READY = 0;

void* thread_function(void* arg) {
    while (!IS_READY) ;
    int thread_id = *((int*)arg);
    struct timeval start;
    gettimeofday(&start, NULL);

    printf("Thread %d started at %ld\n", thread_id, start.tv_usec);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int rc;

    // Créer les threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        rc = pthread_create(&threads[i], NULL, thread_function, (void*)&thread_ids[i]);
        usleep(1000); // Attendre 1ms pour éviter que les threads ne soient créés en même temps
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    // Définir IS_READY à 1 pour commencer l'exécution des threads
    IS_READY = 1;

    // Attendre que tous les threads soient terminés
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have been created and executed.\n");
    pthread_exit(NULL);
}