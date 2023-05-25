#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

struct input{
    int a, b, m[100], p[100];
};

void *first(void *rec){
    struct input *in = (struct input *)rec;
    bool d[in->a];
    bool w[in->b];
    for (int i = 0; i < in->a; i++)
        d[i] = false;
    for (int i = 0; i < in->b; i++)
        w[i] = false;

    printf("First fit\n");
    for (int i = 0; i < in->b; i++){
        for (int j = 0; j < in->a; j++){
            if (in->m[j] >= in->p[i] && d[j] == false){
                printf("\tProcess %d : Block %d Segmentation: %d\n", i + 1, j + 1, in->m[j] - in->p[i]);
                d[j] = true;
                w[i] = true;
                break;
            }
        }
    }

    printf("\n\tUnallocated processes: \n");
    for (int i = 0; i < in->b; i++){
        if (w[i] == false)
            printf("\t\tProcess %d\n", i + 1);
    }
    pthread_exit(NULL);
}

void *best(void *rec){
    struct input *in = (struct input *)rec;
    bool d[in->a], w[in->b];
    for (int i = 0; i < in->b; i++)
        w[i] = false;
    for (int i = 0; i < in->a; i++)
        d[i] = false;

    printf("\nBest fit\n");
    for (int i = 0; i < in->b; i++){
        int k, q;
        int min = 12345678;
        for (int j = 0; j < in->a; j++){
            if (in->m[j] - in->p[i] < min && d[j] == false && (in->m[j] - in->p[i]) >= 0){
                k = j;
                min = in->m[j] - in->p[i];
            }
        }

        if (q == k)
            continue;
        printf("\tProcess %d : Block %d Segmentation: %d \n", i + 1, k + 1, in->m[k] - in->p[i]);
        d[k] = true;
        w[i] = true;
        q = k;
    }

    printf("\n\tUnallocated processes: \n");
    for (int i = 0; i < in->b; i++){
        if (w[i] == false)
            printf("\t\tProcess %d\n", i + 1);
    }
    pthread_exit(NULL);
}

void *worst(void *rec){
    struct input *in = (struct input *)rec;
    bool d[in->a], w[in->b];
    for (int i = 0; i < in->b; i++)
        w[i] = false;
    for (int i = 0; i < in->a; i++)
        d[i] = false;

    printf("\nWorst fit\n");
    int q = 1234;
    for (int i = 0; i < in->b; i++){
        int k;
        int max = -12345678;
        for (int j = 0; j < in->a; j++){
            if (in->m[j] - in->p[i] > max && d[j] == false && (in->m[j] - in->p[i]) >= 0){
                k = j;
                max = in->m[j] - in->p[i];
            }
        }
        if (q == k)
            continue;
        printf("\tProcess %d : Block %d Segmentation: %d\n", i + 1, k + 1, in->m[k] - in->p[i]);
        d[k] = true;
        w[i] = true;
        q = k;
    }

    printf("\n\tUnallocated processes: \n");
    for (int i = 0; i < in->b; i++){
        if (w[i] == false)
            printf("\t\tProcess %d\n", i + 1);
    }
    pthread_exit(NULL);
}

int main(){
    FILE *fp = fopen("input.txt", "r");
    int a, b;
    fscanf(fp, "%d", &a);
    int m[a];
    bool d[a];

    for (int i = 0; i < a; i++){
        d[i] = false;
        fscanf(fp, "%d", &m[i]);
        printf("%d\n", m[i]);
    }

    fscanf(fp, "%d", &b);
    int p[b];

    for (int i = 0; i < b; i++)
        fscanf(fp, "%d", &p[i]);

    struct input in;
    in.a = a;
    in.b = b;
    for (int i = 0; i < a; i++)
        in.m[i] = m[i];

    for (int i = 0; i < b; i++)
        in.p[i] = p[i];

    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, (void *)first, &in);
    pthread_create(&t2, NULL, (void *)best, &in);
    pthread_create(&t3, NULL, (void *)worst, &in);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}