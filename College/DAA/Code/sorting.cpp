#include <bits/stdc++.h>
using namespace std;

// Merge Sort functions
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
