#include <stdio.h>
#include <stdbool.h>

void first(int a, int b, bool d[], int m[], int p[]){
    for(int i = 0; i<a; i++)
        d[i] = false;
    printf("First fit\n");
    for(int i = 0; i<b; i++){
        for(int j = 0; j<a; j++){
            if(m[j] >= p[i] && d[j] == false){
                printf("Process %d : Block %d Segmentation: %d\n", i+1, j+1, m[j] - p[i]);
                d[j] = true;
                break;
            }
        }
    }
}
void best(int a, int b, bool d[], int m[], int p[]){
    for(int i = 0; i<a; i++)
        d[i] = false;
    printf("\nBest fit\n");
    for(int i = 0; i<b; i++){
        int k,q;
        int min = 12345678;
        for(int j = 0; j<a; j++){
            if(m[j] - p[i] < min && d[j] == false && (m[j] - p[i]) >= 0 ){
                k = j;
                min = m[j] - p[i];
            }
        }
        if(q == k)
            continue;
        printf("Process %d : Block %d Segmentation: %d \n", i+1, k+1, m[k] - p[i]);
        d[k] = true;
        q = k;
    }
}
void worst(int a, int b, bool d[], int m[], int p[]){
    for(int i = 0; i<a; i++)
        d[i] = false;
    printf("\nWorst fit\n");
    for(int i = 0; i<b; i++){
        int k, q;
        int max = -12345678;
        for(int j = 0; j<a; j++){
            if(m[j] - p[i] > max && d[j] == false && (m[j] - p[i]) >= 0 ){
                k = j;
                max = m[j] - p[i];
            }
        }
        if(q == k)
            continue;
        printf("Process %d : Block %d Segmentation: %d\n", i+1, k+1, m[k] - p[i]);
        d[k] = true;
        q = k;
    }
}

int main(){
    int a, b, j = 0;
    printf("Enter total Memory Partitions: ");
    scanf("%d", &a);
    int m[a];
    bool d[a];
    printf("Enter the size of each Memory Partition: ");
    for(int i = 0; i<a; i++){
        d[i] = false;
        scanf("%d", &m[i]);
    }
    printf("Enter number of processes to be allocated: ");
    scanf("%d", &b);
    int p[b];
    printf("Enter the size of the processes to be allocated: ");
    for(int i = 0; i<b; i++)
        scanf("%d", &p[i]);
    first(a,b,d,m,p);
    best(a,b,d,m,p);
    worst(a,b,d,m,p);
    return 0;
}