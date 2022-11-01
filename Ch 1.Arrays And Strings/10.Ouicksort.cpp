#include <iostream>

int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high + 1;

    while (i < j) {
        do {
            ++i;
        }
        while (arr[i] <= pivot);

        do {
            --j;
        }
        while(arr[j] > pivot);

        if (i < j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    int tmp = arr[low];
    arr[low] = arr[j];
    arr[j] = tmp;

    return j;
}

void quicksort(int *arr, int low, int high) {
    if (high > low) {
        int cnst = partition(arr, low, high);
        quicksort(arr, low, cnst - 1);
        quicksort(arr, cnst + 1, high);
    }
}

int main() {
    int n;
    std::cout << "enter array size : ";
    std::cin >> n;

    int arr[n];
    std::cout << "enter array elements : ";

    for(int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);

    for(int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
