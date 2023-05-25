#include <stdio.h>
#include <stdbool.h>

void first(int a, int b, bool d[], int m[], int p[]){
    for(int i = 0; i<a; i++)
        d[i] = false;
    printf("First Fit: \n");
    for(int i = 0; i<b; i++){
        for(int j = 0; j<a; j++){
            if(m[j] >= p[i] && d[j] == false){
                printf("Process %d: Block %d\n", i+1, j+1);
                d[j] = true;
                break;
            }
        }
    }
}

void best(int a, int b, bool d[], int m[], int p[]){
    int q = 1234411;
    for(int i = 0; i<a; i++)
        d[i] = false;
    printf("Best Fit: \n");
    for(int i = 0; i<b; i++){
        int k;
        int min = 123456;
        for(int j = 0; j<a; j++){
            if(m[j] - p[i] < min && d[j] == false && (m[j] - p[i]) >= 0){
                k = j;
                min = m[j] - p[i];
            }
        }
        if(q == k)
            continue;
        printf("Process %d: Block %d\n", i+1, k+1);
        d[k] = true;
        q = k;
    }
}

void worst(int a, int b, bool d[], int m[], int p[]){
    int q = 124245132;
    for(int i = 0; i<a; i++)
        d[i] = false;
    printf("Best Fit: \n");
    for(int i = 0; i<b; i++){
        int k;
        int max = 123456;
        for(int j = 0; j<a; j++){
            if(m[j] - p[i] > max && d[j] == false && (m[j] - p[i]) >= 0){
                k = j;
                max = m[j] - p[i];
            }
        }
        if(q == k)
            continue;
        printf("Process %d: Block %d\n", i+1, k+1);
        d[k] = true;
        q = k;
    }
}

int main(){
    int a, b, j = 0;
    printf("Enter the number Memory partitions: ");
    scanf("%d", &a);
    int m[a];
    bool d[a];
    printf("Enter the size of each memory partition: ");
    for(int i = 0; i<a; i++){
        d[i] = false;
        scanf("%d", &m[i]);
    }
    printf("Enter number of processes to be allocated: ");
    scanf("%d", &b);
    int p[b];
    printf("Enter the size of each process: ");
    for(int i = 0; i<b; i++){
        scanf("%d", &p[i]);
    }
    first(a,b,d,m,p);
    best(a,b,d,m,p);
    worst(a,b,d,m,p);
    return 0;
}