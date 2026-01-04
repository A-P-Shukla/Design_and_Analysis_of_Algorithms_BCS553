#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start;
    int finish;
};

int compare(const void* a, const void* b) {
    return ((struct Activity*)a)->finish - ((struct Activity*)b)->finish;
}

void activity_selection(struct Activity activities[], int n) {
    qsort(activities, n, sizeof(activities[0]), compare);

    int i = 0;
    printf("Selected activities: (%d, %d) ", activities[i].start, activities[i].finish);

    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            printf("(%d, %d) ", activities[j].start, activities[j].finish);
            i = j;
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];
    printf("Enter start and finish times of activities:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    activity_selection(activities, n);

    return 0;
}