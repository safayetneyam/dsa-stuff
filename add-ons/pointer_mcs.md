<b> Useful Resources </b> 
- My Code School - [Lectures](https://www.youtube.com/watch?v=h-HBipu_1P0&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_)

### Basic Pointer

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 50; //4 byte
    //int y = 55; //4 byte
    //int z = 56;
    int *p; // p - add- add 4 byte
    p = &x;
    int *pp;
    int **q; //**p - add 
    int ***r; //***r - add 
    q = &p; //
    r = &q; //
    cout << x << endl;
    //cout << &x << endl; //address of x
    printf("Address of x: %d\n", &x);
    //cout << p << endl; //address of x
    printf("Address of p (stored): %d\n", p);
    cout << "Value of p aka x: " << *p << endl; //value of x
    //cout << *q << endl; //address of p aka x
    printf("Address of q (stored): %d\n", *q);
    cout << "Value of q aka p aka x: " << **q << endl; //value of p aka x
    //cout << **r << endl; //address of q aka p aka x
    printf("Address of r (stored): %d\n", **r);
    cout << "Value of r aka q aka p aka x: " << ***r << endl; //value of q aka p aka x 
    //x = 4, 20212223, p = 4, 24252627, q = 4, 28293031

    cout << endl; 
    //cout << "Address of q: " << q << endl; 
    printf("Address of x (pointer): %d\n", &x); 
    //printf("Address of y: %d\n", &y); //4 byte for x, 4 byte for y, 8 byte for pointer
    //printf("Address of z: %d\n", &z); //4 byte for x, 4 byte for y, 4 byte for z, 12 byte pointer
    printf("Address of p (pointer): %d\n", &p); 
    printf("Address of pp (pointer): %d\n", &pp); 
    printf("Address of q (pointer): %d\n", &q); 
    //printf("Address of q: %d\n", &q+2); holding positive, but reverse as negative
    printf("Address of r (pointer): %d\n", &r);  

    ***r = 75;
    cout << endl;
    cout << x << endl;
    cout << *p << endl;
    cout << **q << endl;
    cout << ***r << endl;

    x = 100;
    cout << endl;
    cout << ***r << endl;

    //r = &p; //invalid (serial matters)
    r = &q;
    //*q = 102; //invalid (asterisk matters)
    **q = 102;
    cout << ***r << endl;
}
```

> Console Output 

```txt
50
Address of x: -1085372500
Address of p (stored): -1085372500
Value of p aka x: 50
Address of q (stored): -1085372500
Value of q aka p aka x: 50
Address of r (stored): -1085372500
Value of r aka q aka p aka x: 50

Address of x (pointer): -1085372500
Address of p (pointer): -1085372512
Address of pp (pointer): -1085372520
Address of q (pointer): -1085372528
Address of r (pointer): -1085372536

75
75
75
75

100
102
```

### Basic Array

```cpp
#include <iostream>
using namespace std;

int sumofElements(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += *(arr + i);
    return sum;
}

int sumofElements_forTest(int *arr) {
    int sum = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Size of A: " << sizeof(arr) << " Size of arr[0]: " << " " << sizeof(arr[0]) << endl; 
    //(!why; mismatch yt : https://youtu.be/CpjVucvAc3g?list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&t=263)
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum;
}

int main() {
    int arr[] = {50, 60, 70, 80, 90};
    // for (int i = 0; i < 5; i++) {
    //     cout << "Address: " << arr + i << " - " << &arr[i] << endl;
    //     cout << "Value: " << *(arr + i) << " - " << arr[i] << endl;
    //     cout << endl;
    // }
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Total (sumofElements) : " << sumofElements(&arr[0], size) << endl;
    int total = sumofElements_forTest(arr);
    cout << "Total (sumofElements_forTest) : " << total << endl;
}
```

> Console Output 

```cpp
Total (sumofElements) : 350
Size of A: 8 Size of arr[0]:  4
Total (sumofElements_forTest) : 110
```

### Character Manipulation

```cpp
#include <iostream>
using namespace std;

void print(char *ch) {
    // int i = 0;
    // while (ch[i] != '\0') {
    //     printf("%c", ch[i]);
    //     i++;
    // }
    while (*ch != '\0') {
        printf("%c", *ch);
        ch++;
    }
    printf("\n");
}

