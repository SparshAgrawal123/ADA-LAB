#include <stdio.h>
#include <time.h>

// Function to swap elements
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Heapify function
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and heapify again
    if (largest != i) {
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {

        // Move current root to end
        swap(arr, 0, i);

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

// Main function
int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start, end;
    double time_taken;

    printf("Original Array:\n");
    printArray(arr, n);

    // Start timer
    start = clock();

    // Perform Heap Sort
    heapSort(arr, n);

    // End timer
    end = clock();

    // Calculate time taken
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted Array:\n");
    printArray(arr, n);

    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
