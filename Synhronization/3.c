#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int f[10] = {0};

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

int available(int i){
    if (f[i] != 1)
        return 1;
    else
        return 0;
}

void *phil(int *i){
    int j = *((int *)i);
    while (1){
        think(j % 5);
        take_forkr(j % 5);
        if (available((j + 1) % 5) == 0){
            take_forkl((j + 1) % 5);
            eat(j % 5);
            put_forkr(j % 5);
            put_forkl((j + 1) % 5);
        }
        else{
            put_forkr(j % 5);
            int k = rand()%20;
            sleep(k);
        }
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