#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Function to be executed by the thread
void *thread_function(void *arg) {
    int *id = (int *)arg;
    printf("Thread %d is running\n", *id);
    sleep(3); // Simulate some work
    printf("Thread %d finished\n", *id);
    pthread_exit(NULL);
}

int main() {
    pthread_t tid1, tid2;
    int id1 = 1, id2 = 2;

    // Create threads
    pthread_create(&tid1, NULL, thread_function, &id1);
    pthread_create(&tid2, NULL, thread_function, &id2);

    // Join threads
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // Check if two thread identifiers are equal
    if (pthread_equal(tid1, tid2))
        printf("Threads are equal\n");
    else
        printf("Threads are not equal\n");

    printf("Main thread exiting\n");
    pthread_exit(NULL);
}