int main() {
    char ch[] = "tan45_nadim/tan45nadim; Nick: Nadim; Initial: TAN";
    print(ch);
}
```

> Console Output 

```cpp
tan45_nadim/tan45nadim; Nick: Nadim; Initial: TAN
```

### 2D Array

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[2][3] = {{2, 4, 6}, {1, 3, 5}};
    int (*p)[3] = arr;
    //initializing the pointer of [][3] array;
    //sample function, 2D array; void func(int (*ptr)[3]) { }
    
    printf("Getting Address of First Array(Element) of 3 Integers\narr   &arr[0]   *arr   arr[0]   &arr[0][0]\n%d | %d | %d | %d | %d\n\n", arr, &arr[0], *arr, arr[0], &arr[0][0]);
    printf("Getting Address of Second Array(Element) of 3 Integers\narr+1 &arr[1]   *(arr+1)  arr[1]  &arr[1][0]\n%d | %d | %d | %d | %d\n\n", arr+1, &arr[1], *(arr+1), arr[1], &arr[1][0]);   
    
    printf("2nd Array, 3rd Element, Index[1][2]\n%d %d %d\n\n", *(arr+1)+2, arr[1]+2, &arr[1][2]);
    //Question: Difference Between (arr+1)+1 and *(arr+1)+2?

    cout << "printing address of every element" << endl;
    cout << "Method *(arr+i)+j | arr[i]+j | &arr[i][j]" << endl << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i]+j);
        }
        printf("\n");
    }
    
    cout << endl << "getting values of every element" << endl;
    cout << "Method *(*(arr+i)+j) | *(arr[i]+j) | arr[i][j]" << endl << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("arr[%d][%d] = %d\n", i, j, *(arr[i]+j));
        }
        cout << endl;
    }
}
```

> Console Output 

```cpp
arr   &arr[0]   *arr   arr[0]   &arr[0][0]
-1329010816 | -1329010816 | -1329010816 | -1329010816 | -1329010816

Getting Address of Second Array(Element) of 3 Integers
arr+1 &arr[1]   *(arr+1)  arr[1]  &arr[1][0]
-1329010804 | -1329010804 | -1329010804 | -1329010804 | -1329010804

2nd Array, 3rd Element, Index[1][2]
-1329010796 -1329010796 -1329010796

printing address of every element
Method *(arr+i)+j | arr[i]+j | &arr[i][j]

arr[0][0] = -1329010816
arr[0][1] = -1329010812
arr[0][2] = -1329010808

arr[1][0] = -1329010804
arr[1][1] = -1329010800
arr[1][2] = -1329010796


getting values of every element
Method *(*(arr+i)+j) | *(arr[i]+j) | arr[i][j]

arr[0][0] = 2
arr[0][1] = 4
arr[0][2] = 6

arr[1][0] = 1
arr[1][1] = 3
arr[1][2] = 5
```

### Multidimensional Array

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[3][2][2] = {{{1, 2}, {3, 4}}, {{11, 12}, {13, 14}}, {{21, 22}, {23, 24}}};
    int (*p)[2][2] = arr; 
    //initializing the pointer of [][2][2] array;
    //sample function, multidimensional array; void func(int (*ptr)[2][2]) { }

    printf("Getting Address of First Array(Element) of 2 * 2 Integers\narr   &arr[0]   *arr   arr[0]   &arr[0][0]\n%d | %d | %d | %d | %d\n\n", arr, &arr[0], *arr, arr[0], &arr[0][0]);
    printf("Getting Address of Second Array(Element) of 2 * 2 Integers\narr+1   &arr[1]   *(arr+1)  arr[1]  &arr[1][0]\n%d | %d | %d | %d | %d\n\n", arr+1, &arr[1], *(arr+1), arr[1], &arr[1][0]);
    printf("Getting Address of Third Array(Element) of 2 * 2 Integers\narr+2   &arr[2]   *(arr+2)  arr[2]  &arr[2][0]\n%d | %d | %d | %d | %d\n\n", arr+2, &arr[2], *(arr+2), arr[2], &arr[2][0]);

    printf("Address of 3rd Array, (Inner) 2nd Array, 2nd Element; Index [2][1][1]\nMethod arr[2][1]+1, &arr[2][1][1] is %d, %d\n\n", arr[2][1]+1, &arr[2][1][1]);
    printf("Value of 3rd Array, (Inner) 2nd Array, 2nd Element; Index [2][1][1]\nMethod *(arr[2][1]+1), arr[2][1][1] is %d, %d\n\n", *(arr[2][1]+1), arr[2][1][1]);
}
```

> Console Output 

```txt
arr   &arr[0]   *arr   arr[0]   &arr[0][0]
-1264576640 | -1264576640 | -1264576640 | -1264576640 | -1264576640

