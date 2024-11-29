#include <stdio.h>
#define MAX 100

int main() {
    int arr[MAX], size, target;

    printf("Enter the number of elements in the array :");
    scanf("%d", &size);

    // Input array elements from the user
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask the user for the target element to search
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    // Perform linear search
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element %d found at index %d\n", target, i);
            return 0; // Exit the program immediately after finding the element
        }
    }
    
    printf("Element %d not found in the array\n", target);

    return 0;
}
