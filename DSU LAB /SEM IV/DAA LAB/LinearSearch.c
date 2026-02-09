#include <stdio.h>
void LinearSearch(int arr[], int size, int target, int result[], int *resultSize) {
    *resultSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            result[*resultSize] = i;
            (*resultSize)++;
        }
    }
}

int main() {
    int size, target;
printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target value to search: ");
    scanf("%d", &target);
    int result[size];
    int resultSize;
    LinearSearch(arr, size, target, result, &resultSize);
    if (resultSize > 0) {
        printf("Matching indices for target %d: ", target);
        for (int i = 0; i < resultSize; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    } else {
        printf("No matching indices found for target %d.\n", target);
    }

    return 0;
}
