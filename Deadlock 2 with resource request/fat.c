




















































// incremental
#include <stdio.h>
#include <stdbool.h>
int main()
{
    int p, r;
    printf("Enter the number of processor and resources respectively: ");
    scanf("%d %d", &p, &r);
    int all[p][r], max[p][r], req[p][r], ca[r], ava[r], check[r], l = 0, inc[r], pirr;
    bool finish[p], flag = true, flag1 = true;
    for (int i = 0; i < p; i++)
        finish[i] = false;
    printf("Enter the elements of the Allocation matrix\n");
    for (int i = 0; i < p; i++)
    {
        printf("Enter the resources for P%d ", i + 1);
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &all[i][j]);
        }
    }
    printf("Enter the elements of the Max matrix\n");
    for (int i = 0; i < p; i++)
    {
        printf("Enter the resources for P%d ", i + 1);
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &max[i][j]);
            req[i][j] = max[i][j] - all[i][j];
        }
    }
    printf("Enter the available matrix");
    for (int i = 0; i < r; i++)
        scanf("%d", &ava[i]);

    for (int i = 0; i < r; i++)
    {
        ca[i] = ava[i];
    }
    for (int k = 0; k < p; k++)
    {
        for (int i = 0; i < p; i++)
        {
            if (finish[i] == true)
                continue;
            int count = 0;
            for (int j = 0; j < r; j++)
            {
                if (req[i][j] <= ca[j])
                    count++;
            }
            if (count == r)
            {
                for (int j = 0; j < r; j++)
                {
                    ca[j] += all[i][j];
                }
                finish[i] = true;
                printf("P%d ", i + 1);
                break;
            }
        }
    }

    int c = 0;

    for (int i = 0; i < p; i++)
    {
        if (finish[i] == false)
        {
            printf("\nDeadlock Occurs\n");
            break;
        }
        c++;
    }

    if (c == p)
        printf("\nSafe State Reached\n");

    int h;

    printf("Enter the number of times the request is made: ");
    scanf("%d", &h);
    for (int i = 0; i < h; h++)
    {
        printf("Enter the process which is making the Incremental request: ");
        scanf("%d", &pirr);
        printf("Enter the Incremental resource request matrix of P%d: ", pirr);
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &inc[j]);
        }
        for (int j = 0; j < r; j++)
        {
            if (inc[j] <= ava[j] && inc[j] <= req[pirr - 1][j])
                continue;
            else
                flag1 = false;
        }
        if (flag1 == false)
        {
            printf("Request cannot be completed\n");
        }
        else
        {
            for (int j = 0; j < r; j++)
            {
                all[pirr - 1][j] += inc[j];
                ava[i] -= inc[j];
                req[pirr - 1][j] -= inc[j];
            }
            for (int j = 0; j < r; j++)
            {
                ca[j] = ava[j];
            }
            for (int k = 0; k < p; k++)
            {
                for (int l = 0; l < p; l++)
                {
                    if (finish[l] == true)
                        continue;
                    int count = 0;
                    for (int j = 0; j < r; j++)
                    {
                        if (req[l][j] <= ca[j])
                            count++;
                    if (count == r)
                    {
                        for (int j = 0; j < r; j++)
                        {
                            ca[j] += all[i][j];
                        }
                        finish[l] = true;
                        printf("P%d ", l + 1);
                        break;
                    }
                }
            }

            int c = 0;

            for (int j = 0; j < r; j++)
            {
                if (finish[j] == false)
                {
                    printf("\nDeadlock Occurs, Request cannot be granted\n");
                    break;
                }
                c++;
            }

            if (c == r)
                printf("Safe State Reached, Request approved\n");
        }
    }
    return 0;
}





//FCFS
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







