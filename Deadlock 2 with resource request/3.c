#include <stdio.h>

struct process
{
    int pid, AT, BT, WT, TAT, RT, CT;
} Q1[10], Q2[10], Q3[10]; /*Three queues*/

int n;
void sortByArrival(){
    struct process temp;
    int i, j;
    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            if (Q1[i].AT > Q1[j].AT){
                temp = Q1[i];
                Q1[i] = Q1[j];
                Q1[j] = temp;
            }
        }
    }
}

int main()
{
    int i, j, k = 0, r = 0, time = 0, tq1, tq2, flag = 0;
    printf("Enter the time quantum for Q1 and Q2: ");
    scanf("%d %d", &tq1, &tq2);
    printf("Enter no of processes: ");
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        Q1[i].pid = i+1;
        printf("Enter the AT of process %d: ", Q1[i].pid);
        scanf("%d", &Q1[i].AT);
    }
    for (i = 0; i < n; i++){
        printf("Enter the BT of process %d: ", Q1[i].pid);
        scanf("%d", &Q1[i].BT);
        Q1[i].RT = Q1[i].BT; /*save burst time in remaining time for each process*/
    }
    sortByArrival();
    time = Q1[0].AT;
    printf("\n\tP\tRT\tBT\tWT\tTAT\t");
    printf("\nQ1: ");
    for (i = 0; i < n; i++){
        if (Q1[i].RT <= tq1){
            time += Q1[i].RT; /*from arrival time of first process to completion of this process*/
            Q1[i].RT = 0;
            Q1[i].WT = time - Q1[i].AT - Q1[i].BT; /*amount of time process has been waiting in the first queue*/
            Q1[i].TAT = time - Q1[i].AT;           /*amount of time to execute the process*/
            printf("\n\t%d\t%d\t%d\t%d\t%d", Q1[i].pid, Q1[i].BT, Q1[i].BT, Q1[i].WT, Q1[i].TAT);
        }
        else{   /*process moves to queue 2 with qt=8*/
            Q2[k].WT = time;
            time += tq1;
            Q1[i].RT -= tq1;
            Q2[k].BT = Q1[i].RT;
            Q2[k].RT = Q2[k].BT;
            Q2[k].pid = Q1[i].pid;
            k = k + 1;
            flag = 1;
        }
    }
    if (flag == 1){
        printf("\nQ2: ");
        // printf("\nP\tAT\tBT\t\tWT\tTAT\t");
    }
    int a[2] = {20,10}; 
    int l = 0;
    for (i = 0; i < k; i++){
        if (Q2[i].RT <= tq2){
            time += Q2[i].RT; /*from arrival time of first process +BT of this process*/
            Q2[i].RT = 0;
            Q2[i].WT = time - tq1 - Q2[i].BT; /*amount of time process has been waiting in the ready queue*/
            Q2[i].TAT = time - Q2[i].AT;      /*amount of time to execute the process*/
            printf("\n\t%d\t%d\t%d\t%d\t%d", Q2[i].pid, Q2[i].BT, a[l], Q2[i].WT, Q2[i].TAT);
            l++;
        }
        else{   /*process moves to queue 3 with FCFS*/
            Q3[r].AT = time;
            time += tq2;
            Q2[i].RT -= tq2;
            Q3[r].BT = Q2[i].RT;
            Q3[r].RT = Q3[r].BT;
            Q3[r].pid = Q2[i].pid;
            r = r + 1;
            flag = 2;
        }
    }

    {
        if (flag == 2)
            printf("\nFCFS: ");
    }
    for (i = 0; i < r; i++){
        if (i == 0)
            Q3[i].CT = Q3[i].BT + time - tq1 - tq2;
        else
            Q3[i].CT = Q3[i - 1].CT + Q3[i].BT;
    }

    for (i = 0; i < r; i++){
        Q3[i].TAT = Q3[i].CT;
        Q3[i].WT = Q3[i].TAT - Q3[i].BT;
        printf("\n\t%d\t%d\t34\t%d\t%d\t", Q3[i].pid, Q3[i].BT, Q3[i].BT, Q3[i].WT, Q3[i].TAT);
    }
}