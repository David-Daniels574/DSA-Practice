#include <bits/stdc++.h>
using namespace std;

// Merge Sort functions
/*
Merge Sort is a classic divide and conquer algorithm. The core idea is based on breaking down a big problem into smaller, manageable sub-problems i.e. sorting smaller arrays and then merging those solutions to get the final sorted result.

It is much easier to merge two sorted arrays than to sort a large unsorted one. Therefore, instead of trying to sort the entire array at once, Merge Sort breaks it into halves repeatedly until we reach arrays of size 1 (which are trivially sorted), and then merges them back in sorted order. This makes the algorithm efficient and predictable, especially for large datasets.

    If the array has only one or zero elements, it is already sorted, so we return it as is.
    Else, we divide the array into two halves by finding the middle index.
    We then apply the merge sort algorithm recursively on each of the two halves to sort them individually.
    Once we have two sorted halves, we need to merge them into a single sorted array.
    To merge, we compare elements from both halves one by one and place the smaller element into a new array, continuing this until all elements from both halves are used.
    This process is repeated at every level of recursion, and finally, we get one fully sorted array after all merges are complete.


*/
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Quick Sort functions
int Partition(int arr[], int left, int right) {
    int x = arr[right], i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] >= x) swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = Partition(arr, left, right);
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex]) minIndex = j;
        if (minIndex != i) swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> vec(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> vec[i];

    int choice;
    cout << "\nChoose sorting algorithm:\n";
    cout << "1. Merge Sort\n2. Quick Sort\n3. Insertion Sort\n4. Selection Sort\n";
    cin >> choice;

    // Create a raw array if needed by quick/insertion/selection
    int arr[n];
    copy(vec.begin(), vec.end(), arr);

    switch (choice) {
        case 1:
            mergeSort(vec, 0, n - 1);
            cout << "Sorted array (Merge Sort):\n";
            for (int x : vec) cout << x << " ";
            break;
        case 2:
            quickSort(arr, 0, n - 1);
            cout << "Sorted array (Quick Sort):\n";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            break;
        case 3:
            insertionSort(arr, n);
            cout << "Sorted array (Insertion Sort):\n";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            break;
        case 4:
            selectionSort(arr, n);
            cout << "Sorted array (Selection Sort):\n";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            break;
        default:
            cout << "Invalid choice!\n";
    }

    cout << "\n";
    return 0;
}
