#include <stdio.h>

int main(){
    int p, r;
    printf("ENter the number of processes and resources respectively: ");
    scanf("%d %d", &p, &r);
    int reso[p][r], m[r];
    printf("Enter the Resource Matrix: \n");
    for (int i = 0; i < p; i++){
        printf("Enter the resources for P%d ", i + 1);
        for (int j = 0; j < r; j++){
            scanf("%d", &reso[i][j]);
        }
    }
    for(int i = 0; i<r; i++){
        m[i] = 0;
    }
    for(int i = 0; i<r; i++){
        for(int j = 0; j<p; j++){
            m[i] += reso[j][i]-1;
        }
    }
    for(int i = 0; i<r; i++){
        printf("Minimum requirement for the resource R%d is: %d\n", i, m[i]+1);
    }
    return 0;
}