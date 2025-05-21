#include <stdio.h>
#include <stdlib.h>

struct Task {
    int time;
    int deadline;
    int index;
};

// Sort by deadline
int compare(const void *a, const void *b) {
    return ((struct Task*)a)->deadline - ((struct Task*)b)->deadline;
}

int main() {
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    struct Task tasks[n];
    int timeSpent = 0, selected[n], count = 0;

    printf("Enter time taken by each task:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tasks[i].time);
        tasks[i].index = i + 1;
    }

    printf("Enter deadlines for each task:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tasks[i].deadline);
    }

    qsort(tasks, n, sizeof(struct Task), compare);

    for (int i = 0; i < n; i++) {
        if (timeSpent + tasks[i].time <= tasks[i].deadline) {
            timeSpent += tasks[i].time;
            selected[count++] = tasks[i].index;
        }
    }

    printf("Max number of tasks = %d\n", count);
    printf("Selected task numbers : ");
    for (int i = 0; i < count; i++) {
        printf("%d", selected[i]);
        if (i < count - 1) printf(", ");
    }
    printf("\n");

    return 0;
}
