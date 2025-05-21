#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start, finish, index;
};

int compare(const void* a, const void* b) {
    return ((struct Activity*)a)->finish - ((struct Activity*)b)->finish;
}

int main() {
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];

    printf("Enter starting times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &activities[i].start);
        activities[i].index = i + 1;
    }

    printf("Enter finishing times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &activities[i].finish);
    }

    qsort(activities, n, sizeof(struct Activity), compare);

    printf("Selected activities: ");
    int count = 1;
    printf("%d", activities[0].index);
    int lastFinish = activities[0].finish;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            printf(", %d", activities[i].index);
            lastFinish = activities[i].finish;
            count++;
        }
    }

    printf("\nNo. of non-conflicting activities: %d\n", count);
    return 0;
}
