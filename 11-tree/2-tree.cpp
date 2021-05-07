#include <iostream>
using namespace std;

void fun1(int arr[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1 -> ganjil
    int r = 2 * i + 2; // right = 2*i + 2 -> genap
    // if left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
    // if right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
    // if largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        fun1(arr, n, largest); //recursive
    }
}

// build max-heap
void fun2(int arr[], int n)
{
    int startIdx = (n / 2) - 1;         // index of last non-leaf node
    for (int i = startIdx; i >= 0; i--) //heapify
        fun1(arr, n, i);
}

// build min-heap
void fun3(int arr[], int &n)
{
    int lastElement = arr[n - 1];
    arr[0] = lastElement;
    n = n - 1;
    fun1(arr, n, 0);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    // int arr[] = {2, 4, 5, 1, 6, 10, 13, 17, 15, 8, 9};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // fun2(arr, n);
    // printArray(arr, n);
    // // int arr2[] = {10, 5, 3, 6, 2, 4, 17};
    // // int n = sizeof(arr2) / sizeof(arr2[0]);
    // fun3(arr, n);
    // printArray(arr, n);

    int arr[] = {20, 16, 11, 2, 4, 5, 1, 6, 10, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    fun2(arr, n);
    printf("Max Heap: ");
    printArray(arr, n);
    fun3(arr, n);
    printf("Setelah di delete: ");
    printArray(arr, n);
    return 0;
}