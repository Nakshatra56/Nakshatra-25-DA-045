// Write a program to implement Quick Sort.

#include <iostream>
#include <vector>
using namespace std;

// Partitions arr[low..high] using the last element as pivot.
// Returns the final index of the pivot.
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1; // index of last element <= pivot

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

bool isSorted(const vector<int>& arr) {
    for (size_t i = 0; i + 1 < arr.size(); i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

void printArray(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: ";
    printArray(arr);
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Quick sorted:   ";
    printArray(arr);
    cout << "\nCorrectly sorted: " << (isSorted(arr) ? "true" : "false") << endl;

    return 0;
}