//NON-PREEMPTIVE SJF
#include <stdio.h>
#include <stdlib.h>
int main(){
printf("SANIDHYA GUPTA 21BRS1610\n");
char t[10];
int
arr[10],pn[10],bur[10],star[10],finish[10],tat[10],wt[10],check[10],i,j,n,temp;
int totwt=0,tottat=0,big=0;
printf("Enter the number of processes:");
scanf("%d",&n);
for(i=0; i<n; i++)
{
printf("Enter the ProcessName, Arrival Time& Burst Time:");
scanf("%d%d%d",&pn[i],&arr[i],&bur[i]);
check[i]=bur[i];
fflush(stdin);
}
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
if(bur[i]<bur[j])
{
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
temp=bur[i];
bur[i]=bur[j];
bur[j]=temp;
temp=pn[i];
pn[i]=pn[j];
pn[j]=temp;
}
}
}
int c=0;
for(i=0; c<n ; i++)
{
for(j=0; j<n; j++)
{
if(arr[j]<=i && check[j]!=0)
{
star[j]=i;
wt[j]=star[j]-arr[j];
finish[j]=star[j]+bur[j];
tat[j]=finish[j]-arr[j];
check[j]=0;
i=finish[j]-1;
c++;
break;
}
}
}
printf("\nPName Arrtime Burtime WaitTime Start TAT Finish");
for(i=0; i<n; i++)
{
printf("\n%d\t%3d\t%3d\t%3d\t%3d\t%6d\t%6d",pn[i],arr[i],bur[i],wt[i],star[i],tat[i],f
inish[i]);
totwt+=wt[i];
tottat+=tat[i];
}
printf("\nAverage Waiting time:%f",(float)totwt/n);
printf("\nAverage Turn Around Time:%f",(float)tottat/n);
return 0;
}




//
// PREMPITIVE SJF:-
#include <stdio.h>
#include <stdlib.h>
int main(){
printf("SANIDHYA GUPTA 21BRS1610");
int arrival_time[10], burst_time[10], temp[10];
int i, smallest, count = 0, time, limit;
double wait_time = 0, turnaround_time = 0, end;
float average_waiting_time, average_turnaround_time;
printf("\nEnter the Total Number of Processes:\t");
scanf("%d", &limit);
printf("\nEnter Details of %d Processes\n", limit);
for(i = 0; i < limit; i++)
{
printf("\nEnter Arrival Time:\t");
scanf("%d", &arrival_time[i]);
printf("Enter Burst Time:\t");
scanf("%d", &burst_time[i]);
temp[i] = burst_time[i];
}
burst_time[9] = 9999;
for(time = 0; count != limit; time++)
{
smallest = 9;
for(i = 0; i < limit; i++)
{
if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest]
&& burst_time[i] > 0)
{
smallest = i;
}
}
burst_time[smallest]--;
if(burst_time[smallest] == 0)
{
count++;
end = time + 1;
wait_time = wait_time + end - arrival_time[smallest] -
temp[smallest];
turnaround_time = turnaround_time + end - arrival_time[smallest];
}
}
average_waiting_time = wait_time / limit;
average_turnaround_time = turnaround_time / limit;
printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);
return 0;
}






// NON PREMPITIVE PRIORITY:-
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 30
int main()
{
printf("SANIDHYA GUPTA 21BRS1610\n");
int i,k=1,n,t,b=0,min,temp[max],bt[max],wt[max],at[max],pr[max],tat[max];
float avgwt=0, avgtat=0;
printf("Enter the no of process\n");
scanf("%d",&n);
for(int i=0;i<n;i++){
printf("Enter the Burst Time, Arrival Time & Priority :");
scanf("%d %d %d",&bt[i], &at[i], &pr[i]);
}
for(int i=0; i<n; i++){
for(int j=0; j<n; j++){
if(at[i]<at[j]){
t=at[j];
at[j]=at[i];
at[i]=t;
t=bt[j];
bt[j]=bt[i];
bt[i]=t;
}
}
}
for (int j=0;j<n;j++){
b=b+bt[j];
min=bt[k];
for(int i=k;i<n;i++){
min=pr[k];
if(b>at[i]){
if(pr[i]<min){
t=at[k];
at[k]=at[i];
at[i]=t;
t=bt[k];
bt[k]=bt[i];
bt[i]=t;
t=pr[k];
pr[k]=pr[i];
pr[i]=t;
}
}
}
k++;
}
temp[0]=0;
printf("process\t burst time\t arrival time\t priority\t waiting time\t turn
around time\n");
for (int i=0;i<n;i++){
wt[i]=0;
tat[i]=0;
temp[i+1]=temp[i]+bt[i];
wt[i]=temp[i]-at[i];
tat[i]=wt[i]+bt[i];
avgwt=avgwt+wt[i];
avgtat=avgtat+tat[i];
printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],at[i],pr[i],wt[i],tat[i]);
}
avgwt=avgwt/n;
avgtat=avgtat/n;
printf("average waiting time= %f\n",avgwt);
printf("average turn around time= %f\n",avgtat);
return 0;
}






