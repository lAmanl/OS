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
    int q = 1245;
    for(int i = 0; i<b; i++){
        int k;
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
    FILE *fp = fopen("input.txt","r");
    int a, b;
    fscanf(fp, "%d", &a);
    bool d[a];
    int m[a];
    for(int i = 0; i<a; i++){
        d[i] = false;
        fscanf(fp, "%d", &m[i]);
    }
    fscanf(fp, "%d", &b);
    int p[b];
    for(int i = 0; i<b; i++){
        fscanf(fp, "%d", p[i]);
    }
    first(a,b,d,m,p);
    best(a,b,d,m,p);
    worst(a,b,d,m,p);
    return 0;
}