Getting Address of Second Array(Element) of 2 * 2 Integers
arr+1   &arr[1]   *(arr+1)  arr[1]  &arr[1][0]
-1264576624 | -1264576624 | -1264576624 | -1264576624 | -1264576624

Getting Address of Third Array(Element) of 2 * 2 Integers
arr+2   &arr[2]   *(arr+2)  arr[2]  &arr[2][0]
-1264576608 | -1264576608 | -1264576608 | -1264576608 | -1264576608

Address of 3rd Array, (Inner) 2nd Array, 2nd Element; Index [2][1][1]
Method arr[2][1]+1, &arr[2][1][1] is -1264576596, -1264576596

Value of 3rd Array, (Inner) 2nd Array, 2nd Element; Index [2][1][1]
Method *(arr[2][1]+1), arr[2][1][1] is 24, 24
```

### Heap / Dynamic Memory (in C)
 
```cpp
#include <iostream>
using namespace std;

int main() {
    int num;
    int *ptr;

    ptr = (int*)malloc(sizeof(int));
    // malloc returns void pointer. here, type casting needed
    // sizeof(int) assigns 4 byte; size of an integer data/var
    *ptr = 782;
    printf("Assigned Value is %d\n", *ptr);
    printf("Address of ptr on the Heap is %d\n\n", ptr);

    ptr = (int*)malloc(sizeof(int));
    *ptr = 181;
    printf("Assigned Value is %d\n", *ptr);
    printf("Address of ptr on the Heap is %d\n", ptr);  
}
```

> Console Output 

```txt
Assigned Value is 782
Address of ptr on the Heap is 6783040

Assigned Value is 181
Address of ptr on the Heap is 6783056
```

#### Usage of free() Function

```cpp
#include <iostream>
using namespace std;

int main() {
    int num;
    int *ptr;
    ptr = (int*)malloc(sizeof(int));
    // sizeof(int) assigns 4 byte; size of an integer data/var
    *ptr = 782;
    printf("Assigned Value is %d\n", *ptr);
    printf("Address of ptr on the Heap is %d\n", ptr);
    free(ptr);
    /* 
        free: any memory which is allocated using malloc will be cleared off
        you're responsible for removing the memory block on the heap/dynamic memory
        if it's not needed. with free func, we pass the starting address of the memory block.
    */ 

    printf("\n");

    ptr = (int*)malloc(sizeof(int));
    *ptr = 181;
    printf("Assigned Value is %d\n", *ptr);
    printf("Address of ptr on the Heap is %d\n", ptr);
    free(ptr);

    printf("\n");

    ptr = (int*)malloc(20*sizeof(int)); //reserves memory block for 20 sized array.
    *(ptr + 0) = 11; //can be written as *ptr = 11;
    *(ptr + 1) = 22;
    *(ptr + 2) = 33;
    *(ptr + 3) = 44;

    printf("Assigned Value is %d\n", *(ptr + 0)); //ptr[0]
    printf("Assigned Value is %d\n", *(ptr + 1)); //ptr[1]
    printf("Assigned Value is %d\n", *(ptr + 2)); //ptr[2]
    printf("Assigned Value is %d\n", *(ptr + 3)); //ptr[3]

    printf("\n");

    printf("Address of ptr + 0 on the Heap is %d\n", ptr + 0);
    printf("Address of ptr + 1 on the Heap is %d\n", ptr + 1);
    printf("Address of ptr + 2 on the Heap is %d\n", ptr + 2);
    printf("Address of ptr + 3 on the Heap is %d\n", ptr + 3);    
}
```

> Console Output 

```txt
Assigned Value is 782
Address of ptr on the Heap is 59621440

