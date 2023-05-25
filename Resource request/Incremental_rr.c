#include <stdio.h>
#include <stdbool.h>

int main(){
    int p, r;
    printf("Enter the number of processor and resources respectively: ");
    scanf("%d %d", &p, &r);
    int all[p][r], max[p][r], req[p][r], ca[r], ava[r], check[r], l = 0, inc[r], pirr;
    bool finish[p], flag = true, flag1 = true;

    for(int i = 0; i<p; i++)
        finish[i] = false;
    
    printf("Enter the elements of the Allocation matrix\n");
    for(int i = 0; i<p; i++){
        printf("Enter the resources for P%d ", i+1);
        for(int j = 0; j<r; j++){
            scanf("%d", &all[i][j]);
        }
    }

    

    printf("Enter the elements of the Max matrix\n");
    for(int i = 0; i<p; i++){
        printf("Enter the resources for P%d ", i+1);
        for(int j = 0; j<r; j++){
            scanf("%d", &max[i][j]);
            req[i][j] = max[i][j] - all[i][j];
        }
    }

    printf("Enter the available matrix");
    for(int i = 0; i<r; i++)
        scanf("%d", &ava[i]);
    
    printf("Enter the process which is making the Incremental request:");
    scanf("%d", &pirr);

    printf("Enter the Incremental resource request matrix of P%d:", pirr);
    for(int i = 0; i<r; i++)
        scanf("%d", &inc[i]);

    for(int i = 0; i<r; i++){
        if(inc[i] <= ava[i] && inc[i] <= req[pirr-1][i])
            continue;
        else
            flag1 = false;
    }

    if(flag1 == false){
        printf("Request cannot be completed\n");
    }
    else{
        for(int i = 0; i<r; i++){
            all[pirr-1][i] += inc[i];
            ava[i] -= inc[i];
            req[pirr-1][i] -= inc[i];
        }

        for(int i = 0; i<r; i++){
            int sum = 0;
            for(int j = 0; j<p; j++){
                sum += all[j][i];
            }
            check[l] = sum;
            l++;
        }

        for(int i = 0; i<r; i++)
            ca[i] = ava[i];
        for(int k = 0; k<p; k++){
            for(int i = 0; i<p; i++){
                if(finish[i] == true)
                    continue;
                int count = 0;
                for(int j = 0; j<r; j++){
                    if(req[i][j]<=ca[j])
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

        for(int i = 0; i<r; i++)
            ca[i] = ca[i] - ava[i];

        for(int i = 0; i<r; i++){
            if(check[i] != ca[i])
                flag = false;
        }
        flag == true? printf("\nSafe State reached, therefore request P%d can be done\n", pirr) : printf("Deadlock Occurs\n");
    }
    
    return 0;
}