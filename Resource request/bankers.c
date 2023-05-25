#include <stdio.h>
#include <stdbool.h>

struct input{
    int p, r, req[100][100], ca[100], all[100][100], check[100], ava[100];
    bool finish[100];
}in;

void *bankers(void *a){
    struct input *in = (struct input *)a;
    for(int k = 0; k<in.p; k++){
        for(int i = 0; i<in.p; i++){
            if(in.finish[i] == true)
                continue;
            int count = 0;
            for(int j = 0; j<r; j++){
                if(in.req[i][j]<=in.ca[j])
                    count++;
            }
            if(count == in.r){
                for(int j = 0; j<in.r; j++){
                    in.ca[j] += in.all[i][j];
                }
                in.finish[i] = true;
                printf("P%d ", i+1);
                break;
            }
        }
    }

    for(int i = 0; i<in.r; i++)
        in.ca[i] = in.ca[i] - in.ava[i];

    for(int i = 0; i<in.r; i++){
        if(in.check[i] != ca[i])
            flag = false;
    }
    
    flag == true? printf("No Deadlock\n") : printf("Deadlock Occurs\n");
}

int main(){
    pthread_t t1;
    int p, r;
    printf("Enter the number of processor and resources respectively: ");
    scanf("%d %d", &in.p, &in.r);
    // int all[p][r], max[p][r], req[p][r], ca[r], ava[r], check[r], l = 0;
    // bool finish[p], flag = true;

    for(int i = 0; i<p; i++)
        in.finish[i] = false;
    
    printf("Enter the elements of the Allocation matrix\n");
    for(int i = 0; i<p; i++){
        printf("Enter the resources for P%d ", i+1);
        for(int j = 0; j<r; j++){
            scanf("%d", &in.all[i][j]);
        }
    }

    for(int i = 0; i<r; i++){
        int sum = 0;
        for(int j = 0; j<p; j++){
            sum += in.all[j][i];
        }
        in.check[l] = sum;
        l++;
    }

    printf("Enter the elements of the Max matrix\n");
    for(int i = 0; i<p; i++){
        printf("Enter the resources for P%d ", i+1);
        for(int j = 0; j<r; j++){
            scanf("%d", &max[i][j]);
            in.req[i][j] = max[i][j] - all[i][j];
        }
    }

    printf("Enter the available matrix");
    for(int i = 0; i<r; i++)
        scanf("%d", &in.ava[i]);
    
    for(int i = 0; i<r; i++)
        in.ca[i] = ava[i];

    pthread_create(&t1, NULL, (void *)bankers, &in);   
    
    return 0;
}