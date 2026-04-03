#include <stdio.h>

// Function for Linear Search
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i; // return index if found
        }
    }
    return -1; // not found
}
void sortarray(int arr[], int n) {
    int temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }      
}
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            return mid;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
    int arr[100], n, key, choice, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search (Array must be sorted)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &key);

                result = linearSearch(arr, n, key);

                if(result != -1)
                    printf("Element found at %d position using Linear Search\n", result + 1);
                else
                    printf("Element not found\n");
                break;
            case 2:
             printf("Enter element to search: ");
                scanf("%d", &key);
                sortarray(arr, n); // Sort before binary search
                printf("Sorted array:");
                for(int i = 0; i < n; i++) 
                    printf("%d ", arr[i]);
                result = binarySearch(arr, n, key);
                if(result != -1)
                    printf("\nElement found at %d position using Binary Search\n", result + 1);
                else
                    printf("\nElement not found\n");
                break;
                
            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 3);

    return 0;
}