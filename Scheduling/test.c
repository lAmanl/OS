#include <stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
int x = 1, y = 1;
int count = 1;
sem_t wrt;
sem_t mutex;
int numreader = 0;

void *wr(void *a){
    sem_wait(&wrt);
    count++;
    printf("Writer%d updated count to %d\n", x ,count);
    x++;
    sem_post(&wrt);
}

void *wr1(void *a){
    sem_wait(&wrt);
    count--;
    printf("Writer%d updated count to %d\n", x ,count);
    x++;
    sem_post(&wrt);
}

void *rd(void *a){
    sem_wait(&mutex);
    numreader++;
    
    if(numreader==1)
        sem_wait(&wrt);
        
    sem_post(&mutex);
    printf("Reader%d read count as %d\n", y,count);
    y++;
    sem_wait(&mutex);
    usleep(3);
    numreader--;
    
    if(numreader==0)
        sem_post(&wrt);
        
    sem_post(&mutex);
    return NULL;
}

int main() {
    int r = 1, w = 1;
    int *arg = malloc(sizeof(*arg));
    pthread_t t1[r], t2[w];
    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);
    for(int i=0;i<w;i++){
        *arg = i-1;
        pthread_create(&t2[i],NULL,(void * )wr,arg);
        pthread_create(&t1[i],NULL,(void *)rd,arg);
        pthread_create(&t2[i],NULL,(void * )wr1,arg);
        pthread_create(&t1[i],NULL,(void *)rd,arg);
    } 
    for(int i=0;i<r;i++)
        pthread_join(t1[i],NULL);    
    for(int i=0;i<w;i++)
        pthread_join(t2[i],NULL);
    return 0;
}