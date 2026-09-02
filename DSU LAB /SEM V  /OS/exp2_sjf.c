#include <stdio.h>

struct Process {
    int pid, at, bt, ct, wt, tat;
};

int main() {
    int n, i, completed = 0, time = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    int done[n];

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        done[i] = 0;

        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    while (completed < n) {
        int index = -1;
        int shortest = 9999;

        // Find the process with shortest BT
        // among the processes that have arrived
        for (i = 0; i < n; i++) {
            if (!done[i] && p[i].at <= time) {
                if (p[i].bt < shortest) {
                    shortest = p[i].bt;
                    index = i;
                }
            }
        }

        // If no process has arrived yet
        if (index == -1) {
            time++;
            continue;
        }

        // Execute selected process
        time += p[index].bt;

        p[index].ct = time;
        p[index].tat = p[index].ct - p[index].at;
        p[index].wt = p[index].tat - p[index].bt;

        done[index] = 1;
        completed++;

        avg_wt += p[index].wt;
        avg_tat += p[index].tat;
    }

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].ct,
               p[i].wt,
               p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
