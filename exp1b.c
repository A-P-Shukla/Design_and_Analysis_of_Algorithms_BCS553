#include <stdio.h>

int recursive_binary_search(int arr[], int target, int left, int right) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return recursive_binary_search(arr, target, left, mid - 1);
    } else {
        return recursive_binary_search(arr, target, mid + 1, right);
    }
}

int main() {
    int size;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d sorted elements of the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int result = recursive_binary_search(arr, target, 0, size - 1);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}