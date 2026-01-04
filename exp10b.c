#include <stdio.h>

void printSolution(int solution[], int n) {
    for (int i = 0; i < n; i++)
        if (solution[i])
            printf("%d ", solution[i]);
    printf("\n");
}

void sumOfSubsetUtil(int arr[], int n, int sum, int currentSum, int index, int solution[]) {
    if (currentSum == sum) {
        printSolution(solution, n);
        return;
    }
    if (index >= n || currentSum > sum)
        return;

    solution[index] = arr[index];
    sumOfSubsetUtil(arr, n, sum, currentSum + arr[index], index + 1, solution);
    solution[index] = 0;
    sumOfSubsetUtil(arr, n, sum, currentSum, index + 1, solution);
}

void sumOfSubset(int arr[], int n, int sum) {
    int solution[n];
    for (int i = 0; i < n; i++)
        solution[i] = 0;
    sumOfSubsetUtil(arr, n, sum, 0, 0, solution);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 9;
    printf("Subsets with sum %d are:\n", sum);
    sumOfSubset(arr, n, sum);
    return 0;
}