#include <stdio.h>

int main() {
    int i;
    int at[5], bt[5], ct[5], tat[5], wt[5];
    float avg_wt = 0, avg_tat = 0;

    // Input Arrival Time and Burst Time for 5 processes
    for (i = 0; i < 5; i++) {
        printf("\nEnter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Calculate Completion Time
    ct[0] = at[0] + bt[0];

    for (i = 1; i < 5; i++) {
        if (ct[i - 1] < at[i]) {
            // CPU is idle until the process arrives
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    // Calculate Turnaround Time and Waiting Time
    for (i = 0; i < 5; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    // Calculate averages
    avg_tat = avg_tat / 5;
    avg_wt = avg_wt / 5;

    // Display results
    printf("\n---------------------------------------------------------\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    printf("---------------------------------------------------------\n");

    for (i = 0; i < 5; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("---------------------------------------------------------\n");
    printf("Average Turnaround Time = %.2f\n", avg_tat);
    printf("Average Waiting Time    = %.2f\n", avg_wt);

    return 0;
}
