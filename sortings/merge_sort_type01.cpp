#include <iostream>
using namespace std;

void finalMerge(int *arr, int start, int mid, int end) {
    int firstHalf = mid - start + 1, secondHalf = end - mid;
    int *leftArr = new int[firstHalf + 1], *rightArr = new int[secondHalf + 1];

    for (int i = 0; i < firstHalf; i++) {
        leftArr[i] = arr[start + i];
    }
    for (int j = 0; j < secondHalf; j++) {
        rightArr[j] = arr[mid + j + 1];
    }

    leftArr[firstHalf] = INT_MAX; rightArr[secondHalf] = INT_MAX;

    int i = 0, j = 0;
    for (int k = start; k <= end; k++) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i++];
        } else {
            arr[k] = rightArr[j++];
        }
    }
}

void mergeSort(int *arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        finalMerge(arr, start, mid, end);
    }
}

int main() {
    cout << "How many numbers: ";
    int n; cin >> n;
    int *arr = new int[n];
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    cout << "The sorted elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    delete[] arr;
}

// 8
// 6 18 56 62 1 9 15 43
