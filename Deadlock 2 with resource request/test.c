#include <stdio.h>
#include <stdbool.h>

int main(){
    int p, r;
    printf("Enter the number of processes and resoures resp. :");
    scanf("%d %d", &p, &r);
    int all[p][r], max[p][r], req[p][r], ava[r], ca[r];
    bool finish[p];
    for(int i = 0; i<p; i++)
        finish[i] = false;
    printf("Enter the Allocation Matrix:\n");
    for(int i = 0; i<p; i++){
        printf("Enter P%d ", i+1);
        for(int j = 0; j<r; j++){
            scanf("%d", &all[i][j]);
        }
    }
    printf("Enter the Max Matrix\n");
    for(int i = 0; i<p; i++){
        printf("Enter P%d ", i+1);
        for(int j = 0; j<r; j++){
            scanf("%d", &max[i][j]);
            req[i][j] = max[i][j] - all[i][j];
        }
    }
    printf("Enter the available matrix ");
    for(int i = 0; i<r; i++){
        scanf("%d", &ava[i]);
    }
    for(int i = 0; i<r; i++){
        ca[i] = ava[i];
    }
    for(int k = 0; k<p; k++){
        for(int i = 0; i<p; i++){
            if(finish[i] == true)
                continue;
            int count = 0;
            for(int j = 0; j<r; j++){
                if(req[i][j] <= ca[j])
                    count++;
            }
            if(count == r){
                for(int j = 0; j<r; j++){
                    ca[j] += all[i][j];
                }
                finish[i] = true;
                printf("P%d ", i+1);
                break;
            }
        }
    }
    int c = 0;
    for(int i = 0; i<p; i++){
        if(finish[i] == false){
            printf("Deadlock occurs\n");
            break;
        }
        c++;
    }
    if(c == r)
        printf("Safe State Reached\n");
    int h, pirr, inc[r];
    bool flag1 = true;
    printf("Enter the number of time the request is made");
    scanf("%d", &h);
    for(int i = 0; i<h; i++){
        printf("Enter the process which is making the resource request: ");
        scanf("%d", &pirr);
        printf("Enter the Increamental resource request Matrix of P%d: ", pirr);
        for(int j = 0; j<r; j++){
            scanf("%d ", &inc[i]);
        }
        for(int j = 0; j<r; i++){
            if(inc[i] > ava[i] && inc[i] > req[pirr-1][i])
                flag1 = false;
        }
        if(flag1 = false){
            printf("Request cannot be accepted\n");
        }
        else{
            for(int j = 0; i<r; i++){
                all[pirr-1][j] += inc[j];
                ava[j] -= inc[j];
                req[pirr-1][j] += inc[j];
                ca[j] = ava[j];
            }
            for(int k = 0; k<p; k++){
                for(int l = 0; l<p; l++){
                    if(finish[l] == true)
                        continue;
                    int count = 0;
                    for(int j = 0; j<r; j++){
                        if(req[l][j] <= ca[j])
                            count++;
                    }
                    if(count == r){
                        for(int j = 0; j<r; j++){
                            ca[j] += all[l][j];
                        }
                        finish[l] = true;
                        printf("P%d ",l+1);
                        break;
                    }
                }
            }
            c = 0;
            for(int j = 0; j<r; j++){
                if(finish[j] == false){
                    printf("Deadlock occurs, Request cannot be granted\n");
                    break;
                }
                c++;
            }
            if(c==r)
                printf("Safe State reaches, Request approved\n");
        }
    }
}