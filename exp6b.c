#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void* a, const void* b) {
    double r1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double r2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    return (r1 < r2) ? 1 : (r1 > r2 ? -1 : 0);
}

double knapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(items[0]), compare);

    double total_value = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            total_value += items[i].value;
        } else {
            total_value += items[i].value * ((double)capacity / items[i].weight);
            break;
        }
    }
    return total_value;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    struct Item items[n];
    printf("Enter value and weight of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    double max_value = knapsack(items, n, capacity);
    printf("Maximum value in the knapsack: %.2f\n", max_value);

    return 0;
}