// PREMPITIVE PRIORITY:-
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int
arr[10],pn[10],bur[10],star[10],finish[10],tat[10],wt[10],check[10],pri[10],rt[10],f[1
0],n,temp;
int main()
{
int totwt=0,tottat=0,i,j;
printf("Enter the number of processes:");
scanf("%d",&n);
for(i=0; i<n; i++)
{
printf("Enter the ProcessName, Arrival Time, Burst Time & Priority:");
scanf("%d%d%d%d",&pn[i],&arr[i],&bur[i],&pri[i]);
check[i]=bur[i];
f[i]=0;
fflush(stdin);
}
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
if(pri[i]<pri[j])
{
temp=pri[i];
pri[i]=pri[j];
pri[j]=temp;
temp=check[i];
check[i]=check[j];
check[j]=temp;
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
temp=bur[i];
bur[i]=bur[j];
bur[j]=temp;
temp=pn[i];
pn[i]=pn[j];
pn[j]=temp;
}
}
}
int c=0;
for(i=0; c<n ; i++)
{
for(j=0; j<n; j++)
{
if(arr[j]<=i && check[j]!=0)
{
if(f[j]!=1)
{
star[j]=i;
rt[j]=star[j]-arr[j];
f[j]=1;
}
check[j]--;
printf("%d: %d\n",j,check[j]);
if(check[j]==0)
{
finish[j]=i+1;
tat[j]=finish[j]-arr[j];
wt[j]=tat[j]-bur[j];
c++;
}
break;
}
}
}
printf("\nPName Priority Arrtime Burtime WaitTime Start TAT Finish Response");
for(i=0; i<n; i++)
{
printf("\n%d\t%d\t%3d\t%3d\t%3d\t%3d\t%6d\t%6d\t%d",pn[i],pri[i],arr[i],bur[i],wt[i],s
tar[i],tat[i],finish[i],rt[i]);
totwt+=wt[i];
tottat+=tat[i];
}
printf("\nAverage Waiting time:%f",(float)totwt/n);
printf("\nAverage Turn Around Time:%f",(float)tottat/n);
return 0;
}







// ROUND ROBIN:-
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
printf("SANIDHYA GUPTA 21BRS1610\n");
int n,i,qt,count=0,temp,sq=0,bt[10],wt[10],tat[10],rem_bt[10];
float avgwt=0,avgtat=0;
printf("Enter the no of process");
scanf("%d",&n);
printf("Enter the burst time of the process");
for (int i=0;i<n;i++){
scanf("%d",&bt[i]);
rem_bt[i]=bt[i];
}
printf("Enter quantum time");
scanf("%d",&qt);
while(1){
for (i=0,count=0;i<n;i++){
temp=qt;
if(rem_bt[i]==0){
count++;
continue;
}
if(rem_bt[i]>qt){
rem_bt[i]=rem_bt[i]-qt;
}
else
if(rem_bt[i]>=0){
temp=rem_bt[i];
rem_bt[i]=0;
}
sq=sq+temp;
tat[i]=sq;
}
if(n==count){
break;
}
}
printf("\nprocess\t burst time\t turn around time\t waiting time\n");
for(i=0;i<n;i++){
wt[i]=tat[i]-bt[i];
avgwt=avgwt+wt[i];
avgtat=avgtat=tat[i];
printf("\n%d\t%d\t\t%d\t\t\t%d\n",i+1,bt[i],tat[i],wt[i]);
}
avgwt=avgwt/n;
avgtat=avgtat/n;
printf("average waiting time= %f\n",avgwt);
printf("average turn around time= %f\n",avgtat);
return 0;
}








// Fits
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

struct input{
    int a, b, m[100], p[100];
};

