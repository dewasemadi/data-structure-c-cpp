#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int low, int high, int code)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (code == 1)
        {
            if (arr[j] < pivot)
            {
                i++; // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
        if (code == 2)
        {
            if (arr[j] > pivot)
            {
                i++; // increment index of larger element
                swap(&arr[i], &arr[j]);
            }
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort arr[] --> Array to be sorted,
low --> Starting index, high --> Ending index , code 1 --> Descending and code 0 --> ascending*/
void quickSort(int arr[], int low, int high, int code)
{
    if (low < high)
    {
        int pi;
        /* pi is partitioning index, arr[p] is now at right place */
        if (code == 1)
            pi = partition(arr, low, high, 1);
        if (code == 2)
            pi = partition(arr, low, high, 2);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1, code);
        quickSort(arr, pi + 1, high, code);
    }
}

void main()
{
    int arr[] = {10, 7, 8, 9, 1, 5}, n = sizeof(arr) / sizeof(arr[0]), c;
    char ch;
    system("cls");
start:
    printf("Given Array is : ");
    printArray(arr, n);
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("3. exit\n");
    printf("===========================\n");
    printf("Enter your choice\t");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
        quickSort(arr, 0, n - 1, c);
        printArray(arr, n);
        break;
    case 2:
        quickSort(arr, 0, n - 1, c);
        printArray(arr, n);
        break;
    case 3:
        exit(1);
        break;
    default:
        printf("\nWrong choice");
        break;
    }

    printf("\nDo you wish to continue? (y/n) ");
    fflush(stdin);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
        goto start;
}
