#include <stdio.h>
#include <stdbool.h>

int main(){
    int p, r;
    printf("Enter the number of processor and resources respectively: ");
    scanf("%d %d", &p, &r);
    int all[p][r], req[p][r], ca[r], ava[r], check[r], l = 0;
    bool finish[p], flag = true;

    for(int i = 0; i<p; i++)
        finish[i] = false;
    
    printf("Enter the elements of the Allocation matrix\n");
    for(int i = 0; i<p; i++){
        printf("Enter the resources for P%d ", i+1);
        for(int j = 0; j<r; j++){
            scanf("%d", &all[i][j]);
        }
    }

    for(int i = 0; i<r; i++){
        int sum = 0;
        for(int j = 0; j<p; j++){
            sum += all[j][i];
        }
        check[l] = sum;
        l++;
    }

    printf("Enter the elements of the Request matrix\n");
    for(int i = 0; i<p; i++){
        printf("Enter the resources for P%d ", i+1);
        for(int j = 0; j<r; j++){
            scanf("%d", &req[i][j]);
        }
    }

    printf("Enter the available matrix");
    for(int i = 0; i<r; i++)
        scanf("%d", &ava[i]);
    
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
    
    flag == true? printf("No Deadlock\n") : printf("Deadlock Occurs\n");
    
    return 0;
}