void *first(void *rec){
    struct input *in = (struct input *)rec;
    bool d[in->a];
    bool w[in->b];
    for (int i = 0; i < in->a; i++)
        d[i] = false;
    for (int i = 0; i < in->b; i++)
        w[i] = false;

    printf("First fit\n");
    for (int i = 0; i < in->b; i++){
        for (int j = 0; j < in->a; j++){
            if (in->m[j] >= in->p[i] && d[j] == false){
                printf("\tProcess %d : Block %d Segmentation: %d\n", i + 1, j + 1, in->m[j] - in->p[i]);
                d[j] = true;
                w[i] = true;
                break;
            }
        }
    }

    printf("\n\tUnallocated processes: \n");
    for (int i = 0; i < in->b; i++){
        if (w[i] == false)
            printf("\t\tProcess %d\n", i + 1);
    }
    pthread_exit(NULL);
}

void *best(void *rec){
    struct input *in = (struct input *)rec;
    bool d[in->a], w[in->b];
    for (int i = 0; i < in->b; i++)
        w[i] = false;
    for (int i = 0; i < in->a; i++)
        d[i] = false;

    printf("\nBest fit\n");
    for (int i = 0; i < in->b; i++){
        int k, q;
        int min = 12345678;
        for (int j = 0; j < in->a; j++){
            if (in->m[j] - in->p[i] < min && d[j] == false && (in->m[j] - in->p[i]) >= 0){
                k = j;
                min = in->m[j] - in->p[i];
            }
        }

        if (q == k)
            continue;
        printf("\tProcess %d : Block %d Segmentation: %d \n", i + 1, k + 1, in->m[k] - in->p[i]);
        d[k] = true;
        w[i] = true;
        q = k;
    }

    printf("\n\tUnallocated processes: \n");
    for (int i = 0; i < in->b; i++){
        if (w[i] == false)
            printf("\t\tProcess %d\n", i + 1);
    }
    pthread_exit(NULL);
}

void *worst(void *rec){
    struct input *in = (struct input *)rec;
    bool d[in->a], w[in->b];
    for (int i = 0; i < in->b; i++)
        w[i] = false;
    for (int i = 0; i < in->a; i++)
        d[i] = false;

    printf("\nWorst fit\n");
    int q = 1234;
    for (int i = 0; i < in->b; i++){
        int k;
        int max = -12345678;
        for (int j = 0; j < in->a; j++){
            if (in->m[j] - in->p[i] > max && d[j] == false && (in->m[j] - in->p[i]) >= 0){
                k = j;
                max = in->m[j] - in->p[i];
            }
        }
        if (q == k)
            continue;
        printf("\tProcess %d : Block %d Segmentation: %d\n", i + 1, k + 1, in->m[k] - in->p[i]);
        d[k] = true;
        w[i] = true;
        q = k;
    }

    printf("\n\tUnallocated processes: \n");
    for (int i = 0; i < in->b; i++){
        if (w[i] == false)
            printf("\t\tProcess %d\n", i + 1);
    }
    pthread_exit(NULL);
}

int main(){
    FILE *fp = fopen("input.txt", "r");
    int a, b;
    fscanf(fp, "%d", &a);
    int m[a];
    bool d[a];

    for (int i = 0; i < a; i++){
        d[i] = false;
        fscanf(fp, "%d", &m[i]);
        printf("%d\n", m[i]);
    }

    fscanf(fp, "%d", &b);
    int p[b];

    for (int i = 0; i < b; i++)
        fscanf(fp, "%d", &p[i]);

    struct input in;
    in.a = a;
    in.b = b;
    for (int i = 0; i < a; i++)
        in.m[i] = m[i];

    for (int i = 0; i < b; i++)
        in.p[i] = p[i];

    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, (void *)first, &in);
    pthread_create(&t2, NULL, (void *)best, &in);
    pthread_create(&t3, NULL, (void *)worst, &in);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}




//Page replacement
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




//Second Chance
#include <stdio.h>

