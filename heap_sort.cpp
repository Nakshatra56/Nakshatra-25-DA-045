// Write a program to implement Heap Sort.

#include <iostream>
#include <vector>
using namespace std;

// Sift the element at index i down so the subtree rooted at i satisfies the max-heap property.
// n is the size of the heap.
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Repeatedly move the current max to the end and re-heapify the reduced heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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

    heapSort(arr);

    cout << "Heap sorted:    ";
    printArray(arr);
    cout << "\nCorrectly sorted: " << (isSorted(arr) ? "true" : "false") << endl;

    return 0;
}

/*
Sample Output:

student@labs:~/dsa$ g++ -std=c++17 -o heap_sort heap_sort.cpp && ./heap_sort
Original array: [38, 27, 43, 3, 9, 82, 10]
Heap sorted:    [3, 9, 10, 27, 38, 43, 82]
Correctly sorted: true
*/
