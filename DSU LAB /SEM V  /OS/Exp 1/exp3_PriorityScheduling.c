#include <stdio.h>

int main()
{
    int n, i;
    int pid[20], at[20], bt[20], pr[20];
    int ct[20], tat[20], wt[20];
    int completed[20] = {0};
    int currentTime = 0;
    int completedCount = 0;
    int highestPriority, index;

    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("\nEnter Arrival Time of P%d: ", pid[i]);
        scanf("%d", &at[i]);

        printf("Enter Burst Time of P%d: ", pid[i]);
        scanf("%d", &bt[i]);

        printf("Enter Priority of P%d: ", pid[i]);
        scanf("%d", &pr[i]);
    }

    // Priority Scheduling
    // Smaller priority number = higher priority
    while (completedCount < n)
    {
        index = -1;
        highestPriority = 9999;

        // Find highest priority among arrived processes
        for (i = 0; i < n; i++)
        {
            if (at[i] <= currentTime && completed[i] == 0)
            {
                if (pr[i] < highestPriority)
                {
                    highestPriority = pr[i];
                    index = i;
                }
            }
        }

        // If no process has arrived
        if (index == -1)
        {
            currentTime++;
        }
        else
        {
            // Execute process
            currentTime = currentTime + bt[index];

            // Completion Time
            ct[index] = currentTime;

            // Turnaround Time
            tat[index] = ct[index] - at[index];

            // Waiting Time
            wt[index] = tat[index] - bt[index];

            completed[index] = 1;
            completedCount++;
        }
    }

    // Calculate averages
    for (i = 0; i < n; i++)
    {
        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];
    }

    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;

    // Display result
    printf("\n-------------------------------------------------------------");
    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT");
    printf("\n-------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i],
               ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time    = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
