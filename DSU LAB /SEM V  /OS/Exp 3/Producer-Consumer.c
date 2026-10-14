#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // For sleep function
#define BUFFER_SIZE 10
#define NUM_ITEMS 20
// Buffer and related variables
int buffer[BUFFER_SIZE];
int in = 0; // Index for the next item to be produced
int out = 0; // Index for the next item to be consumed
int count = 0; // Number of items in the buffer
pthread_mutex_t mutex; // Mutex to protect buffer
pthread_cond_t not_full; // Condition variable to signal when buffer is not full
pthread_cond_t not_empty; // Condition variable to signal when buffer is not empty
// Producer function
void *producer(void *param) {
for (int i = 0; i < NUM_ITEMS; i++) {
// Produce an item
int item = rand() % 100;
pthread_mutex_lock(&mutex);
// Wait if the buffer is full
while (count == BUFFER_SIZE) {
pthread_cond_wait(&not_full, &mutex);
}
// Add the item to the buffer
buffer[in] = item;
printf("Produced: %d\n", item);
in = (in + 1) % BUFFER_SIZE;
count++;
// Signal that there is a new item in the buffer
pthread_cond_signal(&not_empty);
// Unlock the buffer
pthread_mutex_unlock(&mutex);
// Simulate production time
sleep(rand() % 2);
}
return NULL;
}
// Consumer function
void *consumer(void *param) {
for (int i = 0; i < NUM_ITEMS; i++) {
// Lock the buffer
pthread_mutex_lock(&mutex);
// Wait if the buffer is empty
while (count == 0) {
pthread_cond_wait(&not_empty, &mutex);
}
// Remove the item from the buffer
int item = buffer[out];
printf("Consumed: %d\n", item);
out = (out + 1) % BUFFER_SIZE;
count--;
// Signal that there is a new empty slot in the buffer
pthread_cond_signal(&not_full);
// Unlock the buffer
pthread_mutex_unlock(&mutex);
// Simulate consumption time
sleep(rand() % 2);
}
return NULL;
}
int main() {
pthread_t prod, cons;
// Initialize mutex and condition variables
pthread_mutex_init(&mutex, NULL);
pthread_cond_init(&not_full, NULL);
pthread_cond_init(&not_empty, NULL);
// Create producer and consumer threads
pthread_create(&prod, NULL, producer, NULL);
pthread_create(&cons, NULL, consumer, NULL);
// Wait for threads to complete
pthread_join(prod, NULL);
pthread_join(cons, NULL);
// Cleanup
pthread_mutex_destroy(&mutex);
pthread_cond_destroy(&not_full);
pthread_cond_destroy(&not_empty);
return 0;
}
