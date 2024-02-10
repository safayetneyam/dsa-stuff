// the sorting can be done using both for and while loop. the looping with for is added below.

#include <iostream>
using namespace std;

void finalMerge(int *arr, int start, int mid, int end) {
    int firstHalf = mid - start + 1, secondHalf = end - mid;
    int *leftArr = new int[firstHalf], *rightArr = new int[secondHalf];

    for (int i = 0; i < firstHalf; i++) {
        leftArr[i] = arr[start + i];
    }
    for (int j = 0; j < secondHalf; j++) {
        rightArr[j] = arr[mid + j + 1];
    }

    int i = 0, j = 0, k = start;
    while (i < firstHalf && j < secondHalf) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < firstHalf) {
        arr[k++] = leftArr[i++];
    }
    while (j < secondHalf) {
        arr[k++] = rightArr[j++];
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


// using FOR

//int i = 0, j = 0;
//for (int k = start; k <= end; k++) {
//    if (leftArr[i] <= rightArr[j]) {
//        if (i < firstHalf) arr[k] = leftArr[i++];
//        else arr[k] = rightArr[j++];
//    } else {
//        if (j < secondHalf) arr[k] = rightArr[j++];
//        else arr[k] = leftArr[i++];
//    }
//}
