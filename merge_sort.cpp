// Experiment 1: Merge Sort
// Implements Merge Sort using both recursive and iterative (bottom-up) methods.

#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays arr[left..mid] and arr[mid+1..right] into one sorted range.
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftPart(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < (int)leftPart.size() && j < (int)rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            arr[k++] = leftPart[i++];
        } else {
            arr[k++] = rightPart[j++];
        }
    }
    while (i < (int)leftPart.size()) arr[k++] = leftPart[i++];
    while (j < (int)rightPart.size()) arr[k++] = rightPart[j++];
}

// Recursive top-down merge sort
void mergeSortRecursive(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSortRecursive(arr, left, mid);
    mergeSortRecursive(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Iterative bottom-up merge sort
void mergeSortIterative(vector<int>& arr) {
    int n = arr.size();

    for (int width = 1; width < n; width *= 2) {
        for (int left = 0; left < n - 1; left += 2 * width) {
            int mid = min(left + width - 1, n - 1);
            int right = min(left + 2 * width - 1, n - 1);
            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
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
    vector<int> original = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array:       ";
    printArray(original);
    cout << endl;

    // Recursive version
    vector<int> recursiveResult = original;
    mergeSortRecursive(recursiveResult, 0, recursiveResult.size() - 1);
    cout << "Recursive merge sort: ";
    printArray(recursiveResult);
    cout << "\n  Correctly sorted: " << (isSorted(recursiveResult) ? "true" : "false") << endl;

    // Iterative version
    vector<int> iterativeResult = original;
    mergeSortIterative(iterativeResult);
    cout << "Iterative merge sort: ";
    printArray(iterativeResult);
    cout << "\n  Correctly sorted: " << (isSorted(iterativeResult) ? "true" : "false") << endl;

    return 0;
}

/*
Sample Output:

student@labs:~/dsa$ g++ -std=c++17 -o merge_sort merge_sort.cpp && ./merge_sort
Original array:       [38, 27, 43, 3, 9, 82, 10]
Recursive merge sort: [3, 9, 10, 27, 38, 43, 82]
  Correctly sorted: true
Iterative merge sort: [3, 9, 10, 27, 38, 43, 82]
  Correctly sorted: true
*/
