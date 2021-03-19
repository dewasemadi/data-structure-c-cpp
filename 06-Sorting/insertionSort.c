#include <stdio.h>
#include <math.h>

// function to sort an array using insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        // move elements of arr[0 ... i-1], that are greater than key, to one position ahead of their current posisiton
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// function to print an arry of size n
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6}, n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArr(arr, n);

    return 0;
}