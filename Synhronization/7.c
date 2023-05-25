#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (i+4)%N
#define RIGHT (i+1)%N

int state[i];
int phil[5] = {1,2,3,4,5};
sem_t S[N];
sem_t mutex;

void test(i){
    if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING){
        state[i] = EATING;
        //take
        //eat
        sem_post(&S[i]);
    }
}

void take(int i){
    sem_wait(&mutex);
    state[i] = HUNGRY;
    //hungry
    test(i);
    sem_post(&mutex);
    sem_wait(&S[i]);
}

void put(int i){
    sem_wait(&mutex);
    state[i] = THINKING;
    //put fork
    //thinking
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}

int main(){

}