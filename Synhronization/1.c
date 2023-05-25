#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int size = 5;
int count = 1;
sem_t empty, full;
pthread_mutex_t mutex;
int arr[5];
int o = 0, in = 0, out = 0;
int y = 1, u = 1;

void *prod(void *a){
    for (int i = 0; i < size; i++){
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        arr[in] = o;
        printf("Teacher %d inserts item %d\n", y, o++);
        in = (in + 1) % 5;
        y = (y + 1) % 21;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *cons(void *a){
    for (int i = 0; i < size; i++){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        printf("Student %d removes item %d\n", u, arr[out]);
        out = (out + 1) % 5;
        u = (u + 1) % 21;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    pthread_t t1[20], t2[20];
    sem_init(&empty, 0, 5);
    sem_init(&full, 0, 1);
    for (int i = 0; i < 20; i++)
        pthread_create(&t1[i], NULL, (void *)prod, (void *)&a[i]);
    for (int i = 0; i < 20; i++)
        pthread_create(&t2[i], NULL, (void *)cons, (void *)&a[i]);
    for (int i = 0; i < 20; i++)
        pthread_join(t1[i], NULL);
    for (int i = 0; i < 20; i++)
        pthread_join(t2[i], NULL);
    return 0;
}
