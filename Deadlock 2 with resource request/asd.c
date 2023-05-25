#include <stdio.h>
#include <stdbool.h>

int main(){
    int p, t1, t2;
    printf("Enter the value of the time stamp for Level 1 and Level 2: ");
    scanf("%d %d", &t1, &t2);
    printf("Enter the number of processes: ");
    scanf("%d", &p);
    int arr1[p][6], arr2[p][6], arr3[p][6];
    printf("Enter the arrival time of the processes: \n");
    for(int i = 0; i<p; i++){
        arr1[i][0] = i+1;
        printf("Enter the AT for P%d ", i+1);
        scanf("%d", &arr1[i][1]);
    }
    printf("Enter the burst time of the processes: \n");
    for(int i = 0; i<p; i++){
        printf("Enter the BT for P%d ", arr1[i][0]);
        scanf("%d", &arr1[i][2]);
    }

    for(int i = 1; i<p; i++){
        int key = arr1[i][1], k1 = arr1[i][0], k2 = arr1[i][2];
        int j = i-1;
        while(j>=0 && key<arr1[j][1]){
            arr1[j+1][2] = arr1[j][2];
            arr1[j+1][1] = arr1[j][1];
            arr1[j+1][0] = arr1[j][0];
            j--;
        }
        arr1[j+1][1] = key;
        arr1[j+1][0] = k1;
        arr1[j+1][2] = k2;
    }
    for(int i = 0; i<p; i++){
        arr1[i][5] = arr1[i][2];
    }
    int time = arr1[0][1], j = 0, k = 0;
    int flag = 0;
    printf("\nQ2: ");
    printf("\nP\tAT\tBT\tWT\nTAT\tRT");
    for(int i = 0; i<p; i++){
        if(arr1[i][5] <= t1){
            time += arr1[i][2];
            arr1[i][5] = 0;
            arr1[i][3] = time - arr1[i][1] - arr1[i][2];
            arr1[i][4] = time - arr1[i][1];
            printf("\n%d\t%d\t%d\t%d\t%d\t%d", arr2[i][0], arr2[i][1], arr2[i][2], arr2[i][3], arr2[i][4], arr2[i][5]);
        }
        else{
            arr2[j][3] = time;
            time += t1;
            arr1[i][5] -= t1;
            arr2[j][2] = arr1[i][5];
            arr2[j][5] = arr1[i][2];
            arr2[j][0] = arr1[i][0];
            j++;
            flag = 1;
        }
    }
    if(flag == 1){
        printf("\nQ2: ");
        printf("\nP\tAT\tBT\tWT\nTAT\tRT");
    }
    for(int i = 0; i<j; i++){
        if(arr2[i][5] <= t2){
            time += arr2[i][5];
            arr2[i][5] = 0;
            arr2[i][3] = time - t1 - arr2[i][2];
            arr2[i][4] = time - arr2[i][1];
            printf("\n%d\t%d\t%d\t%d\t%d\t%d", arr2[i][0], arr2[i][1], arr2[i][2], arr2[i][3], arr2[i][4], arr2[i][5]);
        }
        else{
            arr3[k][1] = time;
            time += t2;
            arr2[i][5] -=t2;
            arr3[k][2] = arr2[i][5];
            arr3[k][5] = arr3[k][2];
            arr3[k][0] = arr2[i][0];
            k++;
            flag = 2;
        }
    }

    {
        if(flag == 2)
            printf("\nFCFS: ");
    }

    for(int i = 0; i<k; i++){
        if(i == 0)
            arr3[i][6] = arr3[i][2]+time-t1-t2;
        else
            arr3[i][6] = arr3[i-1][6] + arr3[i][2];
    }
    for(int i = 0; i<k; i++){
        arr3[i][4] = arr3[i][6];
        arr3[i][3] = arr3[i][4] - arr3[i][2];
    }

    return 0;
}