int main() {
    int n, f;
    printf("Enter the number of pages and frame size: ");
    scanf("%d %d", &n, &f);
    int arr[n], frame[f], ref[f];
    for(int i = 0; i<n; i++)
        scanf("%d", &arr[i]);
    int pf = 0, hit = 0;
    for(int i = 0; i<f; i++){
        frame[i] = 0;
        ref[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int page = arr[i];
        int found = 0;

        for (int j = 0; j < f; j++) {
            if (frame[j] == page) {
                ref[j] = 1;
                found = 1;
                hit++;
                break;
            }
        }

        if (!found) {
            int old = 0;
            int old_p = ref[0];

            for (int j = 1; j < f; j++) {
                if (ref[j] < old_p) {
                    old = j;
                    old_p = ref[j];
                }
            }

            frame[old] = page;
            ref[old] = 1;
            pf++;
        }
    }

    float hits = ((float)hit / n) * 100;
    printf("Page fault = %d\n", pf);
    printf("Hit = %d\n", hit);
    printf("Hit percentage = %.2f%%\n", hits);

    return 0;
}





//Dining Philosopher
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (i + 4) % N
#define RIGHT (i + 1) % N

int state[N];
int phil[N] = {1, 2, 3, 4, 5};
sem_t mutex;
sem_t S[N];

void test(int i){
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING){
        state[i] = EATING;
        sleep(2);
        printf("Philosopher %d takes fork %d and %d\n", i + 1, LEFT + 1, i + 1);
        printf("Philosopher %d is Eating\n", i + 1);
        sem_post(&S[i]);
    }
}

void take_fork(int i){
    sem_wait(&mutex);
    state[i] = HUNGRY;
    printf("Philosopher %d is Hungry\n", i + 1);
    test(i);
    sem_post(&mutex);
    sem_wait(&S[i]);
    sleep(1);
}

void put_fork(int i){
    sem_wait(&mutex);
    state[i] = THINKING;
    printf("Philosopher %d putting fork %d and %d down\n", i + 1, LEFT + 1, i + 1);
    printf("Philosopher %d is thinking\n", i + 1);
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}

void *philosopher(void *i){
    while (1){
        int *i = i;
        sleep(1);
        take_fork(*i);
        sleep(0);
        put_fork(*i);
    }
}

int main(){
    int i;
    pthread_t thread_id[N];
    sem_init(&mutex, 0, 1);
    for (i = 0; i < N; i++)
        sem_init(&S[i], 0, 0);
    for (i = 0; i < N; i++){
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
        printf("Philosopher %d is thinking\n", i + 1);
    }
    for (i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL);
}




//Producer consumer
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int size = 5;
int count = 1;
sem_t empty, full;
pthread_mutex_t mutex;
int arr[5];
int o = 0, in = 0, out = 0;
int y = 1, u = 1;

