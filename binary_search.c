#include <stdio.h>
#define MAX 100

int main() {
    int arr[MAX], size, target, mid, left, right;

    printf("Enter the number of elements in the array (max %d): ", MAX);
    scanf("%d", &size);

    // Input array elements from the user
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask the user for the target element to search
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    
    left = 0;
    right = size-1;

    while(left <= right){
        // Find Mid
        mid = (left + right) / 2;
        
        if(arr[mid] == target){
            printf("Element %d found at index %d\n", target, mid);
            return 0;
        }else{
            if(target<arr[mid]){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
    }
    
    printf("Element %d not found in the array\n", target);

    return 0;
}

