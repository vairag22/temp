#include <stdio.h>

void main()
{
    int i, n, x, p[10], pp[10], pt[10], w[10], t[10];
    float total_tat, total_wt = 0;

    printf("Number of Process = ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nP%d: Burst Time = ", i + 1);
        scanf("%d", &pt[i]);

        printf("P%d: Priority = ", i + 1);
        scanf("%d", &pp[i]);

        p[i] = i + 1;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pp[i] < pp[j])
            {
                x = pp[i];
                pp[i] = pp[j];
                pp[j] = x;
                x = pt[i];
                pt[i] = pt[j];
                pt[j] = x;
                x = p[i];
                p[i] = p[j];
                p[j] = x;
            }
        }
    }

    w[0] = 0;
    t[0] = pt[0];
    total_tat = t[0];
    for (i = 1; i < n; i++)
    {
        w[i] = t[i - 1];
        total_wt += w[i];
        t[i] = w[i] + pt[i];
        total_tat += t[i];
    }
    printf("\n\nProcess\tBurst Time\tWaiting Time\tTurn Around Time\tPriority\n");
    for (i = 0; i < n; i++)
    {
        printf("\n %d \t\t %d \t\t %d \t\t %d \t\t %d \n", p[i], pt[i], w[i], t[i], pp[i]);
    }
    printf("\nAverage Wait Time = %f\n", total_wt / n);
    printf("\nAverage Turn Around Time = %f\n", total_tat / n);
}