#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int f[5] = {0};
pthread_mutex_t mutex;

void think(int i){
    printf("Philosopher %d is Thinking\n", i);
}

void eat(int i){
    printf("Philosopher %d is Eating\n", i);
}

void take_forkl(int i){
    if (f[i] != 1){
        printf("Philosopher %d takes Left fork\n", i);
        f[i] = 1;
    }
}

void take_forkr(int i){
    if (f[i] != 1){
        printf("Philosopher %d takes Right fork\n", i);
        f[i] = 1;
    }
}

void put_forkr(int i){
    printf("Philosopher %d puts Right fork\n", i);
    f[i] = 0;
}

void put_forkl(int i){
    printf("Philosopher %d puts Left fork\n", i);
    f[i] = 0;
}

void *phil(int *i){
    int j = *((int *)i);
    while (1){
        think(j % 5);
        pthread_mutex_lock(&mutex);
        take_forkr(j % 5);
        take_forkl((j + 1) % 5);
        eat(j % 5);
        put_forkr(j % 5);
        put_forkl((j + 1) % 5);
        pthread_mutex_unlock(&mutex);
    }
}

int main(){
    pthread_t t[5];
    for (int i = 0; i < 5; i++)
        pthread_create(&t[i], NULL, (void *)phil, (void *)&i);
    for (int i = 0; i < 5; i++)
        pthread_join(t[i], NULL);
    return 0;
}