Assigned Value is 181
Address of ptr on the Heap is 59621440

Assigned Value is 11
Assigned Value is 22
Assigned Value is 33
Assigned Value is 44

Address of ptr + 0 on the Heap is 27099136
Address of ptr + 1 on the Heap is 27099140
Address of ptr + 2 on the Heap is 27099144
Address of ptr + 3 on the Heap is 27099148
```

### Dynamic Memory Allocation (in C)

```cpp
#include <iostream>
using namespace std;

/*
allocate block of memory
malloc - void* malloc(size_t size) 
    size_t - data type
    to measure size, use sizeof(size_t), always positive
    note: malloc sets byte position with garbage value.
    ie. int *p = (int*)malloc(3 * sizeof(int));
        int pointer = (int*)malloc(no of int * size of int); 
        de-reference by *p = 2, *(p + 1) = 3, *(p + 2) = 5

calloc - void* calloc(size_t num, size_t size);
    size_t num = number of elements
    size_t size = size of data type
    note: calloc sets byte positions with value zero, unlike malloc.
    ie. int *p = (int*)calloc(3, sizeof(int));

realloc - void* realloc(void* ptr, size_t size);
    to change the size of an assigned block of memory
*/

int main() {
    int n; 
    cout << "Enter Arr Size: ";
    cin >> n;

    cout << endl;

    /*using malloc; without initializing it will give garbage.
    int *arr = (int*)malloc(n * sizeof(int)); //dynamically allocated array
    */

    //using calloc; without initializing it will give zero.
    int *arr = (int*)calloc(n, sizeof(int)); //dynamically allocated array

    for (int i = 0; i < n; i++) *(arr + i) = i + 1;
    
    /*
    free(arr); 

    by using free, the data of that memory block 
    will be removed or available for further allocation.
    after than it will print garbage value, depends on machine.
    */

    int *arrNew = (int*)realloc(arr, (n / 2) * sizeof(int));
    //int *arrNew = (int*)realloc(arr, 0); as same as free(arr);
    //int *arrExt = (int*)realloc(NULL, n * sizeof(int)); equivalent to malloc
    printf("Prev Arr: %d\nNew Arr: %d\n\n", arr, arrNew);

    for (int i = 0; i < n; i++) cout << *(arrNew + i) << " ";
    cout << endl;
}
```

> Console Output 

```txt
Enter Arr Size: 8

Prev Arr: 37015808
New Arr: 34897984

1 2 3 4 0 0 0 0
```

### Return Value as Pointer

```cpp
#include <iostream>
using namespace std;

int *add (int *c, int *d) {
    int *x = (int*)malloc(sizeof(int));
    *x = *c + *d;
    return x;
}

int main() {
    int a, b; 
    cout << "Enter Two Integers: ";
    cin >> a >> b;
    int *ptr = add(&a, &b);
    cout << "Sum is " << *ptr << endl;
}
```

> Console Output 

```txt
Enter Two Integers: 15 30
Sum is 45
```

### Function as Pointer

```cpp
#include <iostream>
using namespace std;

void printFixed() {
    cout << "This is A Void Function with No Parameter" << endl;
}

void printAnything(char *str) {
    cout << "Your String: " << str << endl;
}

int add(int a, int b) {
    return a + b;
}

int main() {
    int a, b;
    cout << "Enter Two Integer: ";
    cin >> a >> b;
    int (*p)(int, int);
    p = add; //add instread of &add
    //function name will return as pointer
    int c = p(a, b); //p instead of (*p) 
    //de-referencing and executing the function
    cout << "Sum is " << c << endl;

    cout << endl;

    void (*ptr)();
    ptr = printFixed;
    ptr();

    cout << endl;

    void (*ptrNew)(char*);
    ptrNew = printAnything;
    ptrNew("Safayet Neyam");
}
```

> Console Output 

```txt
Enter Two Integer: 30 15
Sum is 45

This is A Void Function with No Parameter

Your String: Safayet Neyam
```
