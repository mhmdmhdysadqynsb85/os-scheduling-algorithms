#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n];

    for(int i = 0; i < n; i++) {
        printf("Burst Time P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    int complete = 0, time = 0, shortest;
    int minm;
    int finish_time;
    int wt[n], tat[n];

    while (complete != n) {
        minm = 9999;
        shortest = -1;

        for (int j = 0; j < n; j++) {
            if (rt[j] > 0 && rt[j] < minm) {
                minm = rt[j];
                shortest = j;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        rt[shortest]--;

        if (rt[shortest] == 0) {
            complete++;

            finish_time = time + 1;

            wt[shortest] = finish_time - bt[shortest];

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }

        time++;
    }

    printf("\nProcess\tBT\tWT\tTAT\n");

    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];

        printf("P%d\t%d\t%d\t%d\n",
               i + 1,
               bt[i],
               wt[i],
               tat[i]);
    }

    return 0;
}