void *prod(void *a){
    for (int i = 0; i < size; i++){
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        arr[in] = o;
        printf("Teacher %d inserts item %d\n", y, o++);
        in = (in + 1) % 5;
        y = (y + 1) % 21;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *cons(void *a){
    for (int i = 0; i < size; i++){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        printf("Student %d removes item %d\n", u, arr[out]);
        out = (out + 1) % 5;
        u = (u + 1) % 21;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    pthread_t t1[20], t2[20];
    sem_init(&empty, 0, 5);
    sem_init(&full, 0, 1);
    for (int i = 0; i < 20; i++)
        pthread_create(&t1[i], NULL, (void *)prod, (void *)&a[i]);
    for (int i = 0; i < 20; i++)
        pthread_create(&t2[i], NULL, (void *)cons, (void *)&a[i]);
    for (int i = 0; i < 20; i++)
        pthread_join(t1[i], NULL);
    for (int i = 0; i < 20; i++)
        pthread_join(t2[i], NULL);
    return 0;
}



//(i) Write a boot loader program that prints A using PrintCharacter procedure
// CODE:
[BITS 16]
[ORG 0x7C00]
MOV AL,65
CALL PrintCharacter
JMP $
PrintCharacter:
MOV AH,0x0E;
MOV BH,0x00;
MOV BL,0x07;
INT 0x10;
RET
TIMES 510 -($-$$) db 0
DW 0xAA55


//(ii) Write a boot loader program that prints A directly by performing lodsb
// and or operations
// CODE:
[BITS 16]
[ORG 0x7C00]
BOOT:
MOV SI,HELLO;
MOV AH,0x0E;
LOOP:
LODSB
OR AL,AL
JZ HALT
INT 0x10
JMP LOOP
HALT:
CLI;
HLT
HELLO: db "A",0
TIMES 510 -($-$$) db 0
DW 0xAA55




// (iii) Write a boot loader program that prints your name
// CODE:
[BITS 16]
[ORG 0x7C00]
BOOT:
MOV SI,HELLO;
MOV AH,0x0E;
LOOP:
LODSB
OR AL,AL
JZ HALT
INT 0x10
JMP LOOP
HALT:
CLI;
HLT
HELLO: db "Aman Sharma",0
TIMES 510 -($-$$) db 0
DW 0xAA55





// (iv) write a boot loader program to print your registration number using
// printcharacter procedure as well as lodsb and or operations. (21bce
// withprintcharacter and your number 1001 with lodsb => so 21bce1001 is the
// final display)
// CODE:
[BITS 16]
[ORG 0x7C00]
MOV AL,50
CALL PrintCharacter
MOV AL,49
CALL PrintCharacter
MOV AL,66
CALL PrintCharacter
MOV AL,67
CALL PrintCharacter
MOV AL,69
CALL PrintCharacter
BOOT:
MOV SI,HELLO;
MOV AH,0x0E;
LOOP:
LODSB
OR AL,AL
JZ HALT
INT 0x10
JMP LOOP
HALT:
CLI;
HLT
HELLO: db "5769",0
JMP $
PrintCharacter:
MOV AH,0x0E;
MOV BH,0x00;
MOV BL,0x07;
INT 0x10;
RET
TIMES 510 -($-$$) db 0
DW 0xAA55




// (v) Write a boot loader program to print your name in red colour.
// CODE:
[BITS 16]
[ORG 0x7C00]
JMP MAIN
MAIN:
XOR AX,AX; DS = 0
MOV DS,AX
CLD;
MOV AX,0012H;
INT 10H
MOV SI,STRING
MOV BL,4
CALL PRINTSTR
JMP $
PRINTSTR:
MOV BH,0x00;
PRINT:
LODSB
CMP AL,0
JE DONE
MOV AH,0EH
INT 10H
JMP PRINT
DONE:
RET
STRING db "Aman Sharma",13,10,0



// 1.	Read n strings and display the strings which are palindrome.
// CODE:
#!/bin/bash
echo "Enter n: "
read n
for((j = 0; j<n; j++))
do
echo "Enter a String"
read str
reverse=""
len=${#str}
for (( i=$len-1; i>=0; i-- ))
do 
    reverse="$reverse${str:$i:1}"
done
if [ $str == $reverse ]
then
    echo "$str is palindrome"
else
    echo "$str is not palindrome"
fi
done




// 2.	Check the given number is prime or not.
// CODE:
#!/bin/bash
echo "Enter the number"
read n
flag=0
for((i=2; i<=n/2; i++))
do
if [ $((num%i)) -eq 0 ]
then
flag=1
fi
done
if [ $flag -eq 1 ]
then 
echo "$n is not a prime number"
else
echo "$n is a prime number"
fi




// 3.	Check the given number is Armstrong or not for a 4 digit number. (Ex. Armstrong numbers with 4 digits are 1634, 8208, and 9474)
// CODE:
#!/bin/bash
echo "Enter the number: "
read n
k=$n
len=${#n}
sum=0
while [ $n -ne  0 ]
do
r=$((n%10))
n=$((n/10))
p=`expr $r \* $r \* $r \* $r`
sum=$(($sum+$p))
done
if [ $sum -eq $k ]
then
echo "$k is an Armstrong number"
else
echo "$k is not an Armstrong number"
fi




// 4.	Display the factors of the given number
// CODE:
#!/bin/bash
echo "Enter the number"
read n
echo "Factors are:"
for((i=2;i<=n/2;i++))
do
if [ $((n%i)) -eq 0 ]
then
echo "$i "
fi
done


nasm file.asm -f bin -o boot.bin
qemu system-x86_64 -drive file=boot.bin,index=0,media=disk,format=raw
