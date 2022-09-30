### Dynamic Memory Allocation

#### Basics in C++

```cpp
  Pointer = new   DataType; 
  Pointer = new   DataType  [IntExpression]; 

  delete    Pointer; 
  delete   []   Pointer; 

  Example: 
  int *a = new int; 
  char *b = new char[5]; 
  float *c = new float[3*someVariable+1]; 
  double **d = new double*[10]; 
  delete a; 
  delete [] b; 
  delete [] c; 
  delete [] d; 
```

#### 2D Array (using C++)

> code `main.cpp`  - LAB01_CSE225
```cpp
#include <iostream>
using namespace std;

int main() {
    int row, col; cin >> row >> col;
    int** arr;
    arr = new int*[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col]; //arr[i], *(arr + i) are same.
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int val; cin >> val;
            arr[i][j] = val; //arr[i][j], *(arr[i] + j) are same.
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) cout << arr[i][j] << " ";
        cout << endl;
    }
    //de-allocating array using delete 
    for (int i = 0; i < row; i++) delete[] arr[i];
    delete[] arr;
    /* alternate_code (lab)
    for (int i = 0; i < row; i++) delete(arr[i]);
    delete(arr);
    */
    return 0;
}
```

> Console Output

```txt
2 3
1 2 3 4 5 6
1 2 3 
4 5 6
```
