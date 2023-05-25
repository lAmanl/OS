#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n][6];
    printf("Enter the Burst TIme and Arrival time: \n");
    for(int i = 0; i<n; i++){
        arr[i][0] = i+1;
        printf("AT BT P%d: ", arr[i][0]);
        scanf("%d %d", &arr[i][1] ,&arr[i][2]);
    }

    for(int i = 1; i<n; i++){
        int key = arr[i][1], k1 = arr[i][0], k2 = arr[i][2];
        int j = i-1;
        while(j>=0 && key<arr[j][1]){
            arr[j+1][2] = arr[j][2];
            arr[j+1][1] = arr[j][1];
            arr[j+1][0] = arr[j][0];
            j--;
        }
        arr[j+1][1] = key;
        arr[j+1][0] = k1;
        arr[j+1][2] = k2;
    }

    int st = arr[0][1];
    int a = 0;

    for(int i = 0; i<n; i++){
        if(arr[i][1]<=st){
            arr[i][3] = arr[i][2] + st;
            st = arr[i][3];
        }
        else{
            i--;
            a++;
            st++;
        }
    }

    for(int i = 0; i<n; i++){
        arr[i][4] = arr[i][3] - arr[i][1];
    }
    for(int i = 0; i<n; i++){
        arr[i][5] = arr[i][4] - arr[i][2];
    }

    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i<n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4], arr[i][5]);
    }

    double cpu = (double)((double)a/(double)arr[n-1][3]);

    printf("%lf", (double)(cpu*100));

    return 0;
}