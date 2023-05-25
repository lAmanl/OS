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