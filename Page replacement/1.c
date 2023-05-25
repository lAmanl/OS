#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void FIFO(int f, int arr[], int n, int l){
    int frame[f], pf = 0;
    for(int i = 0; i<f; i++)
        frame[i] = -1;
    for(int i = 0; i<n; i++){
        bool flag = false;
        if(frame[l] == -1){
            frame[l] = arr[i];
            l = (l+1)%f;
            pf++;
        }
        else{
            for(int j = 0; j<f; j++){
                if(frame[j] == arr[i]){
                    flag = true;
                }
            }
            if(flag == true)
                continue;
            frame[l] = arr[i];
            pf++;
            l = (l+1)%f;
        }
    }
    printf("Page Fault: %d\n", pf);
    printf("Hit: %d\n", (n - pf));
}

void Optimal(int f, int arr[], int n, int l) {
    int pf = 0, hit = 0, frame[f], pd[100][f], di = 0;
    for (int i = 0; i < f; i++) 
        frame[i] = -1;
    for (int i = 0; i < n; i++) {
        int page = arr[i];
        int found = 0;

        for (int j = 0; j < f; j++) {
            if (frame[j] == page) {
                hit++;
                found = 1;
                break;
            }
        }

        if (!found) {
            if (di < f) {
                frame[di] = page;
                pf++;
                di++;
            } else {
                pf++;
                int fi[f];
                for (int j = 0; j < f; j++) {
                    fi[j] = n + 1;
                }
                for (int j = 0; j < f; j++) {
                    for (int k = i + 1; k < n; k++) {
                        if (frame[j] == arr[k]) {
                            fi[j] = k;
                            break;
                        }
                    }
                }
                int max = 0;
                for (int j = 1; j < f; j++) {
                    if (fi[j] > fi[max]) {
                        max = j;
                    }
                }
                for (int j = 0; j < f; j++) {
                    if (frame[max] == pd[j][max]) {
                        pd[j][max] = -1;
                        break;
                    }
                }
                frame[max] = page;
                di = max + 1;
            }
            for (int j = 0; j < f; j++) {
                pd[i][j] = frame[j];
            }
        }
    }
    printf("Page Fault: %d\n", pf);
    printf("Page Hit: %d\n", n - pf);
}

void LRU(int f, int arr[], int n, int l) {
    int frame[f], ch[f], pf = 0;
    bool flag;
    for (int i = 0; i < f; i++) {
        frame[i] = -1;
        ch[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        flag = false;
        for (int j = 0; j < f; j++) {
            if (frame[j] == arr[i]) {
                ch[j] = i + 1;
                flag = true;
                break;
            }
        }
        if (!flag) {
            int min = ch[0], index = 0;
            for (int j = 1; j < f; j++) {
                if (ch[j] < min) {
                    min = ch[j];
                    index = j;
                }
            }
            frame[index] = arr[i];
            ch[index] = i + 1;
            pf++;
        }
    }
    printf("Page Fault: %d\n", pf);
    printf("Hit: %d\n", n - pf);
}

int main(){
    int n,k,f, l = 0;
    printf("Enter the number of pages: ");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the size of frame: ");
    scanf("%d", &f);
    printf("Enter the 1 for FIFO, 2 for Optimal, 3 for LRU: ");
    scanf("%d", &k);
    if(k == 1)
        FIFO(f, arr, n, l);
    else if(k == 2)
        Optimal(f, arr, n, l);
    else if(k == 3)
        LRU(f, arr, n, l);
    else
        printf("Invalid Input\n");
    return 0;
}