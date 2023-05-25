#include <stdio.h>
#include <stdbool.h>

int main(){
    int p, r;
    printf("Enter the processes and resources: ");
    scanf("%d %d", &p, &r);
    int all[p][r], max[p][r], req[p][r], ava[r], ca[r], finish[p], count;
    printf("Enter the Allocation Matrix\n");
    for(int i = 0; i<p; i++){
        printf("Enter P%d: ", i+1);
        for(int j = 0; j<r; j++){
            scanf("%d", &all[i][j]);
        }
    }
    printf("Enter the Max Matrix\n");
    for(int i = 0; i<p; i++){
        printf("Enter P%d: ", i+1);
        for(int j = 0; j<r; j++){
            scanf("%d", &max[i][j]);
            req[i][j] = max[i][j] - all[i][j];

        }
    }
    printf("Enter the Available Matrix");
    for(int i = 0; i<r; i++){
        scanf("%d", &ava[i]);
        ca[i] = ava[i];
    }

    for(int k = 0; k<p; k++){
        for(int i = 0; i<p; i++){
            if(finish[i] == true)
                continue;
            count = 0;
            for(int j = 0; j<r; j++){
                if(req[i][j] <= ca[j])
                    count++;
            }
            if(count == r){
                finish[i] = true;
                for(int j = 0; j<r; j++){
                    ca[j] += all[i][j];
                }
                printf("P%d ",i+1);
                break;
            }
        }
    }

    return 0;
}