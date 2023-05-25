#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int p, r;
    FILE* ptr;
    ptr = fopen("Input.txt", "r");
    char ch;
    ch = fgetc(ptr);
    printf("%c", ch);
    p = (int)ch - (int)('0');
    ch = fgetc(ptr);
    ch = fgetc(ptr);
    printf("%c", ch);
    r = (int)ch - (int)('0'); 
    int all[p][r], max[p][r], req[p][r], ca[r], ava[r], check[r], l = 0;
    bool finish[p], flag = true;

    for(int i = 0; i<p; i++)
        finish[i] = false;
    
    for(int i = 0; i<p; i++){
        for(int j = 0; j<r; j++){
            ch = fgetc(ptr);
            ch = fgetc(ptr);
            printf("%c", ch);
            all[i][j] = (int)ch - (int)('0');
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

    for(int i = 0; i<p; i++){
        for(int j = 0; j<r; j++){
            ch = fgetc(ptr);
            ch = fgetc(ptr);
            max[i][j] = (int)ch - (int)('0');
            req[i][j] = max[i][j] - all[i][j];
        }
    }

    for(int i = 0; i<r; i++){
        ch = fgetc(ptr);
        ch = fgetc(ptr);
        ava[i] = (int)ch - (int)('0');
    }

    for(int i = 0; i<r; i++)
        ca[i] = ava[i];
    printf("\n");
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
    
    flag == true? printf("\nNo Deadlock\n") : printf("\nDeadlock Occurs\n");
    fclose(ptr);
    return 0;
}