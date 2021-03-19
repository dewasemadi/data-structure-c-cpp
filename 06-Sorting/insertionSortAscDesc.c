#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// function to sort an array using insertion sort
void insertionSort(int arr[], int n, int c)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        // move elements of arr[0 ... i-1], that are greater than key, to one position ahead of their current position
        if (c == 1)
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
        if (c == 2)
            while (j >= 0 && arr[j] < key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
        arr[j + 1] = key;
    }
}

// function to print an array of size n
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void main()
{
    int arr[] = {12, 11, 13, 5, 6}, n = sizeof(arr) / sizeof(arr[0]), c = 0;
    char ch;
    system("cls");
start:
    printf("Insertion Sort Program\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("3. Exit\n");
    printf("================================\n");
    printf("Enter your choice : \t");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
        insertionSort(arr, n, c);
        printArr(arr, n);
        break;
    case 2:
        insertionSort(arr, n, c);
        printArr(arr, n);
        break;
    case 3:
        exit(1);
    default:
        printf("\nWrong Choice");
        break;
    }
    printf("\nDo you wish to continue?(y/n) : ");
    fflush(stdin);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
        goto start;
}