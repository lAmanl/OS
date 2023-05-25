#include<stdio.h>
#include<stdbool.h>

int main(){
    int n, low = 1000;
    printf("Enter the Number of Processes: ");
    scanf("%d", &n);
    int arr[n][6];
    printf("Enter the AT and BT of following\n");
    for(int i = 0; i<n; i++){
        arr[i][0] = i+1;
        printf("AT BT of P%d", arr[i][0]);
        scanf("%d %d", &arr[i][1], &arr[i][2]);
        if(arr[i][1] <= low)
            low = arr[i][1];
    }

    for(int i = 1; i<n; i++){
        int key = arr[i][2], k1 = arr[i][0], k2 = arr[i][1];
        int j = i-1;
        while(j>=0 && key<arr[j][2]){
            arr[j+1][2] = arr[j][2];
            arr[j+1][1] = arr[j][1];
            arr[j+1][0] = arr[j][0];
            j--;
        }
        arr[j+1][2] = key;
        arr[j+1][0] = k1;
        arr[j+1][1] = k2;
    }
    
    int st = arr[0][1];
    int a = 0;

    for(int i = 0; i<n; i++){
        if(arr[i][1] <= st){
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

    printf("P\tAT\tBT\tCT\tTAT\n");
    for(int i = 0; i<n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4]);
    }

    double cpu = (double)((double)a/(double)arr[n-1][3]);

    printf("%lf", (double)(cpu*100));
}