#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int *arr, int first, int last, int num) {
    if (last >= first) {
        int mid = (first + last) / 2;
        if (*(arr + mid) == num) {
            return mid;
        } else if (*(arr + mid) > num) {
            return binarySearch(arr, first, mid - 1, num);
        } else {
            return binarySearch(arr, mid + 1, last, num);
        }
    } return -1;
}

int main() {
    cout << "How many numbers: ";
    int n; cin >> n;
    int *arr = new int[n]; //int arr[n];
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    cout << "The sorted elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
    cout << "Which element to search: ";
    int num; cin >> num;
    cout << "The index in " << binarySearch(arr, 0, n - 1, num) << endl;

    delete[] arr;
}

// 8
// 6 18 56 62 1 9 15 43
