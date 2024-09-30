#include <stdio.h>

struct process
{
    int burst, wait, comp, f;
} p[20] = {0, 0};

void main()
{
    int n, i, j, quantum, flag = 1, time = 0;
    float total_wt = 0, total_tat = 0;

    printf("Number of Process = ");
    scanf("%d", &n);

    printf("Quantum Time = ");
    scanf("%d", &quantum);

    printf("\nProcess\t\tBurst Time\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t\t", i + 1);
        scanf("%d", &p[i].burst);
        p[i].f = 1;
    }

    printf("\n0");
    while (flag == 1)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (p[i].f == 1)
            {
                flag = 1;
                j = quantum;
                if ((p[i].burst - p[i].comp) > quantum)
                {
                    p[i].comp += quantum;
                }
                else
                {
                    p[i].wait = time - p[i].comp;
                    j = p[i].burst - p[i].comp;
                    p[i].comp = p[i].burst;
                    p[i].f = 0;
                }
                printf(" P%d %d", i + 1, time + j);
                time += j;
            }
        }
    }
    printf("\n\nProcess\t\tWaiting Time\tTurn Around Time");
    for (i = 0; i < n; i++)
    {
        printf("\nP%d\t\t%d\t\t%d", i + 1, p[i].wait, p[i].wait + p[i].burst);
        total_wt = total_wt + p[i].wait;
        total_tat = total_tat + p[i].wait + p[i].burst;
    }
    printf("\n\nAverage Waiting Time = %f", total_wt / n);
    printf("\nAverage Turn Around Time = %f\n", total_tat / n);
}